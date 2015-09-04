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
}

BrainController::~BrainController(){}

void BrainController::setKeyTonic(int key)
{
	currentKeyTonic = mSenseMaker.setKeyTonic(key);
}

void BrainController::clockTickFrequency(double currentFreq, bool isBeatTick)
{
	int currentNote = mSenseMaker.frequencyToNoteInKey(currentFreq);
#ifdef WIN32
	LOG("The key is " + std::to_string(currentKeyTonic) + " The current note is " + std::to_string(currentNote) + " Is a beat " + std::to_string(isBeatTick));
#endif
}



