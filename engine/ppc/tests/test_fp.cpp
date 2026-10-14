// The integer floating-point core (fp.cpp) against independent references:
// host IEEE double/float arithmetic (round to nearest), std::fma, and a
// round-to-odd reference for fused single-precision results. Plus fixed vectors
// for the conversions and the Gekko-specific pieces.
#include <doctest/doctest.h>

#include <cmath>
#include <cstring>

#include "ppc/fp.h"

using namespace mvp::ppc;
using namespace mvp::ppc::fp;

namespace {

u64 bits(double d) {
  u64 b;
  std::memcpy(&b, &d, 8);
  return b;
}
double dbl(u64 b) {
  double d;
  std::memcpy(&d, &b, 8);
  return d;
}
u32 fbits(float f) {
  u32 b;
  std::memcpy(&b, &f, 4);
  return b;
}
float flt(u32 b) {
  float f;
  std::memcpy(&f, &b, 4);
  return f;
}

// Deterministic generator (xorshift64*).
struct Rng {
  u64 s;
  explicit Rng(u64 seed) : s(seed) {}
  u64 next() {
    s ^= s >> 12;
    s ^= s << 25;
    s ^= s >> 27;
    return s * 0x2545F4914F6CDD1Dull;
  }
  // A finite double with exponent in [emin, emax] (unbiased), random sign and fraction.
  double finite(int emin, int emax) {
    u64 r = next();
    int e = emin + static_cast<int>(r % static_cast<u64>(emax - emin + 1));
    u64 frac = next() & kFracMask;
    // Sometimes few significant bits, to hit exact cases and ties.
    if ((r >> 40) % 4 == 0) frac &= ~((1ull << (r >> 48) % 52) - 1);
    u64 b = (static_cast<u64>(e + 1023) << 52) | frac | ((r >> 63) << 63);
    return dbl(b);
  }
  float single(int emin, int emax) {
    u64 r = next();
    int e = emin + static_cast<int>(r % static_cast<u64>(emax - emin + 1));
    u32 frac = static_cast<u32>(next()) & 0x7FFFFF;
    if ((r >> 40) % 4 == 0) frac &= ~((1u << (r >> 48) % 23) - 1);
    return flt((static_cast<u32>(e + 127) << 23) | frac | static_cast<u32>((r >> 63) << 31));
  }
};

// Reference for a single-precision fused a*c+b with single inputs: the product is
// exact in double; TwoSum gives the exact error of the double sum; making the sum
// round-to-odd from that error, then rounding to float, rounds once.
float ref_fmadds(float a, float c, float b) {
  double p = static_cast<double>(a) * static_cast<double>(c);  // exact (48 bits)
  double s = p + b;
  double bb = s - p;
  double e = (p - (s - bb)) + (b - bb);  // exact error of s
  if (e != 0) {
    u64 sb = bits(s);
    if (!(sb & 1)) {
      // Move one ulp toward the exact value, giving an odd last bit.
      bool toward_larger_magnitude = (e > 0) == (s > 0);
      sb += toward_larger_magnitude ? 1 : static_cast<u64>(-1);
      s = dbl(sb);
    }
  }
  return static_cast<float>(s);
}

}  // namespace

TEST_CASE("double add/sub/mul/div match host IEEE arithmetic") {
  Rng r(0x1234);
  int checked = 0;
  for (int k = 0; k < 200000; ++k) {
    int range = static_cast<int>(r.next() % 3);
    double a = range == 0 ? r.finite(-20, 20) : range == 1 ? r.finite(-1074 + 52, 1023) : r.finite(-1022, -900);
    double b = range == 0 ? r.finite(-20, 20) : range == 1 ? r.finite(-1074 + 52, 1023) : r.finite(-1022, -900);
    if (k % 7 == 0) b = -a * (1.0 + std::ldexp(static_cast<double>(r.next() % 1000), -50));  // cancellation
    struct Case {
      u64 got;
      double want;
    } cases[] = {
        {add(bits(a), bits(b), Prec::Double, 0), a + b},
        {sub(bits(a), bits(b), Prec::Double, 0), a - b},
        {mul(bits(a), bits(b), Prec::Double, 0), a * b},
        {div(bits(a), bits(b), Prec::Double, 0), a / b},
    };
    for (const auto& c : cases) {
      if (std::isnan(c.want)) continue;
      ++checked;
      if (c.got != bits(c.want)) {
        FAIL_CHECK("a=", a, " b=", b, " got ", dbl(c.got), " want ", c.want);
        return;
      }
    }
  }
  CHECK(checked > 700000);
}

