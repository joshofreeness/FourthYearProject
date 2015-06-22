/*
  ==============================================================================

    OutputController.cpp
    Created: 20 Jun 2015 11:42:09pm
    Author:  Joshua

  ==============================================================================
*/

#include "OutputController.h"

OutputController::OutputController(){}
OutputController::~OutputController(){}


void OutputController::ClockProcess(juce::MidiBuffer& midiMessages) {


	//MidiMessage* newMidiMessage = GetMidiMessageObject();

	int noteMode = 148;
	int KeyNumber = 60;
	int NoteOnVelocity = 127;
	juce::MidiMessage* newMidiMessage = new juce::MidiMessage(noteMode, KeyNumber, NoteOnVelocity, 0);

	//TODO: find out how to modify Midimessage instead of using constructor use GetMidiMessageObject()

	midiMessages.addEvent(*newMidiMessage, 0);

}

//This method will schedule a note to be played
void OutputController::PlayNote(int hertz, float volume, int length)
{
	MidiMessage* midiMessageNoteOn = GetMidiMessageObject();
	MidiMessage* midiMessageNoteOff = GetMidiMessageObject();

	int NoteOnVelocity = 127  * volume; //127 is max value
	int noteModeOn = 148; //Note on
	//TODO: Convert hertz to midi value

	//TODO: add it to a list of notes to be added to the next clock cycle
}

MidiMessage* OutputController::GetMidiMessageObject()
{
	//TODO: find out how to reuse MidiMessage objects instead of new all the time
	//Possible keep a linked list(doesn't have to be) and a pointer to the next available object, when ClockProcess is called and they are sent
	//to the DAW then set pointer back to the head
	return new MidiMessage();
}