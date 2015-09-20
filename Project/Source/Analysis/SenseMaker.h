/*
  ==============================================================================

    SenseMaker.h
    Created: 1 Sep 2015 2:01:56pm
    Author:  Joshua

	This class provides functions to convert between our internal note 
	representation and the raw frequency.

  ==============================================================================
*/

#ifndef SENSEMAKER_H_INCLUDED
#define SENSEMAKER_H_INCLUDED

#include "../Logging.h"
#include <math.h>

class SenseMaker
{
public:
	SenseMaker();
	~SenseMaker();

	double setKeyTonic(int key);
	int frequencyToNoteInKey(double freq);
	double noteInKeytoFrequency(int note);

private:
	
	double currentKeyTonic;
	double aValue = pow(2, 1.0 / 12.0);

};



#endif  // SENSEMAKER_H_INCLUDED