TEST_CASE("single add/sub/mul/div of single inputs match host float arithmetic") {
  Rng r(0x777);
  for (int k = 0; k < 200000; ++k) {
    bool tiny = r.next() % 4 == 0;
    float a = tiny ? r.single(-126, -100) : r.single(-30, 30);
    float b = tiny ? r.single(-126, -100) : r.single(-30, 30);
    u64 A = bits(static_cast<double>(a)), B = bits(static_cast<double>(b));
    struct Case {
      u64 got;
      float want;
    } cases[] = {
        {add(A, B, Prec::Single, 0), a + b},
        {sub(A, B, Prec::Single, 0), a - b},
        {mul(A, B, Prec::Single, 0), a * b},
        {div(A, B, Prec::Single, 0), a / b},
    };
    for (const auto& c : cases) {
      if (std::isnan(c.want)) continue;
      if (c.got != bits(static_cast<double>(c.want))) {
        FAIL_CHECK("a=", a, " b=", b, " got ", dbl(c.got), " want ", c.want);
        return;
      }
    }
  }
}

TEST_CASE("double madd matches std::fma") {
  Rng r(0x99);
  for (int k = 0; k < 200000; ++k) {
    double a = r.finite(-60, 60), c = r.finite(-60, 60);
    double b = r.next() % 3 ? r.finite(-120, 120) : -(a * c);  // include near-total cancellation
    double want = std::fma(a, c, b);
    if (std::isnan(want)) continue;
    u64 got = madd(bits(a), bits(c), bits(b), false, false, Prec::Double, 0);
    if (got != bits(want)) {
      FAIL_CHECK("a=", a, " c=", c, " b=", b, " got ", dbl(got), " want ", want);
      return;
    }
    // msub / nmadd / nmsub are sign variants.
    CHECK(madd(bits(a), bits(c), bits(b), true, false, Prec::Double, 0) == bits(std::fma(a, c, -b)));
    u64 nm = madd(bits(a), bits(c), bits(b), false, true, Prec::Double, 0);
    CHECK(nm == (bits(want) ^ kSign));
  }
}

TEST_CASE("single madd of single inputs matches a round-to-odd reference") {
  Rng r(0x4242);
  for (int k = 0; k < 200000; ++k) {
    float a = r.single(-20, 20), c = r.single(-20, 20);
    float b = r.next() % 3 ? r.single(-40, 40) : -(a * c);
    float want = ref_fmadds(a, c, b);
    u64 got = madd(bits(a), bits(c), bits(b), false, false, Prec::Single, 0);
    if (got != bits(static_cast<double>(want))) {
      FAIL_CHECK("a=", a, " c=", c, " b=", b, " got ", dbl(got), " want ", want);
      return;
    }
  }
}

TEST_CASE("round_to_single matches host double-to-float conversion") {
  Rng r(0x5150);
  for (int k = 0; k < 200000; ++k) {
    double d = r.next() % 5 ? r.finite(-160, 140) : r.finite(-1022, 1023);
    float want = static_cast<float>(d);
    CHECK_MESSAGE(round_to_single(bits(d), 0) == bits(static_cast<double>(want)), d);
  }
}

TEST_CASE("single <-> double load/store conversions") {
  Rng r(0xABCD);
  for (int k = 0; k < 100000; ++k) {
    u32 s = static_cast<u32>(r.next());
    u64 d = single_to_double(s);
    // Storing what was loaded gives the same word back (NaN payloads included).
    CHECK(double_to_single(d) == s);
    float f = flt(s);
    if (!std::isnan(f)) CHECK(d == bits(static_cast<double>(f)));
  }
  CHECK(single_to_double(0x00000001) == bits(0x1p-149));
  CHECK(single_to_double(0x80000000) == kSign);
  CHECK(single_to_double(0x7F800000) == 0x7FF0000000000000ull);
  CHECK(single_to_double(0x7FC00001) == 0x7FF8000020000000ull);
  // Stores below the normal single range denormalize (truncating).
  CHECK(double_to_single(bits(0x1p-130)) == 0x00080000);
  CHECK(double_to_single(bits(0x1p-130 * 1.75)) == 0x000E0000);
  CHECK(double_to_single_ftz(bits(0x1p-130)) == 0);
  CHECK(double_to_single_ftz(bits(-0x1p-130)) == 0x80000000);
  CHECK(double_to_single_ftz(bits(1.0)) == 0x3F800000);
}

