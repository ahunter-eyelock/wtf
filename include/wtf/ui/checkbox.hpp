#pragma once

namespace wtf{
  namespace policy{
    template <typename _ImplT, typename _SuperT>
    class isa_checkbox : public _SuperT{
      using __checkbox_t = isa_checkbox<_ImplT, _SuperT>;
    public:

      explicit isa_checkbox(iwindow * pParent) : _SuperT(pParent), _check(this){
        auto_draw_text(false);
      }

      enum class check_locations{
        left,
        right,
      };

      text_horizontal_alignments text_horizontal_alignment() const{ return _text_horizontal_alignment; }
      void text_horizontal_alignment(text_horizontal_alignments newval){
        _text_horizontal_alignment = newval;
      }

    private:
      virtual void handle_msg(window_message& msg) override{}

      virtual void on_wm_click(const mouse_msg_param& m) override{
        if (mouse_msg_param::buttons::left == m.button){
          _check.value(!_check.value());
        }
        _SuperT::on_wm_click(m);
      };

      virtual void on_wm_paint(const device_context& dc, const paint_struct& ps) override{
        auto client = ps.client();
        auto TextSize = prefered_text_size();
        if (text_horizontal_alignments::left == _text_horizontal_alignment){
          _check.move(0, (client.bottom - checkbox_size) / 2, checkbox_size, checkbox_size);
          draw_text(dc, rect<coord_frame::client>(checkbox_size, 0, client.right - checkbox_size, client.bottom));
        } else{
          _check.move(client.right - checkbox_size, (client.bottom - checkbox_size) / 2, checkbox_size, checkbox_size);
          draw_text(dc, rect<coord_frame::client>(0, 0, client.right - checkbox_size, client.bottom));
        }
        _SuperT::on_wm_paint(dc, ps);
      };

      static const int checkbox_size = 15;


      struct _check : panel {

        using __super_t = panel;

        _check(__checkbox_t * pParent)
          : __super_t(pParent),
          _parent(pParent){}

        virtual void on_wm_click(const mouse_msg_param& m) override{
          if (mouse_msg_param::buttons::left == m.button) value(!_value);
          __super_t::on_wm_click(m);
        }

        virtual void on_wm_paint(const device_context& dc, const paint_struct& ps) override{
          auto client = ps.client();
          dc.fill(client, brush::solid_brush(rgb(255, 255, 255)));
          if (_value){
            client.top += 2;
            client.left += 2;
            client.bottom -= 3;
            client.right -= 3;
            auto black = pen::create(pen::style::solid, 2, rgb(0, 0, 0));
            dc.line(black, client.left, client.top, client.right, client.bottom);
            dc.line(black, client.right, client.top, client.left, client.bottom);
          }
          __super_t::on_wm_paint(dc, ps);
        }

        bool value() const{ return _value; }
        void value(bool newval){
          _value = newval;
          border_style(newval ? border_styles::lowered : border_styles::raised);
          invalidate();
        }

      private:
        bool _value = false;
        __checkbox_t * _parent;
      }_check;

    private:
      text_horizontal_alignments _text_horizontal_alignment = text_horizontal_alignments::left;
    };
  }

  struct checkbox : window_impl<checkbox, policy::isa_checkbox>{
    explicit checkbox(iwindow * pParent) : window_impl(pParent){}
  };

}
