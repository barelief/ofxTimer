// http://forum.openframeworks.cc/t/passing-function-as-parameter/17925

#include "ofMain.h"
#include "doSomething.h"


class ofApp : public ofBaseApp{
public:
    void setup(){}
    void update(){}

    void draw(){
        doSomething secWin;
        secWin.doThis(&ofApp::functionToSend, ofRandom(10));

    }

    void functionToSend(int a){
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofRect(100, 100, a*100, 100);
    }
};


int main( )
{

	ofSetupOpenGL(1024,768,OF_WINDOW);
	ofRunApp(new ofApp());

}
