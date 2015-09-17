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
#include "../Logging.h"
#include <JuceHeader.h>

namespace juce{
	class MidiBuffer;
	class AudioSampleBuffer;
	class FFT;
}

class InputProcessor {
public:
	InputProcessor();
	~InputProcessor();

	void SetBlock(juce::AudioSampleBuffer& buffer);
	void AnalyseBlock();
	void SetSampleRate(double rate);
	Key_t GetKey();
	Chord_t GetChord();
	float GetFrequency();
private:
	juce::AudioSampleBuffer currentBuffer;
	int currentHighestIndex;
	int currentFrequency;
	double currentSampleRate;
	juce::FFT* fftObject;
};

#endif  // INPUTPROCESSOR_H_INCLUDED
