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
void placeholderProbabilityStuff() {
	/*
	Next note to play:	1	2	3	4	5	6	7	8
	Current note:	1
					2
					3
					4
					5
					6
					7
					8
	*/

	//TODO: Figure out how to move this into the header without causing compile errors.
	std::vector<std::vector<float>> theMatrix;

	// Creates a 2D vector of size 8x8, filled with 0s - our Markov probability matrix.
	theMatrix.resize(8, std::vector<float>(8, 0));
}