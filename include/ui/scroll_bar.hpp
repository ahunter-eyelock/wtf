#pragma once
namespace wtf{


    struct scroll_bar : window<scroll_bar, policy::has_border, policy::has_size, policy::has_paint, policy::has_mouse, policy::has_timer>
    {
      

      virtual ~scroll_bar() = default;
      scroll_bar(const scroll_bar&) = delete;
      scroll_bar &operator=(const scroll_bar &) = delete;
      scroll_bar(scroll_bar&&) = delete;
      scroll_bar &operator=(scroll_bar&&) = delete;

      explicit scroll_bar(HWND pParent)
        : window(pParent, true),
        _orientation(orientations::horizontal),
        _background_brush(brush::system_brush(system_colors::inactive_border)),
        _Outline(pen::create(pen::style::solid, 1, system_colors::button_text)),
        _Fill(brush::system_brush(system_colors::button_text)),
        _Inc(*this, true),
        _Dec(*this, false)
      {}

      enum class orientations{
        horizontal,
        vertical
      };

      orientations orientation() const{ return _orientation; }
      void orientation(orientations newval){ _orientation = newval; }

    protected:

      friend struct value_step_button;

      virtual void IncrementEvent(){}
      virtual void DecrementEvent(){}


      struct value_step_button : push_button{
        bool _IsIncrementer;
        scroll_bar& _Parent;

        value_step_button(scroll_bar& Parent, bool IsIncrementer) :
          push_button(Parent), _Parent(Parent), _IsIncrementer(IsIncrementer)
        {}

        virtual void ClickEvent(const point&) override {
          if (_IsIncrementer) _Parent.IncrementEvent();
          else _Parent.DecrementEvent();
        }

        virtual void MouseMoveEvent(event_vkeys k, const point& p){
          auto client = rect::get_client_rect(*this);
          if (!client.is_in(p) && this == _Parent._ButtonHeldDown && _Parent._ButtonDownTimer){
            MouseLButtonUpEvent(k, p);
          }
        }
        virtual void MouseLButtonDownEvent(event_vkeys, const point&){
          ::SetCapture(*this);
          _Parent._ButtonHeldDown = this;
          _Parent._ButtonDownTimer = _Parent.set_timer(500);
        }
        virtual void MouseLButtonUpEvent(event_vkeys, const point&){
          if (this == _Parent._ButtonHeldDown && _Parent._ButtonDownTimer){
            _Parent.kill_timer(_Parent._ButtonDownTimer);
            _Parent._ButtonHeldDown = nullptr;
            _Parent._ButtonDownTimer = 0;
          }
        }


        virtual void PaintEvent(const device_context& dc, const paint_struct&) override {
          auto client = rect::get_client_rect(*this);
          point::vector arrow(3);
          if (_IsIncrementer && orientations::horizontal == _Parent._orientation){
            arrow[0].x = 5; arrow[0].y = 5;
            arrow[1].x = client.right - 5; arrow[1].y = client.bottom / 2;
            arrow[2].x = 5; arrow[2].y = client.bottom - 5;
          } else if (_IsIncrementer){
            arrow[0].x = 5; arrow[0].y = 5;
            arrow[1].x = client.right - 5; arrow[1].y = 5;
            arrow[2].x = client.right / 2; arrow[2].y = client.bottom - 5;
          }else if (!_IsIncrementer && orientations::horizontal == _Parent._orientation){
            arrow[0].x = 5; arrow[0].y = client.bottom / 2;
            arrow[1].x = client.right - 5; arrow[1].y = 5;
            arrow[2].x = client.right - 5; arrow[2].y = client.bottom - 5;
          } else{
            arrow[0].x = client.right / 2; arrow[0].y = 5;
            arrow[1].x = client.right - 5; arrow[1].y = client.bottom - 5;
            arrow[2].x = 5; arrow[2].y = client.bottom - 5;
          }
          dc.fill(arrow, _Parent._Outline, _Parent._Fill);
        }
      };

      virtual void MouseWheelEvent(event_vkeys, int16_t delta, const point&p) override{
        delta /= 120;
        if (delta > 0){
          for (;delta>0;--delta) _Dec.ClickEvent(p);
        }else {
          for (;delta<0;++delta) _Inc.ClickEvent(p);
        }
      }

      virtual void ResizedEvent(wm_size_flags, uint16_t width, uint16_t height) override {
        if (orientations::horizontal == _orientation){
          _Dec.move(0, 0, height, height);
          _Inc.move(width - height, 0, height, height);
        } else{
          _Dec.move(0, 0, width, width);
          _Inc.move(0, height - width, width, width);
        }
      }
      
      virtual void TimerEvent(UINT_PTR iTimer) override{
        if (iTimer != _ButtonDownTimer) return;
        kill_timer(_ButtonDownTimer);
        if (!_ButtonHeldDown) return;
        _ButtonDownTimer = set_timer(50);
        _ButtonHeldDown->ClickEvent(point(0, 0));
      }


      virtual const brush& background_brush() const override{ return _background_brush; }

      orientations _orientation;
      brush _background_brush;
      pen _Outline;
      brush _Fill;
      value_step_button _Inc;
      value_step_button _Dec;
      UINT_PTR _ButtonDownTimer = 0;
      value_step_button * _ButtonHeldDown = nullptr;
    };

}
