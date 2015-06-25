/*
  ==============================================================================

    InputProcessor.h
    Created: 23 Jun 2015 3:24:42pm
    Author:  Michael

  ==============================================================================
*/

#ifndef INPUTPROCESSOR_H_INCLUDED
#define INPUTPROCESSOR_H_INCLUDED

#include "../Enums.h"

namespace juce{
	class MidiBuffer;
	class AudioSampleBuffer;
}

class InputProcessor {
public:
	InputProcessor();
	~InputProcessor();

	void SetBlock();
	void AnalyseBlock();
	Key_t GetKey();
	Chord_t GetChord();
	
private:

};

#endif  // INPUTPROCESSOR_H_INCLUDED
