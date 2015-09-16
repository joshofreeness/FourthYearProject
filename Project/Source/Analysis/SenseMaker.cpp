/*
  ==============================================================================

    SenseMaker.cpp
    Created: 1 Sep 2015 2:01:56pm
    Author:  Joshua

  ==============================================================================
*/

#include "SenseMaker.h"
#include <string>

SenseMaker::SenseMaker(){}

SenseMaker::~SenseMaker(){}



double SenseMaker::setKeyTonic(int key)
{
	switch (key)
	{
	case 0:
		//No Key selected
		currentKeyTonic = 0;
		return currentKeyTonic;
	case 1:
		//Key of C : 1
		currentKeyTonic = 261.63;
		return currentKeyTonic;
	case 2:
		//Key of Db / C#: 2
		currentKeyTonic = 277.18;
		return currentKeyTonic;
	case 3:
		//Key of D: 3
		currentKeyTonic = 293.66;
		return currentKeyTonic;
	case 4:
		//Key of Eb / D#: 4
		currentKeyTonic = 311.13;
		return currentKeyTonic;
	case 5:
		//Key of E: 5
		currentKeyTonic = 329.63;
		return currentKeyTonic;
	case 6:
		//Key of F: 6
		currentKeyTonic = 349.23;
		return currentKeyTonic;
	case 7:
		//Key of Gb / Key of F#: 7
		currentKeyTonic = 369.99;
		return currentKeyTonic;
	case 8:
		//Key of G: 8
		currentKeyTonic = 392;
		return currentKeyTonic;
	case 9:
		//Key of Ab / G#: 9
		currentKeyTonic = 415.3;
		return currentKeyTonic;
	case 10:
		//Key of A: 10
		currentKeyTonic = 440;
		return currentKeyTonic;
	case 11:
		//Key of Bb / A#: 11
		currentKeyTonic = 466.16;
		return currentKeyTonic;
	case 12:
		//Key of B / Key of Cb: 12
		currentKeyTonic = 493.88;
		return currentKeyTonic;
	default:
		//Unknown key selected
		currentKeyTonic = 0;
		return currentKeyTonic;
	}
}


int SenseMaker::frequencyToNoteInKey(double freq)
{
	/*
		fn = f0 * (a)n 
		where
		f0 = the frequency of one fixed note which must be defined. A common choice is setting the A above middle C (A4) at f0 = 440 Hz.
		n = the number of half steps away from the fixed note you are. If you are at a higher note, n is positive. If you are on a lower note, n is negative.
		fn = the frequency of the note n half steps away.
		a = (2)1/12 = the twelth root of 2 = the number which when multiplied by itself 12 times equals 2 = 1.059463094359...
		http://www.phy.mtu.edu/~suits/NoteFreqCalcs.html
	*/
	if (freq == currentKeyTonic){return 1;} 
	
	int currentSteps = 0;

	if (freq > currentKeyTonic)
	{
		double multiplier = aValue;

		while ((currentKeyTonic * multiplier) < freq )
		{
			currentSteps++;
			multiplier *= aValue;
		}
		currentSteps = currentSteps % 12;
	}
	else
	{
		double multiplier = aValue;
		while ((currentKeyTonic * multiplier) < freq)
		{
			currentSteps--;
			multiplier *= 1/aValue;
		}
		currentSteps = currentSteps % -12;
		currentSteps = currentSteps + 12;
	}

	//It is in the scale if it is 0, 2, 4, 5, 7, 9, 11, 12(0)
	switch (currentSteps)
	{
		case 0:
			return 1;
		case 2:
			return 2;
		case 4:
			return 3;
		case 5:
			return 4;
		case 7:
			return 5;
		case 9:
			return 6;
		case 11:
			return 7;
		default:
			//Note: not in scale if return 0
			return 0;
	}

}

double SenseMaker::noteInKeytoFrequency(int note)
{
	int numSteps = 0;

	// Convert from note id back to number of semitones from the tonic freq.
	switch (note)
	{
	case 1:
		numSteps = 0;
		break;

	case 2:
		numSteps = 2;
		break;

	case 3:
		numSteps = 4;
		break;

	case 4:
		numSteps = 5;
		break;

	case 5:
		numSteps = 7;
		break;

	case 6:
		numSteps = 9;
		break;

	case 7:
		numSteps = 11;
		break;

	case 8:
		numSteps = 0;
		break;

	default:
		//Note: not in scale if return 0
		return 0;
	}

	// fn = f0 * (a^n)
	// http://www.phy.mtu.edu/~suits/NoteFreqCalcs.html
	double frequency = currentKeyTonic * (pow(aValue, numSteps));

	return frequency;
}


