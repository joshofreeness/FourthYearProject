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

	void SetVolume(float volume){ m_volume = volume; };
	float GetVolume(void){ return m_volume; };

	void SetFrequency(float frequency) { m_frequency = frequency; };
	float GetFrequency(void){ return m_frequency; };

	void SetKey(int key) { m_key = key; };
	int GetKey(void){ return m_key; };

private:
	double unit = 44100.0; // Represents something to do with the number of channels in the sound driver, I think. Most common values 44,100 and 44,400. Idk. Google it.

	MidiOutput* midiOutput = MidiOutput::openDevice(0);

	float m_volume;
	float m_frequency;
	int m_key;
};

#endif  // OUTPUTCONTROLLER_H_INCLUDED
