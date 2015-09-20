/*
  ==============================================================================

    Markov.h
    Created: 27 Jul 2015 4:21:34pm
    Author:  Michael

	This class contains the stochastic matrices for chord and note transitions, 
	and functions to utilise their probability values to calculate the next chord & note.

  ==============================================================================
*/

#ifndef MARKOV_H_INCLUDED
#define MARKOV_H_INCLUDED

#include "../Logging.h"
#include <JuceHeader.h>

class Markov {
public:
	Markov();
	~Markov();

	int getNextNote(int currentNote);
	int getNextChord(int currentChord);

private:

	std::vector<std::vector<double>>* note;
	std::vector<std::vector<double>>* chord;
};


#endif  // MARKOV_H_INCLUDED
