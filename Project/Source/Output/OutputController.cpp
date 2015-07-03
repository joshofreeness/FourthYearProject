/*
  ==============================================================================

    OutputController.cpp
    Created: 20 Jun 2015 11:42:09pm
    Author:  Joshua

  ==============================================================================
*/

#include "OutputController.h"
#include <thread>

OutputController::OutputController(){}
OutputController::~OutputController(){}


void threadNoteOff(MidiMessage* midiMessageNoteOff, OutputController *controller)
{
	std::this_thread::sleep_for(std::chrono::seconds(3));
	controller->scheduledToAddToBuffer.push_back(midiMessageNoteOff);
}


void OutputController::ClockProcess(juce::MidiBuffer& midiMessages, double currentTime, double msPerSample) {

	midiMessages.clear();
	if (first)
	{
		PlayNote(440.0f, 1.0f, currentTime, 1, msPerSample);
		first = false; //uncommented for constant tone
	}
	std::cout << currentTime;

	std::list<MidiMessage*>::const_iterator iterator;
	for (iterator = scheduledToAddToBuffer.begin(); iterator != scheduledToAddToBuffer.end(); ++iterator) {
		midiMessages.addEvent(*(*iterator), 1); //the 0 value could cause problems
		
	}
	//TODO: Does the iterator need to be deleted/destroyed?

	scheduledToAddToBuffer.clear();

	//reset pointers (possible race condition)
	currentOnList = headOnList;
	currentOffList = headOffList;

}

//This method will schedule a note to be played
void OutputController::PlayNote(float hertz, float volume, double currentTime, double length, double msPerSample)
{
	//MidiMessage temp = MidiMessage::noteOn(0, 0, 0.0f);
	MidiMessage* midiMessageNoteOn = GetNextFromList(headOnList, currentOnList, true);
	MidiMessage* midiMessageNoteOff = GetNextFromList(headOffList, currentOffList, false);

	//https://en.wikipedia.org/wiki/MIDI_Tuning_Standard
	int midiNoteValue = 69 + (12 * log2f(hertz / 440.0f)); //midi note from provided frequency
	double startingTimeStamp = currentTime + midiMessagesThisCycle*msPerSample;

	midiMessageNoteOn->setVelocity(volume);
	midiMessageNoteOn->setChannel(1);
	midiMessageNoteOn->setNoteNumber(midiNoteValue);
	midiMessageNoteOn->setTimeStamp(startingTimeStamp);

	midiMessageNoteOff->setVelocity(volume);
	midiMessageNoteOff->setChannel(1);
	midiMessageNoteOff->setNoteNumber(midiNoteValue);
	midiMessageNoteOff->setTimeStamp(startingTimeStamp + length);

	scheduledToAddToBuffer.push_back(midiMessageNoteOn);
	//TODO: correct timestamps, this is stopping it instantly
	std::thread thread(threadNoteOff, midiMessageNoteOff, this);
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