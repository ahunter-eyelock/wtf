#pragma once

namespace wtf {
  namespace policy {
    /** has_timer
    * Adds timer creation and produces timer events
    */
    template<typename _SuperT>
    struct has_timer : _SuperT {
      has_timer() : _next_timer_id(1) {}
      has_timer(const has_timer&) = delete;
      has_timer(has_timer&&) = delete;
      has_timer &operator=(const has_timer &) = delete;
      has_timer &operator=(has_timer&&) = delete;

      callback<void(UINT_PTR)> TimerEvent;

      UINT_PTR set_timer(UINT elapse) {
        _next_timer_id++;
        return wtf::exception::throw_lasterr_if(::SetTimer(*this, _next_timer_id, elapse, nullptr),
                                                [](UINT_PTR x) { return !x; });
      }

      void kill_timer(UINT_PTR timer_id) {
        wtf::exception::throw_lasterr_if(::KillTimer(*this, timer_id), [](BOOL x) { return !x; });
      }

    protected:
      UINT_PTR _next_timer_id;

      virtual LRESULT handle_message(HWND , UINT umsg, WPARAM wparam, LPARAM , bool &) override {
        if (WM_TIMER == umsg) TimerEvent(static_cast<UINT_PTR>(wparam));
        return 0;
      }
    };

  }
}
