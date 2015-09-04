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
#include "../Output/OutputController.h"

class BrainController
{
public:
	BrainController();
	~BrainController();

	
	void clockTickFrequency(double currentFreq, bool isBeatTick, MidiBuffer& midiMessages);

	void SetVolume(float volume){ m_volume = volume; };
	float GetVolume(void){ return m_volume; };

	void SetFrequency(float frequency) { m_frequency = frequency; };
	float GetFrequency(void){ return m_frequency; };

	void SetKey(int key);
	int GetKey(void){ return m_key; };

private:

	SenseMaker mSenseMaker;
	OutputController mOutputController;
	double currentKeyTonic;
	int currentChord;

	bool trackStarted;

	//Values for GUI
	float m_volume;
	float m_frequency;
	int m_key;

};



#endif  // BRAINCONTROLLER_H_INCLUDED
