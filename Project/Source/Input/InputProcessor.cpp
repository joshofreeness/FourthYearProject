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

// Analyses the current block of raw audio input.
void InputProcessor::AnalyseBlock() {
#ifdef WIN32
	LOG("The current number of channels is " + std::to_string(currentBuffer.getNumChannels()));
#endif

	for (int channel = 0; channel < currentBuffer.getNumChannels(); ++channel)
	{
		// Pointer to an array of floats (the actual audio samples in the channel).
		const float* channelData = currentBuffer.getReadPointer(channel);

		std::vector<float> sampleData(*channelData, currentBuffer.getNumSamples());

		/* http://stackoverflow.com/questions/10158756/using-stdmax-element-on-a-vectordouble

		auto biggest = std::max_element(std::begin(sampleData), std::end(sampleData));

		#ifdef WIN32
		LOG("The highest magnitude in channel " + std::to_string(channel) + " is " + std::to_string(*biggest)) + " at position " + std::to_string(std::distance(std::begin(sampleData), biggest));
		#endif 

		*/

		//TODO: Do stuff with the data

		//this will be removed later and is just for investigative purposes
		// I want to find the frequency with the highest volume (can get the value by currentBuffer.getMagnitude()
		// and set that as our current frequency, so that our output notes will kind of match the recorded input.
		juce::Range<float> minAndMax1 = currentBuffer.findMinMax(0, 0, currentBuffer.getNumSamples());
		juce::Range<float> minAndMax2 = currentBuffer.findMinMax(1, 0, currentBuffer.getNumSamples());
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