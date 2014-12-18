/***********************************************************************

Copyright (c) 2009, Todd Vanderlin, www.vanderlin.cc

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

***********************************************************************/

#include "ofxTimer.h"

ofxTimer::ofxTimer() {
}

ofxTimer::~ofxTimer() {
	ofRemoveListener(ofEvents().update, this, &ofxTimer::update);
	printf("*** Timer Destroyed ***\n");
}

// ---------------------------------------

void ofxTimer::setup(float millSeconds, bool loopTimer) {

	count = 0;
	maxCount = 0;
	startCount = 0;
	bLoop = loopTimer;
	bPauseTimer = false;

	//timer
	bStartTimer = true;
	bTimerFinished = false;
	delay = millSeconds;	// mill seconds
	// timer = 0;
	timerStart = 0;

	paused = false;
	resumed = false;

	//events
	ofAddListener(ofEvents().update, this, &ofxTimer::update);

}

// ---------------------------------------
void ofxTimer::pauseTimer() {
	paused = true;
	pauseStartTime = ofGetElapsedTimef();
	//pauseStartTime = ;
	//timerStart=ofGetElapsedTimef()-ofClamp(pauseTime, 0,delay/1000.f);
}

// ---------------------------------------
void ofxTimer::resumeTimer() {
	resumed = true;
	paused = false;
	//pauseTime = ofGetElapsedTimef() - pauseStartTime;
	//setTimeInSeconds(pauseTime)
	timerStart=ofGetElapsedTimef()-pauseStartTime;
	pauseTime=timerStart+getElapsedTimeInSeconds();
}

// ---------------------------------------
void ofxTimer::reset() {
	count = startCount;
	// timer = 0;
	timerStart = 0;
	bStartTimer = true;
	bTimerFinished = false;
	resumed = false;
	paused = false;
}

// ---------------------------------------
void ofxTimer::loop(bool b) {
	bLoop = b;
}

// ---------------------------------------
void ofxTimer::update(ofEventArgs &e) {

	if (paused)
		return;

	if (!bPauseTimer) {
		if (bStartTimer) {
			bStartTimer = false;
			timerStart = ofGetElapsedTimef();
		}

		float time = ofGetElapsedTimef() - timerStart;

		if (resumed) {
			time -= pauseTime;
		}

		time *= 1000.0;
		if (time >= delay) {

			if (count<maxCount)
				count++; else count=startCount;

			if (!bLoop) {
				bPauseTimer = true;
				bTimerFinished = true;	//TODO noch kein unterschied zu bPaused;
			}
			paused = false;
			resumed = false;

			bStartTimer = true;
			static ofEventArgs timerEventArgs;
			ofNotifyEvent(TIMER_REACHED, timerEventArgs, this);
		}
	}
}


float ofxTimer::getTimeLeftInDays() {
	return (int)(getTimeLeftInMillis() / (1000*60*60*24)) % 365;
}

float ofxTimer::getTimeLeftInHours() {
	return (int)(getTimeLeftInMillis() / (1000*60*60)) % 24;
}

float ofxTimer::getTimeLeftInMinutes() {
	return (int)(getTimeLeftInMillis() / (1000*60)) % 60;
}

float ofxTimer::getTimeLeftInSeconds2()
{
	return (int)(getTimeLeftInMillis() / 1000) % 60;
}

float ofxTimer::getTimeLeftInSeconds() {

	if (bTimerFinished)
		return 0;

	if (bStartTimer) {
		return delay / 1000.f;
	}

	float time = ofGetElapsedTimef() - timerStart;


	if (resumed) {
		time = (ofGetElapsedTimef() - timerStart - pauseTime);
	}

	if (paused) {
		time = (ofGetElapsedTimef() - timerStart - ofGetElapsedTimef()
			+ pauseStartTime);
	}

	return (delay / 1000.0) - time;
}

float ofxTimer::getTimeLeftInMillis() {

	if (bTimerFinished)
		return 0;

	if (bStartTimer) {
		return delay;
	}

	float time = ofGetElapsedTimef() - timerStart;

	if (resumed) {
		time = (ofGetElapsedTimef() - timerStart - pauseTime);
	}

	if (paused) {
		time = pauseStartTime;
	}

	return delay - (time * 1000.0);
}

// ---------------------------------------
int ofxTimer::getElapsedTimeInSeconds() 
{
	if (bTimerFinished)
		return 0;

	if (bStartTimer) {
		return delay / 1000.f;
	}

	float time = ofGetElapsedTimef() - timerStart;

	if (resumed) {
		// time = (ofGetElapsedTimef() - timerStart) + pauseTime;
		// time = pauseTime - timerStart;
		time = ofGetElapsedTimef() - timerStart - pauseStartTime;
	}

	if (paused) 
	{
		time=timerStart + pauseStartTime;
	}

	if (bPauseTimer)
	{
		time=timerStart + pauseStartTime;
	}

	return (int)time;
}

float ofxTimer::getDelay()
{
	return delay;
}

void ofxTimer::setTimeInSeconds (int seconds)
{
	// sets the new timer position in seconds (not accurate, but does scheduling well
	if (!paused || !resumed || !bStartTimer || bTimerFinished)
		timerStart=ofGetElapsedTimef()-ofClamp(seconds, 0,delay/1000.f);
	if (paused)
	{
		// timerStart=ofGetElapsedTimef()-ofClamp(seconds, 0,delay/1000.f);
		pauseStartTime=timerStart+ofClamp(seconds, 0,delay/1000.f);
	}
}

// ---------------------------------------
void ofxTimer::setTimer(float millSeconds) {
	delay = millSeconds;
}

void ofxTimer::setCount(int start, int end)
{
	startCount = start;
	maxCount = end;
	count = startCount;
}

void ofxTimer::startTimer() {
	bPauseTimer = false;
}

void ofxTimer::stopTimer() {
	bPauseTimer = true;
}

bool ofxTimer::isTimerFinished() {
	return bTimerFinished;
}

bool ofxTimer::isTimerPaused() {
	return bPauseTimer;
}

