//  ofApp.cpp
//  Created by Bartosh Polonski on 04/07/15.
// 

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofXml settings;
	settings.load("time.xml");
	int hours=settings.getIntValue("hours");
	int minutes=settings.getIntValue("minutes");
	countdown.setup(hours*60*60*1000 + minutes*60*1000,false); // 4 hours

	// countdown.setup(5*24*60*60*1000,false); // 5 days
	// countdown.setup(1*60*1000,false); // 1 minute
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(0);
	string c="Time Left ";
	// display raw
	/*
	c+=" "+ofToString(countdown.getTimeLeftInDays());
	c+=ofToString(countdown.getTimeLeftInHours());
	c+=":"+ofToString(countdown.getTimeLeftInMinutes());
	c+=":"+ofToString(countdown.getTimeLeftInSeconds2());
	*/
	ofDrawBitmapString(c, ofGetWidth()/2,ofGetHeight()/2);

	// Display as digital clock (with zeros)
	ofSetColor(255);

	string displayDigits;
	// hours digit1
	displayDigits+=ofToString((int) countdown.getTimeLeftInHours() / 10 % 10);
	// hours digit2
	displayDigits+=ofToString((int) countdown.getTimeLeftInHours() % 10);
	// colon devider 
	displayDigits+=":";
	// minutes digit1
	displayDigits+=ofToString((int) countdown.getTimeLeftInMinutes() / 10 % 10);
	// minutes digit2
	displayDigits+=ofToString((int) countdown.getTimeLeftInMinutes() % 10);
	// colon devider 
	displayDigits+=":";
	// minutes digit1
	displayDigits+=ofToString((int) countdown.getTimeLeftInSeconds2() / 10 % 10);
	// minutes digit2
	displayDigits+=ofToString((int) countdown.getTimeLeftInSeconds2() % 10);

	ofDrawBitmapString(displayDigits, ofGetWidth()/2,ofGetHeight()/2+20);
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
