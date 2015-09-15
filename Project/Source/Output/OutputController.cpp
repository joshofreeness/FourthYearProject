/*
  ==============================================================================

    OutputController.cpp
    Created: 20 Jun 2015 11:42:09pm
    Author:  Joshua

  ==============================================================================
*/

#include "OutputController.h"

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
	//if (Time::getMillisecondCounter() % 500 <= 10) {
	//	PlayNote(m_frequency, midiMessages, 2);
	//}
}

//This method will schedule a note to be played
void OutputController::PlayNote(float hertz, MidiBuffer& midiMessages, int delay)
{


	//https://en.wikipedia.org/wiki/MIDI_Tuning_Standard
	int midiNoteValue = 69 + (12 * log2f(hertz / 440.0f)); //midi note from provided frequency
	if (midiNoteValue >= 127) {
		midiNoteValue = 127;
	}
	else if (midiNoteValue < 1) {
		midiNoteValue = 1;
	}

	MidiMessage midiMessage = MidiMessage::noteOn(1, midiNoteValue, 1.0f);
	//MidiMessage midiMessageOff = MidiMessage::noteOn(1, midiNoteValue, 0.0f);
	midiMessage.setTimeStamp(Time::getMillisecondCounter());
	//midiMessageOff.setTimeStamp(Time::getMillisecondCounter());

	double aBpmRatio = (double)60 / 120; //the divisor here is the bpm
	
	midiMessages.addEvent(midiMessage, unit * aBpmRatio);

	double time = Time::getMillisecondCounter() + delay; // The time at which the note is to be played. Time::getMillisecondCounter() = current time.
	midiOutput->sendBlockOfMessages(midiMessages, time, unit);
	midiMessages.clear();

#ifdef WIN32
	LOG("Played note " + std::to_string(midiNoteValue) + " Played freq: " + std::to_string(hertz));
#endif
}