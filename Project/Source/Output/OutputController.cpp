/*
  ==============================================================================

    OutputController.cpp
    Created: 20 Jun 2015 11:42:09pm
    Author:  Joshua

  ==============================================================================
*/

#include "OutputController.h"
#include <JuceHeader.h>
//#include <juce_audio_basics/midi/juce_MidiMessage.h>

OutputController::OutputController(){}
OutputController::~OutputController(){}


void OutputController::ClockProcess(juce::MidiBuffer& midiMessages) {

	using namespace juce;
	int noteMode = 148;
	int KeyNumber = 60;
	int NoteOnVelocity = 127;
	juce::MidiMessage* newMidiMessage = new juce::MidiMessage(noteMode, KeyNumber, NoteOnVelocity, 0);

	midiMessages.addEvent(*newMidiMessage, 0);

}