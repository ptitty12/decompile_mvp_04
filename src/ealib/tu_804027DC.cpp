/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x804027DC-0x80403E80 (code-only unit, 34 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern "C" double sqrt(double x);

struct V3 {
    float x, y, z;
};

/* Vec3 array helpers of the EA math library */
extern "C" void fn_804029B8(int n, const V3* a, const V3* b, V3* out)
{
    int i;
    for (i = 0; i < n; i++) {
        out[i].x = a[i].x + b->x;
        out[i].y = a[i].y + b->y;
        out[i].z = a[i].z + b->z;
    }
}

extern "C" void fn_80402A04(int n, const V3* a, const V3* b, V3* out)
{
    int i;
    for (i = 0; i < n; i++) {
        out[i].x = a[i].x - b->x;
        out[i].y = a[i].y - b->y;
        out[i].z = a[i].z - b->z;
    }
}

extern "C" void fn_80402A50(int n, const V3* a, V3* out, float k)
{
    int i;
    for (i = 0; i < n; i++) {
        out[i].x = a[i].x * k;
        out[i].y = a[i].y * k;
        out[i].z = a[i].z * k;
    }
}

/* near-miss: same length; the register order of the three loads and the two fmadds (z*z + (x*x + y*y)) differs. */
extern "C" float fn_80402A90(const V3* v)
{
    float y = v->y;
    float x = v->x;
    float z = v->z;
    return (float)sqrt(z * z + (x * x + y * y));
}

/* near-miss: same length; retail interleaves the six loads and three products differently (locals in draft order tried). */
extern "C" void fn_80402ACC(const V3* a, const V3* b, V3* out)
{
    float bx = b->x;
    float ax = a->x;
    float ay = a->y;
    float bz = b->z;
    float az = a->z;
    float by = b->y;
    out->y = az * bx - ax * bz;
    out->z = ax * by - ay * bx;
    out->x = ay * bz - az * by;
}

extern "C" void fn_80402B48(const V3* v, V3* out)
{
    float s = 1.0f / fn_80402A90(v);
    out->x = v->x * s;
    out->y = v->y * s;
    out->z = v->z * s;
}

extern "C" void fn_80402BA8(int n, const V3* a, const V3* b, float* out)
{
    int i;
    for (i = 0; i < n; i++)
        out[i] = a[i].x * b->x + a[i].y * b->y + a[i].z * b->z;
}
