/*
  ==============================================================================

    OutputController.h
    Created: 20 Jun 2015 11:42:09pm
    Author:  Joshua

  ==============================================================================
*/

#ifndef OUTPUTCONTROLLER_H_INCLUDED
#define OUTPUTCONTROLLER_H_INCLUDED
#include <list>
#include <JuceHeader.h>


namespace juce{
	class MidiBuffer;
	class MidiMessage;
}

struct midiNode
{
	MidiMessage message;
	midiNode *next;
};

class OutputController {
public:
	OutputController();
	~OutputController();

	void ClockProcess(MidiBuffer& midiMessages);
	void PlayNote(float hertz, float velocity, double length, juce::MidiBuffer& midiMessages, int delay);
private:
	midiNode *headOnList = nullptr;
	midiNode *headOffList = nullptr;
	midiNode *currentOnList = nullptr;
	midiNode *currentOffList = nullptr;

	std::list<MidiMessage*> scheduledToAddToBuffer;

	bool first = true;
	bool second = false;
	bool test = true;

	const double unit = 44100.0; // Represents something to do with the number of channels in the sound driver, I think. Most common values 44,100 and 44,400. Idk. Google it.

	MidiMessage* GetNextFromList(midiNode* head, midiNode* current, bool onMessage);
	MidiMessage NewMidiMessage(bool noteOnMessage);

	MidiOutput* midiOutput = MidiOutput::openDevice(0);

};

#endif  // OUTPUTCONTROLLER_H_INCLUDED
