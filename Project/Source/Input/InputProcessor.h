/*
  ==============================================================================

    InputProcessor.h
    Created: 23 Jun 2015 3:24:42pm
    Author:  Michael

	Takes the current block of raw audio samples, and performs the FFT for pitch detection.
	Returns the frequency of the current note heard to PluginProcessor.

  ==============================================================================
*/

#ifndef INPUTPROCESSOR_H_INCLUDED
#define INPUTPROCESSOR_H_INCLUDED

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
	float GetFrequency();

private:
	juce::AudioSampleBuffer currentBuffer;
	int currentHighestIndex;
	double currentFrequency;
	double currentSampleRate;
	juce::FFT* fftObject;
};

#endif  // INPUTPROCESSOR_H_INCLUDED
