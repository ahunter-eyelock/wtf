/** @file
@copyright David Mott (c) 2016. Distributed under the Boost Software License Version 1.0. See LICENSE.md or http://boost.org/LICENSE_1_0.txt for details.
*/
#pragma once

namespace wtf{

  namespace policy{
    template <typename _SuperT>
    struct wm_keyup : _SuperT{

      callback<void(window * sender, UINT char_code, keyboard_msg_param param)> OnKeyUp;

    protected:

      virtual void on_wm_keyup(UINT char_code, keyboard_msg_param param){
        OnKeyUp(this, char_code, param);
      }

      explicit wm_keyup(window * pParent) : _SuperT(pParent){}

      void handle_msg(_::window_message& msg) override{
        if (WM_KEYUP == msg.umsg) on_wm_keyup(static_cast<UINT>(msg.wparam), *reinterpret_cast<keyboard_msg_param*>(&msg.lparam));
        _SuperT::handle_msg(msg);
      }

    };
  }
}