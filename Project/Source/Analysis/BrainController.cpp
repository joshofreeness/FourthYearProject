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
	newChord = true;
	previousNotePlayed = 1;
}

BrainController::~BrainController(){}

double BrainController::clockTickFrequency(double currentFreq, bool isBeatTick, MidiBuffer& midiMessages)
{
	//Wait for the midi track to start so that chord doesn't get changed to something weird from background noise
	if (!trackStarted)
	{
		if (!isBeatTick){ return 0; }
		trackStarted = true;
	}

	int currentNote = mSenseMaker.frequencyToNoteInKey(currentFreq);
	notesHeardSinceLastChord.push_back(currentNote);

	int noteToPlay = 0;
	if (newChord)
	{
		newChord = false;
		noteToPlay = 1;
		previousNotePlayed = 1;
	}

	if (!doesNoteBelong(currentNote))
	{
		int newChord = pickNewChord(currentNote, currentChord);
	}

	noteToPlay = mMarkov.getNextNote(previousNotePlayed);
	previousNotePlayed = noteToPlay;

	

#ifdef WIN32
	LOG("The key is " + std::to_string(currentKeyTonic) + " The current note is " + std::to_string(currentNote) + " Is a beat " + std::to_string(isBeatTick));
#endif

	int noteInKey = convertNoteFromChordToKey(noteToPlay, currentChord);
	return mSenseMaker.noteInKeytoFrequency(noteInKey);
}

int BrainController::convertNoteFromChordToKey(int note, int chord)
{
	int noteInKey = note + chord - 1;
	
	return noteInKey % 8;
}

int BrainController::pickNewChord(int currentNote, int currentChordTransitionFrom)
{
	std::list<int> possibleChords = chordsNoteMayBelongTo(currentNote);
	int probableChord = mMarkov.getNextChord(currentChordTransitionFrom);
	//TODO: Implement
	return 1;
}


bool BrainController::doesNoteBelong(int note)
{
	//TODO: Implement
	return true;
}

std::list<int> BrainController::chordsNoteMayBelongTo(int note)
{
	//TODO: Implement
	return std::list<int>();
}

