/*
  ==============================================================================

    OutputController.h
    Created: 20 Jun 2015 11:42:09pm
    Author:  Joshua

	Takes the frequency of a note, and outputs a MIDI instruction to the DAW 
	that will be passed on to a synthesiser to produce the real output.

  ==============================================================================
*/

#ifndef OUTPUTCONTROLLER_H_INCLUDED
#define OUTPUTCONTROLLER_H_INCLUDED
#include <list>
#include <JuceHeader.h>
#include "../Logging.h"

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
	void PlayNote(float hertz, MidiBuffer& midiMessages, int delay);

private:
	double unit = 44100.0; // Sampling rate. In future, change this to be asked of the DAW instead of hardcoded as the plugin will likely fail if it changes.

	MidiOutput* midiOutput = MidiOutput::openDevice(0);
};

#endif  // OUTPUTCONTROLLER_H_INCLUDED
