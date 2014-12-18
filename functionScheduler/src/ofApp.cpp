#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	timer.setup(10000,true); // start the timer for 10 seconds
	timer.setCount(1,3);
	// timer.stopTimer(); // dont start timer at the beginning
	currentSecond=-1; // 
}

//--------------------------------------------------------------
void ofApp::update(){
	// cout << ofToString(ofGetElapsedTimef())+"\n";
}

//--------------------------------------------------------------
void ofApp::draw(){
	// ofDrawBitmapString(ofToString(timer.getTimeLeftInSeconds()), 20,20);

	ofFill();
	ofColor(0);
	ofDrawBitmapString("Curr. second: "+ ofToString(timer.getElapsedTimeInSeconds()), 20,40);
	ofDrawBitmapString("Loop count: "+ ofToString(timer.count), 20,60);

	// Scheduler
	if(currentSecond!=timer.getElapsedTimeInSeconds())
		scheduler(); // trigger on specified seconds. One time ONLY;

	ofLine(ofPoint(mouseX, 0), ofPoint(mouseX, ofGetHeight()));
	ofDrawBitmapString(ofToString(timer.getElapsedTimeInSeconds()), mouseX+10,ofGetHeight()/2);
}

void ofApp::scheduler()
{
	// particular seconds trigger particular functions

	switch (timer.getElapsedTimeInSeconds())
	{
	case 0:
		cout <<            "\n===============================\n";
		ofLog(OF_LOG_NOTICE,"[%is] Uzkraunam paveiksla No. %i ",timer.getElapsedTimeInSeconds(), timer.count);
		break;

	case 1:
		ofLog(OF_LOG_NOTICE,"[%is] Fade IN... ",timer.getElapsedTimeInSeconds());
		break;

	case 2:
		ofLog(OF_LOG_NOTICE,"[%is] Pirmas efektas ",timer.getElapsedTimeInSeconds());
		break;

	case 3:
		ofLog(OF_LOG_NOTICE,"[%is] Antras efektas ",timer.getElapsedTimeInSeconds());
		break;

	case 4:
		ofLog(OF_LOG_NOTICE,"[%is] Trecias efektas ",timer.getElapsedTimeInSeconds());
		break;

	case 5:
		ofLog(OF_LOG_NOTICE,"[%is] Ketvirtas efektas ",timer.getElapsedTimeInSeconds());
		break;

	case 6:
		ofLog(OF_LOG_NOTICE,"[%is] Penktas efektas ",timer.getElapsedTimeInSeconds());
		break;

	case 7:
		ofLog(OF_LOG_NOTICE,"[%is] Fade OUT... ",timer.getElapsedTimeInSeconds());
		break;

	}

	currentSecond=timer.getElapsedTimeInSeconds();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key=='r')
	{
		timer.stopTimer();
		timer.reset();
	}

	if (key=='p')
	{
		timer.startTimer();
	}

	switch (key)
	{
	case 1:
		timer.setTimeInSeconds(0);
		timer.count=1;

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	timer.setTimeInSeconds((int)ofMap(mouseX, 0, ofGetWidth(), 0, timer.getDelay()/1000.f));
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	// timer.startTimer();

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
