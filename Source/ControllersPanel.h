/*
  ==============================================================================

    ControllersPanel(2).h
    Created: 20 Mar 2019 4:01:10pm
    Author:  Ben Stoneking

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class ControllersPanel    : public Component
{
public:
    ControllersPanel()
    {
        setSize(width, height);
        
        tune.setSliderStyle(Slider::SliderStyle::Rotary);
        tune.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        glide.setSliderStyle(Slider::SliderStyle::Rotary);
        glide.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        modulationMix.setSliderStyle(Slider::SliderStyle::Rotary);
        modulationMix.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        
        knobFont.setTypefaceName("Futura");
        knobFont.setHeight(16.0f);
        panelFont.setTypefaceName("Futura");
        panelFont.setHeight(16.0f);
        
        addAndMakeVisible(tune);
        addAndMakeVisible(glide);
        addAndMakeVisible(modulationMix);
        
        addAndMakeVisible(glideLabel);
        addAndMakeVisible(modMixLabel);
    }

    ~ControllersPanel()
    {
    }
    
    Rectangle<int> getArea()
    {
        return area;
    }

    void paint (Graphics& g) override
    {
        area = Rectangle<int>(0, 0, 200, 350);
        g.setColour(Colours::black);
        g.fillRect(area);
        
        g.setFont(panelFont);
        g.setColour(Colours::white);
        g.drawText("CONTROLLERS", area, Justification::centredBottom, true);
        
        g.drawText("TUNE", (, tune.getY()+50, 40, 10, Justification::horizontallyCentred);
        
        g.drawLine(0, 0, width, 0);
        g.drawLine(width, 0, width, height);
        g.drawLine(width, height, 0, height);
        g.drawLine(0, height, 0, 0);
        
    }

    void resized() override
    {
        Rectangle<int> bounds = getLocalBounds();
        glide.setBounds         (bounds.removeFromLeft(bounds.getWidth()/2-knobBorder).removeFromBottom(bounds.getHeight()*4/5));
        
        bounds = getLocalBounds();
        modulationMix.setBounds (bounds.removeFromRight(bounds.getWidth()/2-knobBorder).removeFromBottom(bounds.getHeight()*4/5));
        
        bounds = getLocalBounds();
        bounds.removeFromBottom(bounds.getHeight()*2/5);
        int section = bounds.getWidth()/4;
        bounds.removeFromRight(section);
        bounds.removeFromLeft(section);
        tune.setBounds(bounds);
        
    }

private:
    Rectangle<int> area;
    int height = 350;
    int width = 200;
    int knobBorder = 5;
    
    Font panelFont;
    Font knobFont;
    
    Slider tune;
    Slider glide;
    Slider modulationMix;
    
    Label glideLabel;
    Label modMixLabel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ControllersPanel)
};
