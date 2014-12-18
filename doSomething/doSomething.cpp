// http://forum.openframeworks.cc/t/passing-function-as-parameter/17925

#include "doSomething.h"

doSomething::doSomething(){
    width=100,height=100;
}

ofPoint doSomething::getMousePos(){
    return ofPoint(ofGetMouseX(),ofGetMouseY());
}
