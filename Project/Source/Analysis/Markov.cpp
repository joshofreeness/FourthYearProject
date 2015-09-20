/*
  ==============================================================================

    Markov.cpp
    Created: 27 Jul 2015 4:21:34pm
    Author:  Michael

	This class contains the stochastic matrices for chord and note transitions, 
	and functions to utilise their probability values to calculate the next chord & note.

  ==============================================================================
*/

#include "Markov.h"

Markov::Markov(){

	// Row = note heard
	// Column = note to play
	std::vector<double> row_1 = { 0, 0, 1, 0, 0, 0, 0, 0 };
	std::vector<double> row_2 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_3 = { 0.5, 0, 0, 0, 0.5, 0, 0, 0 };
	std::vector<double> row_4 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_5 = { 0, 0, 1, 0, 0, 0, 0, 0 };
	std::vector<double> row_6 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_7 = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<double> row_8 = { 0, 0, 0, 0, 0, 0, 0, 0 };

	// Row = current chord
	// Column = chord to transition to
	std::vector<double> chord_row_1 = { 0, 0, 0, 0.5, 0.5, 0, 0, 0 };
	std::vector<double> chord_row_2 = { 0.3, 0, 0, 0.34, 0.3, 0, 0, 0 };
	std::vector<double> chord_row_3 = { 0.3, 0, 0, 0.3, 0.34, 0, 0, 0 };
	std::vector<double> chord_row_4 = { 0.3, 0, 0, 0, 0.34, 0.3, 0, 0 };
	std::vector<double> chord_row_5 = { 0.34, 0, 0, 0.3, 0, 0.3, 0, 0 };
	std::vector<double> chord_row_6 = { 0.3, 0, 0, 0.3, 0.34, 0, 0, 0 };
	std::vector<double> chord_row_7 = { 0.5, 0, 0, 0, 0.5, 0, 0, 0 };
	std::vector<double> chord_row_8 = { 0, 0, 0, 0.5, 0.5, 0, 0, 0 };

	note = new std::vector<std::vector<double>>(8);
	chord = new std::vector<std::vector<double>>(8);

	note->operator[](0) = row_1;
	note->operator[](1) = row_2;
	note->operator[](2) = row_3;
	note->operator[](3) = row_4;
	note->operator[](4) = row_5;
	note->operator[](5) = row_6;
	note->operator[](6) = row_7;
	note->operator[](7) = row_8;

	chord->operator[](0) = chord_row_1;
	chord->operator[](1) = chord_row_2;
	chord->operator[](2) = chord_row_3;
	chord->operator[](3) = chord_row_4;
	chord->operator[](4) = chord_row_5;
	chord->operator[](5) = chord_row_6;
	chord->operator[](6) = chord_row_7;
	chord->operator[](7) = chord_row_8;

}

Markov::~Markov(){}

// Given the last note heard from the musician, determine which note the computer should play next.
int Markov::getNextNote(int currentNote) {
	std::vector<double> workingRow = note->operator[](currentNote-1);

	// Random number between 0 and 1.
	double r = ((double)rand() / (RAND_MAX));

	int nextNote = 0;

	for (int i = 0; i < workingRow.size(); i++) {

		double currentProb = workingRow[i];

		if (currentProb >= r) {

			// Increment because array index starts at 0
			nextNote = i + 1;
			break;

		} else {
			r -= currentProb;

		}
	}

	return nextNote;
}

// Given the current chord, determine which chord our next note should be in.
int Markov::getNextChord(int currentChord) {
	std::vector<double> workingRow = chord->operator[](currentChord);

	// Random number between 0 and 1.
	double r = ((double)rand() / (RAND_MAX));

	int nextChord = 0;

	for (int i = 0; i < workingRow.size(); i++) {

		double currentProb = workingRow[i];

		if (currentProb >= r) {

			// Increment because array index starts at 0
			nextChord = i + 1;
			break;

		} else {
			r -= currentProb;

		}
	}

	return nextChord;
}