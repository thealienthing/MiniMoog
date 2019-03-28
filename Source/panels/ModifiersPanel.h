/*
  ==============================================================================

    ModifiersPanel.h
    Created: 21 Mar 2019 6:39:51pm
    Author:  Benjamin Stoneking

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../buttons/FlipSwitch.h"

//==============================================================================
/*
*/
class ModifiersPanel    : public Component
{
public:
    ModifiersPanel()
    {
        setSize(width, height);
        addAndMakeVisible(loudnessAttack);
        addAndMakeVisible(loudnessDecay);
        addAndMakeVisible(loudnessSustain);
        addAndMakeVisible(cutoff);
        addAndMakeVisible(emphasis);
        addAndMakeVisible(contour);
        addAndMakeVisible(filterAttack);
        addAndMakeVisible(filterSustain);
        addAndMakeVisible(filterDecay);
        
        loudnessAttack.setSliderStyle(Slider::SliderStyle::Rotary);
        loudnessAttack.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        loudnessDecay.setSliderStyle(Slider::SliderStyle::Rotary);
        loudnessDecay.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        loudnessSustain.setSliderStyle(Slider::SliderStyle::Rotary);
        loudnessSustain.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        
        cutoff.setSliderStyle(Slider::SliderStyle::Rotary);
        cutoff.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        emphasis.setSliderStyle(Slider::SliderStyle::Rotary);
        emphasis.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        contour.setSliderStyle(Slider::SliderStyle::Rotary);
        contour.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        filterAttack.setSliderStyle(Slider::SliderStyle::Rotary);
        filterAttack.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        filterSustain.setSliderStyle(Slider::SliderStyle::Rotary);
        filterSustain.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        filterDecay.setSliderStyle(Slider::SliderStyle::Rotary);
        filterDecay.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        
        knobFont.setTypefaceName("Futura");
        knobFont.setHeight(12.0f);
        panelFont.setTypefaceName("Futura");
        panelFont.setHeight(28.0f);

    }

    ~ModifiersPanel()
    {
    }

    void paint (Graphics& g) override
    {
        area = Rectangle<int>(0, 0, width, height);
        g.setColour(Colours::black);
        g.fillRect(area);
        g.setColour(Colours::white);
        g.setFont(panelFont);
        g.drawText("MODIFIERS", area, Justification::centredBottom, true);
        
        g.drawLine(0, 0, width, 0, lineThickness);
        g.drawLine(width, 0, width, height, lineThickness);
        g.drawLine(width, height, 0, height, lineThickness);
        g.drawLine(0, height, 0, 0, lineThickness);
        int offset = 30;
        area.removeFromTop(area.getHeight()/2 + offset);
        g.drawLine(0, height/2 + offset, width, height/2 + offset, lineThickness);
    }

    void resized() override
    {
        area = Rectangle<int>(0, 0, width, height);
        int offset = 30;
        area.removeFromTop(area.getHeight()/2 + offset);
        area.removeFromRight(area.getWidth()/3 * 2);
        loudnessAttack.setBounds(area);
        area.setPosition(area.getX() + area.getWidth(), area.getY());
        loudnessDecay.setBounds(area);
        area.setPosition(area.getX() + area.getWidth(), area.getY());
        loudnessSustain.setBounds(area);
        
        area = Rectangle<int>(0, 0, width, height);
        area.removeFromBottom(area.getHeight()/2 - offset);
        area.removeFromBottom(area.getHeight()/2);
        area.removeFromRight(area.getWidth()/3 * 2);
        cutoff.setBounds(area);
        area.setPosition(area.getX() + area.getWidth(), area.getY());
        emphasis.setBounds(area);
        area.setPosition(area.getX() + area.getWidth(), area.getY());
        contour.setBounds(area);
        area.setPosition(area.getX(), area.getY() + area.getHeight());
        filterAttack.setBounds(area);
        area.setPosition(area.getX() - area.getWidth(), area.getY());
        filterDecay.setBounds(area);
        area.setPosition(area.getX() - area.getWidth(), area.getY());
        filterSustain.setBounds(area);
    }

private:
    Rectangle<int> area;
    
    Slider loudnessAttack;
    Slider loudnessDecay;
    Slider loudnessSustain;
    
    Slider cutoff;
    Slider emphasis;
    Slider contour;
    Slider filterAttack;
    Slider filterDecay;
    Slider filterSustain;
    
    float lineThickness = 3.0f;
    
    int height = 350;
    int width = 325;
    int knobBorder = 5;
    int leftKnobOffset = 10;
    
    Font panelFont;
    Font knobFont;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModifiersPanel)
};
