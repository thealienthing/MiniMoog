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
        setSize(200, 350);
        width = 200;
        height = 350;
        tune.setSliderStyle(Slider::SliderStyle::Rotary);
        tune.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, false, 20, 5);
        glide.setSliderStyle(Slider::SliderStyle::Rotary);
        glide.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, false, 40, 10);
        modulationMix.setSliderStyle(Slider::SliderStyle::Rotary);
        modulationMix.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, false, 40, 10);
        
        addAndMakeVisible(tune);
        addAndMakeVisible(glide);
        addAndMakeVisible(modulationMix);
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
        g.setColour(Colours::firebrick);
        g.fillRect(area);
        g.setFont(Font(16.0f));
        g.setColour(Colours::black);
        g.drawText("Controllers Panel", area, Justification::centredBottom, true);
        
        g.setColour(Colours::white);
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
        bounds.removeFromLeft(section);
        bounds.removeFromRight(section);
        tune.setBounds(bounds);
    }

private:
    Rectangle<int> area;
    int height;
    int width;
    int knobBorder = 5;
    
    Slider tune;
    Slider glide;
    Slider modulationMix;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ControllersPanel)
};
