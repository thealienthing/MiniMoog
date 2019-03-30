/*
  ==============================================================================

    ControllersPanel(2).h
    Created: 20 Mar 2019 4:01:10pm
    Author:  Ben Stoneking

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../CustomLookAndFeel.h"

//==============================================================================
/*
*/
class ControllersPanel    : public Component
{
public:
    ControllersPanel()
    {
        setSize(width, height);
        setLookAndFeel(&customLook);
        
        tune.setSliderStyle(Slider::SliderStyle::Rotary);
        tune.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        glide.setSliderStyle(Slider::SliderStyle::Rotary);
        glide.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        modulationMix.setSliderStyle(Slider::SliderStyle::Rotary);
        modulationMix.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        
        knobFont.setTypefaceName("Futura");
        knobFont.setHeight(12.0f);
        panelFont.setTypefaceName("Futura");
        panelFont.setHeight(28.0f);
        panelFont.setExtraKerningFactor(0.075);
        
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
        area = Rectangle<int>(0, 0, width, height);
        g.setColour(Colours::black);
        g.fillRect(area);
        
        g.setFont(panelFont);
        g.setColour(Colours::white);
        area.removeFromTop(height/4 * 3);
        area.removeFromBottom(30);
        g.drawText("CONTROLLERS", area, Justification::centredBottom, true);
        g.setFont(knobFont);
        g.drawText("TUNE", width/2 - 20, tune.getY()+50, 40, 10, Justification::centred);
        g.drawText("GLIDE", width/3 - 38, glide.getY()+90, 40, 10, Justification::centred);
        g.drawText("MODULATION MIX", width/3*2 - 30, modulationMix.getY()+90, 100, 10, Justification::centred);
        
        g.drawLine(0, 0, width, 0, lineThickness);
        g.drawLine(width, 0, width, height, lineThickness);
        g.drawLine(width, height, 0, height, lineThickness);
        g.drawLine(0, height, 0, 0, lineThickness);
        
    }
    
    Slider* getTune()
    {
        return &tune;
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
    CustomLookAndFeel customLook;
    
    float lineThickness = 3.0;
    
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
