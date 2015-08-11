/*
  ==============================================================================

    InputProcessor.cpp
    Created: 23 Jun 2015 3:24:42pm
    Author:  Michael

  ==============================================================================
*/

#include "InputProcessor.h"
#include "../Analysis/FFT.h"

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
	//For most audio setups the audio will either be mono, or both tracks will be the same
	if (currentBuffer.getNumChannels() >0)
	{
		//perform fourier transform TODO: is this the right place for it? probs not
		Analysis::FFT::PerformFFT(currentBuffer.getWritePointer(0), currentBuffer.getNumSamples());
	}
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

		//juce FFT code - being replaced
		//THIS method supposidly does a FFT but I don't know what order it should be nore how to get meaningful data back from it
			//fastFourierTransformObject->performFrequencyOnlyForwardTransform(channelData);

			std::vector<float> sampleData(channelData, channelData + currentBuffer.getNumSamples());
			//auto biggest = std::max_element(std::begin(sampleData), std::end(sampleData));

#ifdef WIN32
			//To stop it printing thousands of lines per second
			if (rand() % 1000 == 1) {
				LOG("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
				// Print all sample data from the first block processed
				// So it can be graphed and we can try to figure out what it means
				for (int i = 0; i < currentBuffer.getNumSamples(); i++) {
					LOG(std::to_string(sampleData[i]));
				}
			}
#endif

		//TODO: Temporary thing matching output frequency to input.
		//	juce::FFT::performFrequencyOnlyForwardTransform(currentBuffer);
		//	juce::

		/* FFT docs and useful links:
		http://www.juce.com/forum/topic/open-source-fft-plugin
		https://github.com/aaronleese/FFT-Plugin
		http://learn.juce.com/doc/classFFT.php

		Also look into this once we think we have a calculated frequency value:
		http://www.juce.com/forum/topic/best-way-update-gui-parameters
		*/
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