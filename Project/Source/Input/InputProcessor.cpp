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
	//TODO: Actually do something with currentBuffer
	// https://www.juce.com/api/classAudioSampleBuffer.html

	const float** readPointers = currentBuffer.getArrayOfReadPointers();
	const float* thePointers = *readPointers;

	// lol I have no idea what I'm doing

	//for (int channel = 0; channel < number of pointers; ++channel)
	//{
	//	float* channelData = buffer.getSampleData(channel);
	//
	//	// Do something with channelData
	//}
}

// Returns the estimated key of the current block of input.
Key_t InputProcessor::GetKey() {
	return Key_t::A;
}

// Returns the estimated chord of the current block of input.
Chord_t InputProcessor::GetChord() {
	return Chord_t::1;
}