/*
  ==============================================================================

    OutputController.cpp
    Created: 20 Jun 2015 11:42:09pm
    Author:  Joshua

  ==============================================================================
*/

#include "OutputController.h"

// See http://stackoverflow.com/questions/1149620/how-to-write-to-the-output-window-in-visual-studio for details
// and http://blog.wavosaur.com/debugging-vst-2-4-part-1-visual-studio/ for how to set up Cantabile debugging.
// you'll need to make the working directory ".\Debug".
#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>

// Use this for logging on Windows - different characterset or something.
#define LOG_W( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

// Use this for logging on Linux.
#define LOG( s )            \
{                             \
   std::ostringstream os_;    \
   os_ << s;                   \
   OutputDebugString( os_.str().c_str() );  \
}

using namespace std;

OutputController::OutputController(){
	midiOutput->startBackgroundThread();
}
OutputController::~OutputController(){
	delete(midiOutput);
}


void OutputController::ClockProcess(MidiBuffer& midiMessages) {
	//Lots of help from http://www.juce.com/forum/topic/midi-accuracy, particularly comment #12

	//Notes were being sent far too fast
	if (Time::getMillisecondCounter() % 500 <= 10) {
		PlayNote(m_frequency, midiMessages, 2);

		string test = "This is a test\n";
		LOG_W(test);

		test = "This is also a test\n";
		LOG(test);
	}
}

//This method will schedule a note to be played
void OutputController::PlayNote(float hertz, MidiBuffer& midiMessages, int delay)
{
	//https://en.wikipedia.org/wiki/MIDI_Tuning_Standard
	int midiNoteValue = 69 + (12 * log2f(hertz / 440.0f)); //midi note from provided frequency
	if (midiNoteValue > 128) {
		midiNoteValue = 128;
	}

	MidiMessage midiMessage = MidiMessage::noteOn(1, midiNoteValue, m_volume);
	//MidiMessage midiMessageOff = MidiMessage::noteOn(1, midiNoteValue, 0.0f);
	midiMessage.setTimeStamp(Time::getMillisecondCounter());
	//midiMessageOff.setTimeStamp(Time::getMillisecondCounter());

	double aBpmRatio = (double)60 / 120; //the divisor here is the bpm
	
	midiMessages.addEvent(midiMessage, unit * aBpmRatio);

	double time = Time::getMillisecondCounter() + delay; // The time at which the note is to be played. Time::getMillisecondCounter() = current time.
	midiOutput->sendBlockOfMessages(midiMessages, time, unit);
	midiMessages.clear();
}