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

class OutputController {
public:
	OutputController();
	~OutputController();

	void ClockProcess(juce::MidiBuffer& midiMessages);
	void PlayNote(int hertz, float velocity, int length);
	MidiMessage* GetMidiMessageObject();

private:
	std::list<MidiMessage> midiMessagesRecycling;

};

#endif  // OUTPUTCONTROLLER_H_INCLUDED
