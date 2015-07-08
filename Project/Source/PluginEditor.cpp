/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DAWTestAudioProcessorEditor::DAWTestAudioProcessorEditor (DAWTestAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (sliderVolume = new Slider ("sliderVolume"));
    sliderVolume->setRange (0, 1, 0.01);
    sliderVolume->setSliderStyle (Slider::LinearHorizontal);
    sliderVolume->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    sliderVolume->addListener (this);

    addAndMakeVisible (lblVolume = new Label ("lblVolume",
                                              TRANS("Volume")));
    lblVolume->setFont (Font ("Avenir Next LT Pro", 20.00f, Font::bold));
    lblVolume->setJustificationType (Justification::centredLeft);
    lblVolume->setEditable (false, false, false);
    lblVolume->setColour (Label::textColourId, Colours::lightgrey);
    lblVolume->setColour (TextEditor::textColourId, Colours::black);
    lblVolume->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (sliderFrequency = new Slider ("sliderFrequency"));
    sliderFrequency->setRange (15, 1200, 1);
    sliderFrequency->setSliderStyle (Slider::LinearHorizontal);
    sliderFrequency->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    sliderFrequency->addListener (this);

    addAndMakeVisible (lblFrequency = new Label ("lblFrequency",
                                                 TRANS("Frequency")));
    lblFrequency->setFont (Font ("Avenir Next LT Pro", 20.00f, Font::bold));
    lblFrequency->setJustificationType (Justification::centredLeft);
    lblFrequency->setEditable (false, false, false);
    lblFrequency->setColour (Label::textColourId, Colours::lightgrey);
    lblFrequency->setColour (TextEditor::textColourId, Colours::black);
    lblFrequency->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
	sliderFrequency->setValue(450);
	sliderVolume->setValue(1);
    //[/UserPreSize]

    setSize (600, 200);


    //[Constructor] You can add your own custom stuff here..
	getProcessor()->RequestUIUpdate();// UI update must be done each time a new editor is constructed
    startTimer(200); //starts timer with interval of 200mS
    //[/Constructor]
}

DAWTestAudioProcessorEditor::~DAWTestAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderVolume = nullptr;
    lblVolume = nullptr;
    sliderFrequency = nullptr;
    lblFrequency = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DAWTestAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff514f4f));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DAWTestAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sliderVolume->setBounds (20, 49, 560, 40);
    lblVolume->setBounds (20, 25, 150, 24);
    sliderFrequency->setBounds (16, 136, 560, 40);
    lblFrequency->setBounds (20, 108, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DAWTestAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    DAWTestAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderVolume)
    {
        //[UserSliderCode_sliderVolume] -- add your slider handling code here..
        ourProcessor->setParameter(DAWTestAudioProcessor::Volume, (float)sliderVolume->getValue());
        //[/UserSliderCode_sliderVolume]
    }
    else if (sliderThatWasMoved == sliderFrequency)
    {
        //[UserSliderCode_sliderFrequency] -- add your slider handling code here..
		ourProcessor->setParameter(DAWTestAudioProcessor::Frequency, (float)sliderFrequency->getValue() / 1200);
        //[/UserSliderCode_sliderFrequency]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void DAWTestAudioProcessorEditor::timerCallback() {
	DAWTestAudioProcessor* ourProcessor = getProcessor();
    //exchange any data you want between UI elements and the Plugin "ourProcessor"
    if(ourProcessor->NeedsUIUpdate()) {
        sliderVolume->setValue(ourProcessor->getParameter(DAWTestAudioProcessor::Volume), dontSendNotification);
        ourProcessor->ClearUIUpdateFlag();
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DAWTestAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="DAWTestAudioProcessor&amp; ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="200">
  <BACKGROUND backgroundColour="ff514f4f"/>
  <SLIDER name="sliderVolume" id="d834204f246a0f88" memberName="sliderVolume"
          virtualName="" explicitFocusOrder="0" pos="20 49 560 40" min="0"
          max="1" int="0.01" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="lblVolume" id="e3981c189293ff08" memberName="lblVolume"
         virtualName="" explicitFocusOrder="0" pos="20 25 150 24" textCol="ffd3d3d3"
         edTextCol="ff000000" edBkgCol="0" labelText="Volume" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Avenir Next LT Pro"
         fontsize="20" bold="1" italic="0" justification="33"/>
  <SLIDER name="sliderFrequency" id="e42b5e5b430a6417" memberName="sliderFrequency"
          virtualName="" explicitFocusOrder="0" pos="16 136 560 40" min="15"
          max="1200" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="lblFrequency" id="711836deab664bff" memberName="lblFrequency"
         virtualName="" explicitFocusOrder="0" pos="20 108 150 24" textCol="ffd3d3d3"
         edTextCol="ff000000" edBkgCol="0" labelText="Frequency" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Avenir Next LT Pro"
         fontsize="20" bold="1" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
