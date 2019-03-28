/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "panels/ControllersPanel.h"
#include "panels/OscillatorBankPanel.h"
#include "panels/MixerPanel.h"
#include "panels/ModifiersPanel.h"
#include "panels/OutputPanel.h"
#include "panels/PowerPanel.h"
#include "buttons/RedFlipSwitch.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();
    

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    int sliderRad = 55;
    Slider volumeKnob;
    ControllersPanel controller;
    OscillatorBankPanel oscillatorBank;
    MixerPanel mixer;
    ModifiersPanel modifiers;
    OutputPanel     output;
    PowerPanel      power;
    
    RedFlipSwitch  OscillatorModulationToggle;
    RedFlipSwitch  FilterModulationToggle1;
    RedFlipSwitch  KeyboardControlToggle1;
    RedFlipSwitch  KeyboardControlToggle2;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
