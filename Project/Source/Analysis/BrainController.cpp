/*
  ==============================================================================

    BrainController.cpp
    Created: 4 Sep 2015 11:35:56am
    Author:  Joshua

  ==============================================================================
*/

#include "BrainController.h"

BrainController::BrainController()
{
	currentKeyTonic = 0;
	currentChord = 1; //This will probably be the case at the start most of the time
	trackStarted = false;
}

BrainController::~BrainController(){}

void BrainController::clockTickFrequency(double currentFreq, bool isBeatTick, MidiBuffer& midiMessages)
{
	//Wait for the midi track to start so that chord doesn't get changed to something weird from background noise
	if (!trackStarted)
	{
		if (!isBeatTick){ return; }
		trackStarted = true;
	}

	int currentNote = mSenseMaker.frequencyToNoteInKey(currentFreq);
	int chord = 0;

	double freqToPlay = mMarkov.getNextNote(currentNote);

	// I thought brainController is meant to pass freqToPlay back to PluginProcessor, and then PluginProcessor calls OutputController?
	//mOutputController.PlayNote(freqToPlay, midiMessages, 0); 
	//TODO: change this to accept the int note and outputcontroller handles conversion
	// pretty sure we should keep the int stuff contained within the brain classes, convert back to frequency before passing back to pluginprocessor and outputcontroller

#ifdef WIN32
	LOG("The key is " + std::to_string(currentKeyTonic) + " The current note is " + std::to_string(currentNote) + " Is a beat " + std::to_string(isBeatTick));
#endif
}



