#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	countdown.setup(5*24*60*60*1000,false); // 5 days
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	string c="Time Left";
	c+=" "+ofToString(countdown.getTimeLeftInDays());
	c+=":"+ofToString(countdown.getTimeLeftInHours());
	c+=":"+ofToString(countdown.getTimeLeftInMinutes());
	c+=":"+ofToString(countdown.getTimeLeftInSeconds2());
	ofDrawBitmapString(c, ofGetWidth()/2,ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
