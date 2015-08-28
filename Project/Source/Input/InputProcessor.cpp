/*
  ==============================================================================

    InputProcessor.cpp
    Created: 23 Jun 2015 3:24:42pm
    Author:  Michael

  ==============================================================================
*/

#include "InputProcessor.h"

InputProcessor::InputProcessor(){
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

		/* KissFFT Temporarily commented out.
		// Config object with settings and stuff
		kiss_fftr_cfg cfg = kiss_fftr_alloc( currentBuffer.getNumSamples(), false, 0, 0 );
		
		// Array of complex data that the FFT output will be written to.
		kiss_fft_cpx transformed[2048];

		// Do the FFT
		kiss_fftr( cfg , channelData , transformed );
            
		// Delete the config object
		free(cfg);

		// Find the fundamental frequency
		currentFrequency = 0;
		for (int i = 0; i < currentBuffer.getNumSamples(); i ++)
		{
			if ((pow(transformed[i].r, 2) + pow(transformed[i].i, 2))>(pow(transformed[currentFrequency].r, 2) + pow(transformed[currentFrequency].i, 2))){
				currentFrequency = i;
			}
		}*/

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

		//frequency(currentHightestIndex) = sampleRate*currentHightestIndex/2*blockSize
		currentFrequency = (currentSampleRate*currentHighestIndex) / (currentBuffer.getNumSamples() * 2) ;


#ifdef WIN32
	LOG("Fundamental frequency of channelData is " + std::to_string(currentFrequency));
	//LOG("with a magnitude of " + std::to_string(pow(transformed[currentFrequency].r, 2) + pow(transformed[currentFrequency].i, 2)));
#endif

	}
}

void InputProcessor::SetSampleRate(double rate)
{
	currentSampleRate = rate;
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
	return (float)currentFrequency;
}