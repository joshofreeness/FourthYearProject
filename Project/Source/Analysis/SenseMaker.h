/*
  ==============================================================================

    SenseMaker.h
    Created: 1 Sep 2015 2:01:56pm
    Author:  Joshua

  ==============================================================================
*/

#ifndef SENSEMAKER_H_INCLUDED
#define SENSEMAKER_H_INCLUDED

class SenseMaker
{
public:
	SenseMaker();
	~SenseMaker();

	void clockTickFrequency(double freq, bool isBeat);

private:
	int frequencyToNoteInKey(double ferq);

};



#endif  // SENSEMAKER_H_INCLUDED
