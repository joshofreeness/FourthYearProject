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
		// Pointer to an array of floats (the actual audio samples in the channel).
		const float* channelData = currentBuffer.getReadPointer(channel);

		// TODO: Find a way to convert a pointer array to a vector without needing to know the size of the array
		// Or find a way to get the size of the array
		std::vector<float> sampleData;
		
		float sample1 = channelData[0];
		float sample2 = channelData[1];
		float sample3 = channelData[2];
		float sample4 = channelData[3];
		float sample5 = channelData[4];
		float sample6 = channelData[5];
		float sample7 = channelData[6];
		float sample8 = channelData[7];
		float sample9 = channelData[8];

#ifdef WIN32
		LOG(std::to_string(sample1));
		LOG(std::to_string(sample2));
		LOG(std::to_string(sample3));
		LOG(std::to_string(sample4));
		LOG(std::to_string(sample5));
		LOG(std::to_string(sample6));
		LOG(std::to_string(sample7));
		LOG(std::to_string(sample8));
		LOG(std::to_string(sample9));
#endif
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