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

	std::vector<float> row_1 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<float> row_2 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<float> row_3 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<float> row_4 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<float> row_5 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<float> row_6 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<float> row_7 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<float> row_8 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	matrix[1] = row_1;
	matrix[2] = row_2;
	matrix[3] = row_3;
	matrix[4] = row_4;
	matrix[5] = row_5;
	matrix[6] = row_6;
	matrix[7] = row_7;
	matrix[8] = row_8;
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