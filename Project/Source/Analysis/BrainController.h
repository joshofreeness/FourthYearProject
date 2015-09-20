/*
  ==============================================================================

    BrainController.h
    Created: 4 Sep 2015 11:35:56am
    Author:  Joshua

	Controller class to abstract the use of the analysis classes (SenseMaker and Markov)
	away from PluginProcessor. Takes the frequency of the current note heard and returns
	the frequency of the next note to play.

  ==============================================================================
*/

#ifndef BRAINCONTROLLER_H_INCLUDED
#define BRAINCONTROLLER_H_INCLUDED
#include "SenseMaker.h"
#include "Markov.h"
#include <list>

class BrainController
{
public:
	BrainController();
	~BrainController();

	double clockTickFrequency(double currentFreq, bool isBeatTick, MidiBuffer& midiMessages);

	void SetVolume(float newVolume){ volume = newVolume; };
	float GetVolume(void){ return volume; };

	void SetBeat(int newBeat) { beat = newBeat; beatSkip = newBeat - 1; if (newBeat == 3){ beatSkip++; } };
	int GetBeat(void){ return beat; };
	/* Beats:
				1/16: 1
				1/8: 2
				1/4: 3
			*/

	void SetKey(int newKey){ key = newKey; currentKeyTonic = mSenseMaker.setKeyTonic(key); };
	int GetKey(void){ return key; };

private:

	SenseMaker mSenseMaker;
	Markov mMarkov;
	std::list<int> notesHeardSinceLastChord;

	bool doesNoteBelong(int note);
	std::list<int> chordsNoteMayBelongTo(int note);
	int convertNoteFromChordToKey(int note, int chord);
	int convertNoteFromKeyToChord(int note, int chord);
	int pickNewChord(int currentNote, int currentChord);

	double currentKeyTonic;
	int currentChord;
	int previousNotePlayed;
	bool newChord;

	int beatCounter;
	int beatSkip;

	bool trackStarted;

	// Values from GUI
	float volume;
	int key;
	int beat;
};



#endif  // BRAINCONTROLLER_H_INCLUDED
