/*
  ==============================================================================

    InputProcessor.cpp
    Created: 23 Jun 2015 3:24:42pm
    Author:  Michael

  ==============================================================================
*/

#include "InputProcessor.h"

InputProcessor::InputProcessor(){}
InputProcessor::~InputProcessor(){}

// Sets the current block of audio data to be analysed.
void InputProcessor::SetBlock(juce::AudioSampleBuffer& buffer) {
	currentBuffer = buffer;
}

// Sets the current block of audio data to be analysed.
void InputProcessor::SetNumInputChannels(int number) {
	numInputChannels = number;
}

// Analyses the current block of raw audio input.
void InputProcessor::AnalyseBlock() {

	for (int channel = 0; channel < numInputChannels; ++channel)
	{
		// pointer to an array of floats (the actual audio samples in the channel).
		const float* channelData = currentBuffer.getReadPointer(channel);
		
		int i = 0;
		std::vector<float> samples;

		try {
			samples.push_back(channelData[i]);
			i++;
		} catch (...) {
		}
	}
}

// Returns the estimated key of the current block of input.
Key_t InputProcessor::GetKey() {
	return Key_t::A;
}

// Returns the estimated chord of the current block of input.
Chord_t InputProcessor::GetChord() {
	return Chord_t::Placeholder1;
}

float InputProcessor::GetFrequency()
{
	return currentFrequency;
}