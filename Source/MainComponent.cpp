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
    addAndMakeVisible(OscillatorModulationToggle);
    addAndMakeVisible(FilterModulationToggle1);
    addAndMakeVisible(KeyboardControlToggle1);
    addAndMakeVisible(KeyboardControlToggle2);
    
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
    
    Rectangle<int> switchBox(controller.getRight()-35, controller.getHeight()/3 -30, 70, 27);
    OscillatorModulationToggle.setBounds(switchBox);
    switchBox = Rectangle<int> (mixer.getRight() - 35, mixer.getHeight() * .165 -12, 70, 27);
    FilterModulationToggle1.setBounds(switchBox);
    switchBox.setPosition(switchBox.getX(), switchBox.getY() + mixer.getHeight() * .165);
    KeyboardControlToggle1.setBounds(switchBox);
    switchBox.setPosition(switchBox.getX(), switchBox.getY() + mixer.getHeight() * .165);
    KeyboardControlToggle2.setBounds(switchBox);
}
