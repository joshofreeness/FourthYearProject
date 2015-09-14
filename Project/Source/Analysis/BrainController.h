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

class BrainController
{
public:
	BrainController();
	~BrainController();

	
	void clockTickFrequency(double currentFreq, bool isBeatTick, MidiBuffer& midiMessages);

	void SetVolume(float newVolume){ volume = newVolume; };
	float GetVolume(void){ return volume; };

	void SetFrequency(float newFrequency) { frequency = newFrequency; };
	float GetFrequency(void){ return frequency; };

	void SetKey(int newKey){ key = newKey; currentKeyTonic = mSenseMaker.setKeyTonic(key); };
	int GetKey(void){ return key; };

private:

	SenseMaker mSenseMaker;
	Markov mMarkov;
	double currentKeyTonic;
	int currentChord;

	bool trackStarted;

	//Values for GUI
	float volume;
	float frequency;
	int key;

};



#endif  // BRAINCONTROLLER_H_INCLUDED
