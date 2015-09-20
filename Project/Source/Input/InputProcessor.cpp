/*
  ==============================================================================

    InputProcessor.cpp
    Created: 23 Jun 2015 3:24:42pm
    Author:  Michael

	Takes the current block of raw audio samples, and performs the FFT for pitch detection.
	Returns the frequency of the current note heard to PluginProcessor.

  ==============================================================================
*/

#include "InputProcessor.h"

InputProcessor::InputProcessor() {
	// log2(2048 samples per block) = 11, FFT isInverse = false
	fftObject = new juce::FFT(11, false);
}

InputProcessor::~InputProcessor(){
	free(fftObject);
}

// Sets the current block of audio data to be analysed.
void InputProcessor::SetBlock(juce::AudioSampleBuffer& buffer) {
	currentBuffer = buffer;
}

// Analyses the current block of raw audio input.
void InputProcessor::AnalyseBlock() {
	// For most audio setups the audio will either be mono, or both tracks will be the same
	// So we only FFT one of the channels, for speed
	if (currentBuffer.getNumChannels() > 0) {
		float* channelData = currentBuffer.getWritePointer(0);
		float* doubleLength = new float[currentBuffer.getNumSamples() * 2];

		for (int i = 0; i < currentBuffer.getNumSamples(); i++) {
			doubleLength[i] = channelData[i];
		}

		fftObject->performRealOnlyForwardTransform(doubleLength);

		// Find the fundamental frequency
		currentHighestIndex = 0;
		for (int i = 0; i < currentBuffer.getNumSamples() * 2; i+= 2) {
			float newMag = (pow(doubleLength[i], 2) + pow(doubleLength[i + 1], 2));
			float oldMag = (pow(doubleLength[currentHighestIndex], 2) + pow(doubleLength[currentHighestIndex + 1], 2));
			
			if (newMag > oldMag) {
				currentHighestIndex = i;
			}
		}

		currentFrequency = (currentSampleRate*currentHighestIndex) / (currentBuffer.getNumSamples() * 2) ;

		//NOTE: current frequency is only accurate to the nearest 10.8Hz so have to "auto-tune" the results
		//The following takes frequency to the nearest semi-tone (assuming tuned to A=440)
		int noteNum = int(0.5 + 12 * log2(currentFrequency / 27.5));
		double filteredFrequency = 27.5 * pow(2.0, noteNum / 12.0);

		currentFrequency = filteredFrequency;
	}
}

void InputProcessor::SetSampleRate(double rate)
{
	currentSampleRate = rate;
}

float InputProcessor::GetFrequency()
{
	return (float)currentFrequency;
}