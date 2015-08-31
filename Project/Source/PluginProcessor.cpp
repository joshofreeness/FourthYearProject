/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <cstdint>
#include "./Logging.h"

//==============================================================================
DAWTestAudioProcessor::DAWTestAudioProcessor()
{
	UserParams[Volume] = 1.0f; //default volume 1.0 (no change)
	mOutputController.SetVolume(UserParams[Volume]); //push VST default to effect
	UserParams[Frequency] = (1 / 3); //default frequency 500Hz (no change)
	mOutputController.SetFrequency(UserParams[Frequency]); //push VST default to effect
	UserParams[Key] = 1; //default frequency 500Hz (no change)
	mOutputController.SetKey(UserParams[Key]); //push VST default to effect
    UIUpdateFlag=true; //Request UI update
}

DAWTestAudioProcessor::~DAWTestAudioProcessor()
{
}

int DAWTestAudioProcessor::getNumParameters(){ return totalNumParam; }

float DAWTestAudioProcessor::getParameter (int index) {
	switch (index) {
		case Volume://example update from internal
			UserParams[Volume] = mOutputController.GetVolume();
			return UserParams[Volume];
		case Frequency://example update from internal
			UserParams[Frequency] = mOutputController.GetFrequency();
			return UserParams[Frequency];
		case Key://example update from internal
			UserParams[Key] = mOutputController.GetKey();
			return UserParams[Key];
        default: return 0.0f;//invalid index
    }
}

void DAWTestAudioProcessor::setParameter (int index, float newValue) {
	switch (index) {
		case Volume:
			UserParams[Volume] = newValue;
			mOutputController.SetVolume(UserParams[Volume]);
			break;
		case Frequency:
			UserParams[Frequency] = newValue;
			mOutputController.SetFrequency(UserParams[Frequency] * 1200); //Convert from parameter to Hz value.
			break;
		case Key:
			UserParams[Key] = newValue;
			mOutputController.SetKey((int)newValue);
			/* Keys:
			    Key of C: 1
				Key of Db / C#: 2
				Key of D: 3
				Key of Eb / D#: 4
				Key of E: 5
				Key of F: 6
				Key of Gb / Key of F#: 7
				Key of G: 8
				Key of Ab / G#: 9
				Key of A: 10
				Key of Bb / A#: 11
				Key of B / Key of Cb: 12
			*/
			break;
		default: return;
    }
    UIUpdateFlag=true;//Request UI update -- Some OSX hosts use alternate editors, this updates ours
}

const String DAWTestAudioProcessor::getParameterName (int index) {
	switch (index) {
		case Volume: return "Volume";
		case Frequency: return "Frequency";
		case Key: return "Key";
        default:return String::empty;
    }
}

const String DAWTestAudioProcessor::getParameterText (int index) {
    if(index>=0 && index<totalNumParam)
        return String(UserParams[index]);//return parameter value as string
    else return String::empty;
}

//This is where all the audio processing happens
void DAWTestAudioProcessor::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages) {
	if(getNumInputChannels()<2) {
        //Nothing to do here - processing is in-place, so doing nothing is pass-through (for NumInputs=NumOutputs) 
    } else {
        //Do processing!
		mOutputController.ClockProcess(midiMessages);

		mInputProcessor.SetBlock(buffer);
		mInputProcessor.SetSampleRate(getSampleRate());
		mInputProcessor.AnalyseBlock();
		float currentFreq = mInputProcessor.GetFrequency();

		float note = currentFreq;
		//float note = mNoteAnalyser.getNote();
		//TODO: Uncomment this when it returns a real frequency value and not just 0
		
		mOutputController.PlayNote(note, midiMessages, 0);

		if (hasEditor())
		{
			//DAWTestAudioProcessorEditor *theOne = getActiveEditor();
			AudioProcessorEditor *temp = getActiveEditor();
			//TODO: get a reference to the editor and call UpdateGUILabel  
			//temp->UpdateGUILable("Haha");
			//DAWTestAudioProcessorEditor *tempDaw = static_cast<DAWTestAudioProcessorEditor>(*temp);
		}
    }
}

//Save UserParams/Data to file
void DAWTestAudioProcessor::getStateInformation (MemoryBlock& destData) {
    XmlElement root("Root");
	XmlElement *el;
	el = root.createNewChildElement("Volume");
	el->addTextElement(String(UserParams[Volume]));
	el = root.createNewChildElement("Frequency");
	el->addTextElement(String(UserParams[Frequency]));
	el = root.createNewChildElement("Key");
	el->addTextElement(String(UserParams[Key]));
    copyXmlToBinary(root,destData);
}
 
//Load UserParams/Data from file
void DAWTestAudioProcessor::setStateInformation (const void* data, int sizeInBytes) {
    XmlElement* pRoot = getXmlFromBinary(data,sizeInBytes);
    
    if(pRoot!=NULL) {
		forEachXmlChildElement((*pRoot), pChild) {
			if (pChild->hasTagName("Volume")) {
				String text = pChild->getAllSubText();
				setParameter(Volume, text.getFloatValue());
			} else if (pChild->hasTagName("Frequency")) {
				String text = pChild->getAllSubText();
				setParameter(Frequency, text.getFloatValue());
			} else if (pChild->hasTagName("Key")) {
				String text = pChild->getAllSubText();
				setParameter(Key, text.getFloatValue());
			}
        }
        delete pRoot;
        UIUpdateFlag=true;//Request UI update
    }
}

//==============================================================================
const String DAWTestAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

const String DAWTestAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String DAWTestAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool DAWTestAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool DAWTestAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool DAWTestAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DAWTestAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DAWTestAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double DAWTestAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DAWTestAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DAWTestAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DAWTestAudioProcessor::setCurrentProgram (int index)
{
}

const String DAWTestAudioProcessor::getProgramName (int index)
{
    return String();
}

void DAWTestAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void DAWTestAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void DAWTestAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

//==============================================================================
bool DAWTestAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* DAWTestAudioProcessor::createEditor()
{
    return new DAWTestAudioProcessorEditor (*this);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DAWTestAudioProcessor();
}