TEST_CASE("force25 rounds the significand to 25 bits, ties away") {
  CHECK(force25(bits(1.0)) == bits(1.0));
  CHECK(force25(bits(1.0 + 0x1p-25)) == bits(1.0 + 0x1p-24));  // half: rounds up
  CHECK(force25(bits(1.0 + 0x1p-26)) == bits(1.0));            // below half
  CHECK(force25(bits(1.0 + 0x1p-24 + 0x1p-25)) == bits(1.0 + 0x1p-23));
  CHECK(force25(bits(-(1.0 + 0x1p-25))) == bits(-(1.0 + 0x1p-24)));
  // Singles are unchanged.
  Rng r(3);
  for (int k = 0; k < 10000; ++k) {
    double d = static_cast<double>(r.single(-126, 127));
    CHECK(force25(bits(d)) == bits(d));
  }
}

TEST_CASE("zero signs and rounding modes") {
  const u64 pz = 0, nz = kSign, one = bits(1.0), mone = bits(-1.0);
  CHECK(add(pz, nz, Prec::Double, 0) == pz);
  CHECK(add(nz, nz, Prec::Double, 0) == nz);
  CHECK(add(one, mone, Prec::Double, 0) == pz);
  CHECK(add(one, mone, Prec::Double, 3) == nz);  // round toward -inf
  CHECK(mul(mone, pz, Prec::Double, 0) == nz);
  CHECK(madd(mone, pz, pz, false, false, Prec::Double, 0) == pz);  // -0 + +0
  CHECK(madd(mone, pz, nz, false, false, Prec::Double, 0) == nz);  // -0 + -0
  // Directed rounding of 1 + 2^-60.
  u64 x = bits(1.0), y = bits(0x1p-60);
  CHECK(add(x, y, Prec::Double, 0) == bits(1.0));
  CHECK(add(x, y, Prec::Double, 1) == bits(1.0));
  CHECK(add(x, y, Prec::Double, 2) == bits(1.0 + 0x1p-52));
  CHECK(add(x, y, Prec::Double, 3) == bits(1.0));
  CHECK(sub(x, y, Prec::Double, 3) == bits(1.0 - 0x1p-53));
  // Overflow: inf for nearest, max finite toward zero.
  CHECK(mul(bits(1e300), bits(1e300), Prec::Double, 0) == 0x7FF0000000000000ull);
  CHECK(mul(bits(1e300), bits(1e300), Prec::Double, 1) == 0x7FEFFFFFFFFFFFFFull);
  CHECK(mul(bits(1e30), bits(1e30), Prec::Single, 0) == 0x7FF0000000000000ull);
  CHECK(mul(bits(1e30), bits(1e30), Prec::Single, 1) == bits(static_cast<double>(3.40282347e38f)));
}

TEST_CASE("fctiw and fctiwz conversions") {
  CHECK(to_int32(bits(0.0), true, 0) == 0xFFF8000000000000ull);
  CHECK(to_int32(bits(-0.0), true, 0) == 0xFFF8000100000000ull);
  CHECK(to_int32(bits(2147483647.9), true, 0) == 0xFFF800007FFFFFFFull);
  CHECK(to_int32(bits(-2147483648.9), true, 0) == 0xFFF8000080000000ull);
  CHECK(to_int32(bits(-1.5), false, 0) == 0xFFF80000FFFFFFFEull);  // nearest even: -2
  CHECK(to_int32(bits(-2.5), false, 0) == 0xFFF80000FFFFFFFEull);  // nearest even: -2
  CHECK(to_int32(bits(0.5), false, 0) == 0xFFF8000000000000ull);
  CHECK(to_int32(bits(1.5), false, 2) == 0xFFF8000000000002ull);   // toward +inf
  CHECK(to_int32(bits(-1.5), false, 3) == 0xFFF80000FFFFFFFEull);  // toward -inf
  CHECK(to_int32(bits(1e-300), false, 2) == 0xFFF8000000000001ull);
  CHECK(to_int32(0x7FF0000000000000ull, true, 0) == 0xFFF800007FFFFFFFull);
  Rng r(77);
  for (int k = 0; k < 100000; ++k) {
    double d = r.finite(-10, 30);
    long long t = static_cast<long long>(std::trunc(d));
    if (t > 0x7FFFFFFF || t < -0x80000000LL) continue;
    u64 want = 0xFFF8000000000000ull | static_cast<u32>(static_cast<int>(t));
    if (t == 0 && std::signbit(d)) want |= 0x100000000ull;
    CHECK(to_int32(bits(d), true, 0) == want);
  }
}

