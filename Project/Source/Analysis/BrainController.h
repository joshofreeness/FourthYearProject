/*
  ==============================================================================

    BrainController.h
    Created: 4 Sep 2015 11:35:56am
    Author:  Joshua

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

	void SetFrequency(float newFrequency) { frequency = newFrequency; };
	float GetFrequency(void){ return frequency; };

	void SetKey(int newKey){ key = newKey; currentKeyTonic = mSenseMaker.setKeyTonic(key); };
	int GetKey(void){ return key; };

private:

	SenseMaker mSenseMaker;
	Markov mMarkov;
	std::list<int> notesHeardSinceLastChord;

	bool doesNoteBelong(int note);
	std::list<int> chordsNoteMayBelongTo(int note);
	int convertNoteFromChordToKey(int note, int chord);
	int pickNewChord(int currentNote, int currentChord);

	double currentKeyTonic;
	int currentChord;
	int previousNotePlayed;
	bool newChord;

	bool trackStarted;

	//Values for GUI
	float volume;
	float frequency;
	int key;

};



#endif  // BRAINCONTROLLER_H_INCLUDED
