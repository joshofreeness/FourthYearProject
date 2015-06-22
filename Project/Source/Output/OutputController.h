/*
  ==============================================================================

    OutputController.h
    Created: 20 Jun 2015 11:42:09pm
    Author:  Joshua

  ==============================================================================
*/

#ifndef OUTPUTCONTROLLER_H_INCLUDED
#define OUTPUTCONTROLLER_H_INCLUDED
//#include <juce_audio_basics/midi/juce_MidiBuffer.h> //TODO: THE HELL?

namespace juce{
	class MidiBuffer;
}

class OutputController {
public:
	OutputController();
	~OutputController();

	void ClockProcess(juce::MidiBuffer& midiMessages); //TODO: THE HELL?

};

#endif  // OUTPUTCONTROLLER_H_INCLUDED
