/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (1450, 350);
    addAndMakeVisible(volumeKnob);
    addAndMakeVisible(test);
    addAndMakeVisible(controller);
    volumeKnob.setSliderStyle(Slider::SliderStyle::Rotary);
    volumeKnob.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
}

MainComponent::~MainComponent()
{
    
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    
    
}



void MainComponent::resized()
{
    
    test.setBounds(getLocalBounds());
    controller.setBounds(controller.getLocalBounds());
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
