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

class BrainController
{
public:
	BrainController();
	~BrainController();

	void setKeyTonic(int key);
	void clockTickFrequency(double currentFreq, bool isBeatTick);

private:

	SenseMaker mSenseMaker;
	double currentKeyTonic;

};



#endif  // BRAINCONTROLLER_H_INCLUDED
