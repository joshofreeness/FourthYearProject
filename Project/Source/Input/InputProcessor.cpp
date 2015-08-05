/*
  ==============================================================================

    InputProcessor.cpp
    Created: 23 Jun 2015 3:24:42pm
    Author:  Michael

  ==============================================================================
*/

#include "InputProcessor.h"

InputProcessor::InputProcessor()
{
	fastFourierTransformObject = new FFT(9, false);
}
InputProcessor::~InputProcessor(){}

// Sets the current block of audio data to be analysed.
void InputProcessor::SetBlock(juce::AudioSampleBuffer& buffer) {
	currentBuffer = buffer;
}

// Analyses the current block of raw audio input.
void InputProcessor::AnalyseBlock() {
	for (int channel = 0; channel < currentBuffer.getNumChannels(); ++channel)
	{
		// Pointer to an array of floats (the actual audio samples in the channel).
		//const float* channelData = currentBuffer.getReadPointer(channel);
		float* channelData = currentBuffer.getWritePointer(channel);

		//std::vector<float> sampleData(channelData, channelData + currentBuffer.getNumSamples());

		// http://stackoverflow.com/questions/10158756/using-stdmax-element-on-a-vectordouble

		//auto biggest = std::max_element(std::begin(sampleData), std::end(sampleData));

		//int position = std::distance(std::begin(sampleData), biggest);

#if FALSE//#ifdef WIN32
		LOG("currentBuffer.getNumSamples() is " + std::to_string(currentBuffer.getNumSamples()));
		LOG("The size of the vector is " + std::to_string(sampleData.size()));
		LOG("The highest magnitude in channel " + std::to_string(channel) + " is " + std::to_string(*biggest) + " at position " + std::to_string(position));
#endif 

		//THIS method supposidly does a FFT but I don't know what order it should be nore how to get meaningful data back from it
			fastFourierTransformObject->performFrequencyOnlyForwardTransform(channelData);

			std::vector<float> sampleData(channelData, channelData + currentBuffer.getNumSamples());
			auto biggest = std::max_element(std::begin(sampleData), std::end(sampleData));
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