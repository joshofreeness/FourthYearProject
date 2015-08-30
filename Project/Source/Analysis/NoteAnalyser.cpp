/*
  ==============================================================================

    NoteAnalyser.cpp
    Created: 27 Jul 2015 4:21:34pm
    Author:  Michael

  ==============================================================================
*/

#include "NoteAnalyser.h"

/*
Next note to play:	1	2	3	4	5	6	7	8
Current note:	1
2
3      ############################
4      ###### PROBABILITIES #######
5      ######    GO HERE    #######
6      ############################
7
8
*/

NoteAnalyser::NoteAnalyser(){
	std::vector<std::vector<float>> mInitial(rows, std::vector<float>(columns));
	std::vector<std::vector<float>> mTransition(rows, std::vector<float>(columns));
	// TODO: Fill transition matrix with state change probabilities
}

NoteAnalyser::~NoteAnalyser(){}

// Look at the current (and previous) notes and chords, determine which note should be played next (probability/Markov/whatever), and return its frequency.
float NoteAnalyser::getNextNote(float currentFrequency) {
	//TODO: Add helper function .h file (similar to enums, logging) that contains functions to convert freq - note and vice versa.
	// Convert frequency to note
	// Clear initial matrix
	// Set current note as current state in initial matrix
	// doTransition()
	// Convert that note back into a frequency

	return currentFrequency;
}

void doTransition() {
	// Perform one iteration of the Markov Chain.
}