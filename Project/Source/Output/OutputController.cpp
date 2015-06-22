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


	MidiMessage* newMidiMessage = GetMidiMessageObjectNoteOn();

	//int noteMode = 148;
	//int KeyNumber = 60;
	//int NoteOnVelocity = 127;
	//juce::MidiMessage* newMidiMessage = new juce::MidiMessage(noteMode, KeyNumber, NoteOnVelocity, 0);

	//TODO: find out how to modify Midimessage instead of using constructor use GetMidiMessageObject()
	newMidiMessage->setVelocity(1.0);
	newMidiMessage->setChannel(1);
	newMidiMessage->setNoteNumber(60);
	newMidiMessage->setTimeStamp(0.0);
	midiMessages.addEvent(*newMidiMessage, 0);

	//reset pointers (possible race condition)
	currentOnList = headOnList;
	currentOffList = headOffList;

}

//This method will schedule a note to be played
void OutputController::PlayNote(int hertz, float volume, int length)
{
	MidiMessage* midiMessageNoteOn = GetMidiMessageObjectNoteOn();
	MidiMessage* midiMessageNoteOff = GetMidiMessageObjectNoteOff();

	int NoteOnVelocity = 127  * volume; //127 is max value
	int noteModeOn = 148; //Note on
	//TODO: Convert hertz to midi value

	//TODO: add it to a list of notes to be added to the next clock cycle
}

MidiMessage* OutputController::GetMidiMessageObjectNoteOn()
{
	return GetNextFromList(headOnList, currentOnList, true);

	//TODO: find out how to reuse MidiMessage objects instead of new all the time
	//Possible keep a linked list(doesn't have to be) and a pointer to the next available object, when ClockProcess is called and they are sent
	//to the DAW then set pointer back to the head
	MidiMessage temp = MidiMessage::noteOn(0, 0, 0.0f);
	return &temp;
}

MidiMessage* OutputController::GetMidiMessageObjectNoteOff()
{
	return GetNextFromList(headOffList, currentOffList, false);

	//TODO: find out how to reuse MidiMessage objects instead of new all the time
	//Possible keep a linked list(doesn't have to be) and a pointer to the next available object, when ClockProcess is called and they are sent
	//to the DAW then set pointer back to the head
	MidiMessage temp = MidiMessage::noteOff(0, 0, 0);
	return &temp;
}

MidiMessage* OutputController::GetNextFromList(midiNode *head, midiNode *current, bool noteOnMessage)
{
	//Handle a completely empty list
	if (head == nullptr)
	{
		head = new midiNode();
		head->message = NewMidiMessage(noteOnMessage);
		current = head;
		return &(head->message);
	}

	//handle if next is null  (current should never be null)
	if (current->next == nullptr)
	{
		current->next = new midiNode();
		current->next->message = NewMidiMessage(noteOnMessage);
		current = current->next;
		return &(current->message);
	} else
	{
		current = current->next;
		return &(current->message);
	}
}

MidiMessage OutputController::NewMidiMessage(bool noteOnMessage)
{
	if (noteOnMessage)
	{
		return MidiMessage::noteOn(0, 0, 0.0f);
	}
	return  MidiMessage::noteOff(0, 0, 0);
}