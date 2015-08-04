/*
  ==============================================================================

    NoteAnalyser.cpp
    Created: 27 Jul 2015 4:21:34pm
    Author:  Michael

  ==============================================================================
*/

#include "NoteAnalyser.h"

NoteAnalyser::NoteAnalyser(){}
NoteAnalyser::~NoteAnalyser(){}

// Look at the current (and previous) notes and chords, determine which note should be played next (probability/Markov/whatever), and return its frequency.
float NoteAnalyser::getNote() {
	return frequency;
}

//TODO: Sort out what other functions may be needed.