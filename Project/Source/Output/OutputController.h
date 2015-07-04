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

	void ClockProcess(juce::MidiBuffer& midiMessages);
	void PlayNote(float hertz, float velocity, double length);
private:
	midiNode *headOnList = nullptr;
	midiNode *headOffList = nullptr;
	midiNode *currentOnList = nullptr;
	midiNode *currentOffList = nullptr;

	std::list<MidiMessage*> scheduledToAddToBuffer;

	bool first = true;
	bool second = false;

	MidiMessage* GetNextFromList(midiNode* head, midiNode* current, bool onMessage);
	MidiMessage NewMidiMessage(bool noteOnMessage);

};

#endif  // OUTPUTCONTROLLER_H_INCLUDED
