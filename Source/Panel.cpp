/*
  ==============================================================================

    Panel.cpp
    Created: 18 Mar 2019 4:30:17pm
    Author:  Ben Stoneking

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Panel.h"

//==============================================================================

Panel::Panel()
{
    setSize (1450, 350);
}


Panel::~Panel()
{
}

void Panel::paint (Graphics& g)
{
    //controllers = Rectangle<int>(0, 0, 200, 350);
    oscillatorBank = Rectangle<int>(200, 0, 325, 350);
    mixer = Rectangle<int>(525, 0, 375, 350);
    modifiers = Rectangle<int>(900, 0, 325, 350);
    output = Rectangle<int>(1225, 0, 150, 350);
    power = Rectangle<int>(1375, 0, 75, 350);
    
    g.setColour(Colours::purple);
    //g.fillRect(controllers);
    g.fillRect(oscillatorBank);
    g.fillRect(mixer);
    g.fillRect(modifiers);
    g.fillRect(output);
    g.fillRect(power);
    
    g.setFont (Font (16.0f));
    g.setColour (Colours::black);
    
    //g.drawText ("Controllers", controllers, Justification::centredBottom, true);
    g.drawText ("Oscillator Bank", oscillatorBank, Justification::centredBottom, true);
    g.drawText ("Mixer", mixer, Justification::centredBottom, true);
    g.drawText ("Modifiers", modifiers, Justification::centredBottom, true);
    g.drawText ("Output", output, Justification::centredBottom, true);
    g.drawText ("Power", power, Justification::centredBottom, true);
    
    //g.drawLine(200, 0, 200, 350, 3.0);
    g.drawLine(525, 0, 525, 350, 3.0);
    g.drawLine(900, 0, 900, 350, 3.0);
    g.drawLine(1225, 0, 1225, 350, 3.0);
    g.drawLine(1375, 0, 1375, 350, 3.0);
}

void Panel::resized()
{
    
}
