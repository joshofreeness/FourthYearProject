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
Note last played:		1	2	3	4	5	6	7	8
	Note Heard :	1           1
					2
					3  0.5              0.5   
					4     
					5           1 
					6     
					7
					8
	*/

	/*
	Note to play:		1	2	3	4	5	6	7	8
	Note Heard :	1
					2
					3      ############################
					4      #### PROBABILITIES HERE ####
					5      ####   FOR REFERENCE    ####
					6      ############################
					7
					8
	*/

	std::vector<double> row_1 = { 0, 0, 1, 0, 0, 0, 0, 0 };
	std::vector<double> row_2 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_3 = { 0.5, 0, 0, 0, 0.5, 0, 0, 0 };
	std::vector<double> row_4 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_5 = { 0, 0, 1, 0, 0, 0, 0, 0 };
	std::vector<double> row_6 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_7 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_8 = { 0, 0, 0, 0, 0, 0, 0, 0 };

	note = new std::vector<std::vector<double>>(9);
	chord = new std::vector<std::vector<double>>(9);

	note->operator[](1) = row_1;
	note->operator[](2) = row_1;
	note->operator[](3) = row_1;
	note->operator[](4) = row_1;
	note->operator[](5) = row_1;
	note->operator[](6) = row_1;
	note->operator[](7) = row_1;
	note->operator[](8) = row_1;

	chord->operator[](1) = row_1;
	chord->operator[](2) = row_1;
	chord->operator[](3) = row_1;
	chord->operator[](4) = row_1;
	chord->operator[](5) = row_1;
	chord->operator[](6) = row_1;
	chord->operator[](7) = row_1;
	chord->operator[](8) = row_1;

}

Markov::~Markov(){}

// Given the chord and the last note heard from the musician, determine which note the computer should play.
int Markov::getNextNote(int currentNote) {
	std::vector<double> workingRow = note->operator[](currentNote);

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

// Given the chord and the last note heard from the musician, determine which note the computer should play.
int Markov::getNextChord(int currentChord) {
	std::vector<double> workingRow = note->operator[](currentNote);

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