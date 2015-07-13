/*
  ==============================================================================

    InputProcessor.cpp
    Created: 23 Jun 2015 3:24:42pm
    Author:  Michael

  ==============================================================================
*/

#include "InputProcessor.h"
#include <string>

// See http://stackoverflow.com/questions/1149620/how-to-write-to-the-output-window-in-visual-studio for details
#include <Windows.h>
#include <iostream>
#include <sstream>

#define LOG_W( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

#define LOG( s )            \
{                             \
   std::ostringstream os_;    \
   os_ << s;                   \
   OutputDebugString( os_.str().c_str() );  \
}

using namespace std;

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

		string test = "This is a test";
		cout << test;

		// TODO: Find some way of displaying/logging data to ourselves (maybe add a way to change a text field in the GUI
		// so we can see things like the number of samples and channels. Would be very useful for our own stuff.
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