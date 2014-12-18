// http://forum.openframeworks.cc/t/passing-function-as-parameter/17925

#pragma once

#include "ofMain.h"

class doSomething {
public:
    doSomething();

    template<class c_l_a_s_s>
    void doThis(void (c_l_a_s_s::*otherFunction)(int), int a=0) {
                void (c_l_a_s_s::*renderer)(int) ;
                c_l_a_s_s * t;
                renderer=  otherFunction;
                (t->*renderer)(a);
    }
    private:
    int width, height;
    ofPoint getMousePos();

};
