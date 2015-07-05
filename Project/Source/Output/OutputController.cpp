/*
  ==============================================================================

    OutputController.cpp
    Created: 20 Jun 2015 11:42:09pm
    Author:  Joshua

  ==============================================================================
*/

#include "OutputController.h"

OutputController::OutputController(){
	midiOutput->startBackgroundThread();
}
OutputController::~OutputController(){}


void OutputController::ClockProcess(MidiBuffer& midiMessages) {
	//Lots of help from http://www.juce.com/forum/topic/midi-accuracy, particularly comment #12

	if (test) {
		PlayNote(1050.0f, 1.0f, 10, midiMessages, 100);
		PlayNote(950.0f, 1.0f, 10, midiMessages, 200);
		PlayNote(850.0f, 1.0f, 10, midiMessages, 300);
		PlayNote(750.0f, 1.0f, 10, midiMessages, 400);
		PlayNote(650.0f, 1.0f, 10, midiMessages, 500);
		PlayNote(550.0f, 1.0f, 10, midiMessages, 600);
		PlayNote(450.0f, 1.0f, 10, midiMessages, 700);
		PlayNote(350.0f, 1.0f, 10, midiMessages, 800);
		PlayNote(250.0f, 1.0f, 10, midiMessages, 900);
		PlayNote(150.0f, 1.0f, 10, midiMessages, 1000);
		PlayNote(50.0f, 1.0f, 10, midiMessages, 1100);
		PlayNote(5.0f, 1.0f, 10, midiMessages, 1200);
		PlayNote(0.1f, 1.0f, 10, midiMessages, 1300);
		PlayNote(0.01f, 1.0f, 10, midiMessages, 1400);
		PlayNote(0.001f, 1.0f, 10, midiMessages, 1500);

		test = false;
	}
}

//This method will schedule a note to be played
void OutputController::PlayNote(float hertz, float volume, double length, MidiBuffer& midiMessages, int delay)
{
	//https://en.wikipedia.org/wiki/MIDI_Tuning_Standard
	int midiNoteValue = 69 + (12 * log2f(hertz / 440.0f)); //midi note from provided frequency

	MidiMessage midiMessage = MidiMessage::noteOn(1, midiNoteValue, volume);
	midiMessage.setTimeStamp(Time::getMillisecondCounter());

	double aBpmRatio = (double)60 / 120; //the divisor here is the bpm
	
	midiMessages.addEvent(midiMessage, unit * aBpmRatio);

	double time = Time::getMillisecondCounter() + delay; // The time at which the note is to be played. Time::getMillisecondCounter() = current time.
	midiOutput->sendBlockOfMessages(midiMessages, time, unit);
}