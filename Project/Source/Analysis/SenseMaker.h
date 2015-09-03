/*
  ==============================================================================

    SenseMaker.h
    Created: 1 Sep 2015 2:01:56pm
    Author:  Joshua

  ==============================================================================
*/

#ifndef SENSEMAKER_H_INCLUDED
#define SENSEMAKER_H_INCLUDED

#include "../Logging.h"

class SenseMaker
{
public:
	SenseMaker();
	~SenseMaker();

	void clockTickFrequency(double freq, bool isBeat);
	void setKeyTonic(int key);

private:
	int frequencyToNoteInKey(double freq);
	double currentKeyTonic;

};



#endif  // SENSEMAKER_H_INCLUDED
