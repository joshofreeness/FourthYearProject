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
	Note to play:		1	2	3	4	5	6	7	8
	Note Heard :	1
					2
					3      ############################
					4      ###### PROBABILITIES #######
					5      ######    GO HERE    #######
					6      ############################
					7
					8
	*/

	std::vector<double> row_1 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_2 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_3 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_4 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_5 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_6 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_7 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_8 = { 0, 0, 0, 0, 0, 0, 0, 0 };
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

// Given the chord and the last note heard from the musician, determine which note the computer should play.
int Markov::getNextNote(int currentNote, int chord) {
	std::vector<double> workingRow = matrix[currentNote];

	// TODO: Are we using a temporary copy of matrix and editing it based on the chord?
	// currently the chord has no effect on the outcome, just the probabilities.

	// Random number between 0 and 1.
	double r = ((double)rand() / (RAND_MAX));

	int nextNote = 0;

	for (int i = 1; i < workingRow.size(); i++) {

		double currentProb = workingRow[i];

		if (currentProb >= r) {
			nextNote = i;
			break;

		} else {
			r -= currentProb;

		}
	}

#ifdef WIN32
	LOG("Note chosen: " + std::to_string(nextNote) + " (note heard was: " + std::to_string(currentNote) + ").");
#endif

	return nextNote;
}