TEST_CASE("estimates are deterministic and correctly rounded") {
  CHECK(rsqrt_estimate(bits(4.0), 0) == bits(0.5));
  CHECK(rsqrt_estimate(bits(0.0), 0) == 0x7FF0000000000000ull);
  CHECK(rsqrt_estimate(bits(-0.0), 0) == 0xFFF0000000000000ull);
  CHECK(rsqrt_estimate(bits(-4.0), 0) == kDefaultNaN);
  CHECK(rsqrt_estimate(0x7FF0000000000000ull, 0) == 0);
  Rng r(5);
  for (int k = 0; k < 100000; ++k) {
    double d = std::fabs(r.finite(-1000, 1000));
    CHECK(rsqrt_estimate(bits(d), 0) == bits(1.0 / std::sqrt(d)));
  }
  CHECK(reciprocal_estimate(bits(3.0), 0) == bits(static_cast<double>(1.0f / 3.0f)));
}

TEST_CASE("quantization") {
  // dequantize: integer * 2^-scale; scale is a 6-bit two's complement field.
  CHECK(dequantize(0xFF, 4, 0) == bits(255.0));
  CHECK(dequantize(0xFF, 6, 0) == bits(-1.0));
  CHECK(dequantize(0x8000, 7, 1) == bits(-16384.0));
  CHECK(dequantize(0x8000, 5, 0x3F) == bits(65536.0));  // scale -1: times 2
  CHECK(dequantize(0x3F800000, 0, 5) == bits(1.0));     // float type ignores the scale
  // quantize: round to single, scale, truncate toward zero, saturate.
  CHECK(quantize(bits(1.99999999999), 7, 0) == 2);  // rounds to the single 2.0 first
  CHECK(quantize(bits(1.999), 7, 0) == 1);
  CHECK(quantize(bits(-1.999), 7, 0) == 0xFFFF);  // -1
  CHECK(quantize(bits(40000.0), 7, 0) == 0x7FFF);
  CHECK(quantize(bits(-40000.0), 7, 0) == 0x8000);
  CHECK(quantize(bits(70000.0), 5, 0) == 0xFFFF);
  CHECK(quantize(bits(-1.0), 5, 0) == 0);
  CHECK(quantize(bits(0.75), 4, 2) == 3);  // 0.75 * 4
  CHECK(quantize(kDefaultNaN, 6, 0) == 0x7F);
  CHECK(quantize(0x7FF0000000000000ull, 4, 0) == 0xFF);
  CHECK(quantize(0xFFF0000000000000ull, 6, 0) == 0x80);
  CHECK(quantize(bits(1e38), 7, 10) == 0x7FFF);  // scaled past the single range
  CHECK(quantize(bits(1.0), 0, 0) == 0x3F800000);
}

TEST_CASE("NI flushing") {
  const u32 ni = 4;
  // Single result below 2^-126 (exact value) flushes, sign kept.
  CHECK(mul(bits(-0x1p-70), bits(0x1p-60), Prec::Single, ni) == kSign);
  CHECK(mul(bits(-0x1p-70), bits(0x1p-60), Prec::Single, 0) == bits(-0x1p-130));
  // A value just below 2^-126 that would round up to it still flushes.
  CHECK(round_to_single(bits(0x1p-126 * (1 - 0x1p-30)), ni) == 0);
  CHECK(round_to_single(bits(0x1p-126 * (1 - 0x1p-30)), 0) == bits(0x1p-126));
  // Double: flushes only results that round to a denormal double.
  CHECK(mul(bits(0x1p-600), bits(0x1p-450), Prec::Double, ni) == 0);
  CHECK(mul(bits(0x1p-600), bits(0x1p-422), Prec::Double, ni) == bits(0x1p-1022));
  // Inputs are not flushed.
  CHECK(add(bits(0x1p-1060), bits(1.0), Prec::Double, ni) == bits(1.0));
  CHECK(add(bits(0x1p-1060), bits(0x1p-1060), Prec::Double, 0) == bits(0x1p-1059));
}
