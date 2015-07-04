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

	if (first)
	{
		PlayNote(450.0f, 1.0f, 1);
		first = false;
		second = true;
	}
	else if (second)
	{
		PlayNote(300.0f, 1.0f, 30000);
		second = false;
	}
	else
	{
		//PlayNote(150.0f, 1.0f, 10000);
	}

	std::list<MidiMessage*>::const_iterator iterator;

	int i = 1;
	for (iterator = scheduledToAddToBuffer.begin(); iterator != scheduledToAddToBuffer.end(); ++iterator) {
		midiMessages.addEvent(*(*iterator), i);
		i++;
	}

	scheduledToAddToBuffer.clear();

	//reset pointers (possible race condition)
	currentOnList = headOnList;
	currentOffList = headOffList;
}

//This method will schedule a note to be played
void OutputController::PlayNote(float hertz, float volume, double length)
{
	MidiMessage* midiMessageNoteOn = GetNextFromList(headOnList, currentOnList, true);
	MidiMessage* midiMessageNoteOff = GetNextFromList(headOffList, currentOffList, false);

	//https://en.wikipedia.org/wiki/MIDI_Tuning_Standard
	int midiNoteValue = 69 + (12 * log2f(hertz / 440.0f)); //midi note from provided frequency

	midiMessageNoteOn->setVelocity(volume);
	midiMessageNoteOn->setChannel(1);
	midiMessageNoteOn->setNoteNumber(midiNoteValue);
	midiMessageNoteOn->setTimeStamp(0);

	midiMessageNoteOff->setVelocity(volume);
	midiMessageNoteOff->setChannel(1);
	midiMessageNoteOff->setNoteNumber(midiNoteValue);
	midiMessageNoteOff->setTimeStamp(length);

	scheduledToAddToBuffer.push_back(midiMessageNoteOn);
	//scheduledToAddToBuffer.push_back(midiMessageNoteOff);
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