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
    addAndMakeVisible(controller);
    addAndMakeVisible(oscillatorBank);
    addAndMakeVisible(mixer);
    addAndMakeVisible(modifiers);
    addAndMakeVisible(output);
    addAndMakeVisible(power);
    
    
    
    
    
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
    controller.setBounds(controller.getLocalBounds());
    oscillatorBank.setBounds(controller.getRight(), 0, oscillatorBank.getWidth(), oscillatorBank.getHeight());
    mixer.setBounds(oscillatorBank.getRight(), 0, mixer.getWidth(), mixer.getHeight());
    modifiers.setBounds(mixer.getRight(), 0, modifiers.getWidth(), modifiers.getHeight());
    output.setBounds(modifiers.getRight(), 0, output.getWidth(), output.getHeight());
    power.setBounds(output.getRight(), 0, power.getWidth(), power.getHeight());
    
}
