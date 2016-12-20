#define __WTF_DEBUG_MESSAGES__ 1

#include "wtf/wtf.hpp"

struct SubclassedForm : wtf::form {

  SubclassedForm() : wtf::form(), oButton(this){

    OnCreate += [this](...){
      titlebar("This is a sub-classed form with a button");
      oButton.move(10, 10, 100, 50);
      oButton.text("Click Me");
    };

    oButton.OnClick += [this](...){
      close();
    };

  }

  wtf::button oButton;
};



int main() {
  return SubclassedForm().run();
}