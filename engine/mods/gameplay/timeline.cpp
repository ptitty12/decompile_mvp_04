#include "mods/gameplay/timeline.h"

#include <chrono>
#include <cstdio>

#include "common/sha1.h"
#include "runtime/hle.h"

namespace mvp::mods {

namespace {

double ms_since(std::chrono::steady_clock::time_point t0) {
  return std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count();
}

}  // namespace

Timeline::Timeline(rt::Machine& m, rt::YieldingHooks& hooks, rt::Hardware& hw, rt::InputQueue& input,
                   GameplayHost& mods, Tool& tool)
    : m_(m), hooks_(hooks), hw_(hw), input_(input), mods_(mods), tool_(tool) {}

bool Timeline::gate(ppc::Cpu& c) {
  const u64 poll = rt::g_frame_polls;  // the poll about to happen
  const bool stop = mods_.phase() == Phase::Live ? (mods_.snapshot_requested() || mods_.review_requested())
                                                 : poll >= target_;
  if (!stop || !hooks_.stop_before(c)) return true;
  due_ = true;
  return false;
}

void Timeline::after_poll(u64 frame) {
  ring_[frame % kRing] = input_.current();
  if (frame + 1 > recorded_to_) recorded_to_ = frame + 1;
}

void Timeline::push_inputs(u64 from, u64 to) {
  for (u64 f = from; f < to; ++f) {
    u64 at = f;
    if (at >= recorded_to_) at = recorded_to_ ? recorded_to_ - 1 : 0;  // past what was played: hold the last input
    if (recorded_to_ > kRing && at < recorded_to_ - kRing)
      throw rt::StopRun{"timeline: the review reaches back further than the recorded inputs"};
    input_.push(ring_[at % kRing]);
  }
}

void Timeline::save(int slot) {
  const auto t0 = std::chrono::steady_clock::now();
  rt::save_state(slot_[slot], m_, hooks_, hw_, &input_);
  slot_mods_[slot] = mods_.save_state();
  tool_.save_views(slot);
  ++snapshots;
  const double ms = ms_since(t0);
  if (ms > snapshot_ms_max) snapshot_ms_max = ms;
}

void Timeline::load(int slot) {
  const auto t0 = std::chrono::steady_clock::now();
  rt::load_state(slot_[slot], m_, hooks_, hw_, &input_);
  if (!mods_.load_state(slot_mods_[slot])) throw rt::StopRun{"timeline: the mods' state does not fit the snapshot"};
  tool_.load_views(slot);
  ++restores;
  const double ms = ms_since(t0);
  if (ms > restore_ms_max) restore_ms_max = ms;
}

std::string Timeline::mem1_sha1() {
  Sha1 h;
  h.update(m_.mem1(), rt::Machine::kMem1Size);
  return Sha1::hex(h.finish());
}

void Timeline::log(const std::string& s) {
  if (log_) log_(s);
  else std::printf("timeline: %s\n", s.c_str());
}

void Timeline::step() {
  if (!due_) return;
  due_ = false;
  const u64 poll = rt::g_frame_polls;
  switch (mods_.phase()) {
    case Phase::Live: {
      if (const Review* req = mods_.review_requested()) {
        const Review r = *req;
        if (recorded_to_ > kRing && slot_[0].frame_polls < recorded_to_ - kRing) {
          // The pitch began longer ago than the recorded inputs reach: no review.
          mods_.drop_review();
          log("review dropped: the snapshot is older than the recorded inputs");
          break;
        }
        resume_ = poll;
        live_sha1_ = mem1_sha1();
        mods_.begin_review();
        ++reviews;
        load(0);
        const u64 p = rt::g_frame_polls;
        char b[200];
        std::snprintf(b, sizeof b, "review: back to poll %llu, replay %llu-%llu, continue at %llu",
                      static_cast<unsigned long long>(p), static_cast<unsigned long long>(r.present_from),
                      static_cast<unsigned long long>(r.present_to), static_cast<unsigned long long>(resume_));
        log(b);
        if (r.present_from > p) {
          push_inputs(p, r.present_from);
          mods_.set_phase(Phase::Seeking);
          tool_.present(false, Phase::Seeking);
          target_ = r.present_from;
        } else {
          save(1);
          push_inputs(p, r.present_to);
          mods_.set_phase(Phase::Presenting);
          tool_.present(true, Phase::Presenting);
          target_ = r.present_to;
        }
      } else if (mods_.snapshot_requested()) {
        save(0);
        mods_.snapshot_taken(poll);
      }
      break;
    }
    case Phase::Seeking: {
      const Review& r = *mods_.review();
      save(1);
      push_inputs(r.present_from, r.present_to);
      mods_.set_phase(Phase::Presenting);
      tool_.present(true, Phase::Presenting);
      target_ = r.present_to;
      break;
    }
    case Phase::Presenting: {
      const Review& r = *mods_.review();
      load(1);
      push_inputs(r.present_from, resume_);
      mods_.set_phase(Phase::Rerunning);
      tool_.present(false, Phase::Rerunning);
      target_ = resume_;
      break;
    }
    case Phase::Rerunning: {
      const std::string rerun = mem1_sha1();
      log("review: re-ran to poll " + std::to_string(poll) + ": MEM1 sha1 " + rerun +
          (rerun == live_sha1_ ? " (same as live)" : " (live was " + live_sha1_ + ")"));
      target_ = ~0ull;
      tool_.present(true, Phase::Live);
      mods_.end_review(m_.cpu());
      break;
    }
  }
}

}  // namespace mvp::mods
