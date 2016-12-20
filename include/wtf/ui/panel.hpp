/** @file
@copyright David Mott (c) 2016. Distributed under the Boost Software License Version 1.0. See LICENSE.md or http://boost.org/LICENSE_1_0.txt for details.
*/
#pragma once

namespace wtf{

  namespace policy{
    template <typename _SuperT>
    struct isa_panel : _SuperT{

    protected:

      explicit isa_panel(window * pParent) : _SuperT(pParent){}

    };
  }

  namespace _{

    template <> struct policy_traits<policy::isa_panel>{
      using requires = policy_list<policy::has_enable, policy::has_border, policy::has_click, policy::has_show, policy::has_text,
        policy::has_size, policy::has_move, policy::has_invalidate, policy::has_background, policy::has_zorder, 
        policy::wm_enable, policy::wm_size, policy::wm_paint, policy::wm_create>;
    };

  }

  struct panel : window_impl<panel, policy::isa_panel>{
    explicit panel(window * pParent) : window_impl(pParent){}
  };

}
