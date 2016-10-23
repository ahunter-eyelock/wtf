
#pragma once

namespace wtf{
  namespace policy{

    template <typename _SuperT, typename _ImplT> 
    struct has_button_border : _SuperT{

    protected:


      has_button_border(window<void,void> * pParent) : _SuperT(pParent){}

      virtual LRESULT on_wm_create(bool& bhandled) override{ 
        border_style(border_styles::raised); 
        return _SuperT::on_wm_create(bhandled);
      };

      virtual LRESULT on_wm_mouse_move(const messages::mouse_msg_param& m, bool& bhandled) override{
        if (!_Down || messages::mouse_msg_param::buttons::left != m.button) return _SuperT::on_wm_mouse_move(m, bhandled);
        if (!rect<coord_frame::client>::get(*this).is_in(m.position)){
          ::ReleaseCapture();
          _Down = false;
          border_style(border_styles::raised);
          invalidate();
        }
        return _SuperT::on_wm_mouse_move(m, bhandled);
      };

      virtual LRESULT on_wm_mouse_down(const messages::mouse_msg_param& m, bool& bhandled) override{
        if (messages::mouse_msg_param::buttons::left != m.button) return _SuperT::on_wm_mouse_down(m, bhandled);
        _Down = true;
        border_style(border_styles::lowered);
        ::SetCapture(*this);
        invalidate();
        return _SuperT::on_wm_mouse_down(m, bhandled);
      };

      virtual LRESULT on_wm_mouse_up(const messages::mouse_msg_param& m, bool& bhandled) override{
        if (!_Down || messages::mouse_msg_param::buttons::left != m.button) return _SuperT::on_wm_mouse_up(m, bhandled);
        _Down = false;
        border_style(border_styles::raised);
        invalidate();
        ::ReleaseCapture();
        return _SuperT::on_wm_mouse_up(m, bhandled);
      };

      virtual LRESULT on_wm_mouse_leave(bool& bhandled) override{ 
        return _SuperT::on_wm_mouse_leave(bhandled);
      }

    private:
      bool _Down = false;
    };
  }
}