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
	for (int channel = 0; channel < currentBuffer.getNumChannels(); ++channel)
	{
		// Pointer to an array of floats (the actual audio samples in the channel).
		const float* channelData = currentBuffer.getReadPointer(channel);

		std::vector<float> sampleData(channelData, channelData + currentBuffer.getNumSamples());

		// http://stackoverflow.com/questions/10158756/using-stdmax-element-on-a-vectordouble

		auto biggest = std::max_element(std::begin(sampleData), std::end(sampleData));

		int position = std::distance(std::begin(sampleData), biggest);

		#ifdef WIN32
			// Print all sample data from the first block processed
			// So it can be graphed and we can try to figure out what it means
			for (int i = 0; i < currentBuffer.getNumSamples(); i++) {
				LOG(std::to_string(sampleData[i]));
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