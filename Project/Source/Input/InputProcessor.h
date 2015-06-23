/*
  ==============================================================================

    InputProcessor.h
    Created: 23 Jun 2015 3:24:42pm
    Author:  Michael

  ==============================================================================
*/

#ifndef INPUTPROCESSOR_H_INCLUDED
#define INPUTPROCESSOR_H_INCLUDED

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
	
private:

};

#endif  // INPUTPROCESSOR_H_INCLUDED
