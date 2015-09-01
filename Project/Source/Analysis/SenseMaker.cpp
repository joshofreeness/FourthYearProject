/*
  ==============================================================================

    SenseMaker.cpp
    Created: 1 Sep 2015 2:01:56pm
    Author:  Joshua

  ==============================================================================
*/

#include "SenseMaker.h"

SenseMaker::SenseMaker(){}

SenseMaker::~SenseMaker(){}



void SenseMaker::clockTickFrequency(double freq, bool isBeat)
{
	return;
}

void SenseMaker::setKeyTonic(int key)
{
	switch (key)
	{
	case 0:
		//No Key selected
		currentKeyTonic = 0;
	case 1:
		//Key of C : 1
		currentKeyTonic = 261.63;
	case 2:
		//Key of Db / C#: 2
		currentKeyTonic = 277.18;
	case 3:
		//Key of D: 3
		currentKeyTonic = 293.66;
	case 4:
		//Key of Eb / D#: 4
		currentKeyTonic = 311.13;
	case 5:
		//Key of E: 5
		currentKeyTonic = 329.63;
	case 6:
		//Key of F: 6
		currentKeyTonic = 349.23;
	case 7:
		//Key of Gb / Key of F#: 7
		currentKeyTonic = 369.99;
	case 8:
		//Key of G: 8
		currentKeyTonic = 392;
	case 9:
		//Key of Ab / G#: 9
		currentKeyTonic = 415.3;
	case 10:
		//Key of A: 10
		currentKeyTonic = 440;
	case 11:
		//Key of Bb / A#: 11
		currentKeyTonic = 466.16;
	case 12:
		//Key of B / Key of Cb: 12
		currentKeyTonic = 493.88;
	default:
		//Unknown key selected
		currentKeyTonic = 0;
	}
}


int SenseMaker::frequencyToNoteInKey(double freq)
{
	return 0;
}



