/*
  ==============================================================================

    Panel.h
    Created: 18 Mar 2019 4:30:17pm
    Author:  Ben Stoneking

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
*/
class Panel    : public Component
{
public:
    Panel();

    ~Panel();
    
    Rectangle<int> bounds;

    void paint (Graphics&) override;
    void resized() override;

private:
    //Rectangle<int> controllers;
    //Rectangle<int> oscillatorBank;
    //Rectangle<int> mixer;
    Rectangle<int> modifiers;
    Rectangle<int> output;
    Rectangle<int> power;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Panel)
};

/*
 Rectangle<int> controllers(0, 0, 200, 350);
 Rectangle<int> oscillatorBank(200, 0, 325, 350);
 Rectangle<int> mixer(525, 0, 375, 350);
 Rectangle<int> modifiers(900, 0, 325, 350);
 Rectangle<int> output(1225, 0, 150, 350);
 Rectangle<int> power(1375, 0, 75, 350);
 
 g.setColour(Colours::bisque);
 g.fillRect(controllers);
 g.fillRect(oscillatorBank);
 g.fillRect(mixer);
 g.fillRect(modifiers);
 g.fillRect(output);
 g.fillRect(power);
 
 g.setFont (Font (16.0f));
 g.setColour (Colours::black);
 
 g.drawText ("Controllers", controllers, Justification::centredBottom, true);
 g.drawText ("Oscillator Bank", oscillatorBank, Justification::centredBottom, true);
 g.drawText ("Mixer", mixer, Justification::centredBottom, true);
 g.drawText ("Modifiers", modifiers, Justification::centredBottom, true);
 g.drawText ("Output", output, Justification::centredBottom, true);
 g.drawText ("Power", power, Justification::centredBottom, true);
 
 g.drawLine(200, 0, 200, 350, 3.0);
 g.drawLine(525, 0, 525, 350, 3.0);
 g.drawLine(900, 0, 900, 350, 3.0);
 g.drawLine(1225, 0, 1225, 350, 3.0);
 g.drawLine(1375, 0, 1375, 350, 3.0);
*/
