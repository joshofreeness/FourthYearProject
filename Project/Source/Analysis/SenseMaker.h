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

	double setKeyTonic(int key);
	int frequencyToNoteInKey(double freq);

private:
	
	double currentKeyTonic;

};



#endif  // SENSEMAKER_H_INCLUDED
