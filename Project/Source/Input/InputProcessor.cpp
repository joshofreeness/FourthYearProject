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
void InputProcessor::SetBlock() {
}

// Analyses the current block of raw audio input.
void InputProcessor::AnalyseBlock() {}

// Returns the estimated key of the current block of input.
// TODO: Make a Key enum
Key_t InputProcessor::GetKey() {
	return Key_t::A;
}

// Returns the estimated chord of the current block of input.
// TODO: Make a chord enum
Chord_t InputProcessor::GetChord() {
	return Chord_t::Placeholder1;
}