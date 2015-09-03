/*
  ==============================================================================

    Markov.cpp
    Created: 27 Jul 2015 4:21:34pm
    Author:  Michael

  ==============================================================================
*/

#include "Markov.h"

Markov::Markov(){
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

	//TODO figure out how to fill matrix with values. will probably just be 64 push_back() calls, which looks bad but only happens once so it's fine.
}

Markov::~Markov(){}

// Look at the current (and previous) notes and chords, determine which note should be played next (probability/Markov/whatever), and return its frequency.
int Markov::getNextNote(int currentNote, int chord) {
    // make a matrix (or array of arrays, vector of vectors, etc) of size matrix_dimension * matrix_dimension
    // for the current row
        // generate random number between 0 and 1
        // for each probability
            // if random value < sum of probabilities so far
            // break
            // else
            // add probability to ongoing sum
        // convert note int value to frequency?
    int nextNote;
	return nextNote;
}

void doTransition() {
	// Perform one iteration of the Markov Chain.
}