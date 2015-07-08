/*
  ==============================================================================

    InputProcessor.h
    Created: 23 Jun 2015 3:24:42pm
    Author:  Michael

  ==============================================================================
*/

#ifndef INPUTPROCESSOR_H_INCLUDED
#define INPUTPROCESSOR_H_INCLUDED

#include "../Enums.h"
#include <JuceHeader.h>

namespace juce{
	class MidiBuffer;
	class AudioSampleBuffer;
}

class InputProcessor {
public:
	InputProcessor();
	~InputProcessor();

	void SetBlock(juce::AudioSampleBuffer& buffer);
	void AnalyseBlock();
	Key_t GetKey();
	Chord_t GetChord();
	float GetFrequency();
private:
    juce::AudioSampleBuffer currentBuffer;
	float currentFrequency;
};

#endif  // INPUTPROCESSOR_H_INCLUDED
