﻿/** @file
@copyright David Mott (c) 2016. Distributed under the Boost Software License Version 1.0. See LICENSE.md or http://boost.org/LICENSE_1_0.txt for details.
*/
#pragma once

namespace wtf{

  namespace messages {
    template <typename _super_t>
    struct wm_destroy : _super_t{

      callback<void(window * sender)> OnDestroy;


    protected:
      template <typename, template <typename> typename...> friend struct window_impl;

      virtual void on_wm_destroy(){ OnDestroy(this); }

      void handle_msg(wtf::window_message& msg) override {
        if (WM_DESTROY == msg.umsg) on_wm_destroy();
      }

    };

  }
}