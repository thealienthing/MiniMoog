/*
  ==============================================================================

    OscillatorBankPanel.h
    Created: 21 Mar 2019 1:31:09pm
    Author:  Ben Stoneking

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../CustomLookAndFeel.h"

//==============================================================================
/*
*/
class OscillatorBankPanel    : public Component
{
public:
    OscillatorBankPanel()
    {
        setSize(width, height);
        setLookAndFeel(&customLook);
        
        addAndMakeVisible(range1);
        addAndMakeVisible(range2);
        addAndMakeVisible(range3);
        addAndMakeVisible(waveform1);
        addAndMakeVisible(waveform2);
        addAndMakeVisible(waveform3);
        addAndMakeVisible(oscillator2);
        addAndMakeVisible(oscillator3);
        
        range1.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        range2.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        range3.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        waveform1.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        waveform2.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        waveform3.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        oscillator2.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        oscillator3.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        
        
        range1.setSliderStyle(Slider::SliderStyle::Rotary);
        range2.setSliderStyle(Slider::SliderStyle::Rotary);
        range3.setSliderStyle(Slider::SliderStyle::Rotary);
        waveform1.setSliderStyle(Slider::SliderStyle::Rotary);
        waveform2.setSliderStyle(Slider::SliderStyle::Rotary);
        waveform3.setSliderStyle(Slider::SliderStyle::Rotary);
        oscillator2.setSliderStyle(Slider::SliderStyle::Rotary);
        oscillator3.setSliderStyle(Slider::SliderStyle::Rotary);
        
        knobFont.setTypefaceName("Futura");
        knobFont.setHeight(12.0f);
        panelFont.setTypefaceName("Futura");
        panelFont.setHeight(28.0f);
        panelFont.setExtraKerningFactor(0.1);
        
    }

    ~OscillatorBankPanel()
    {
    }

    void paint (Graphics& g) override
    {
        
        area = Rectangle<int>(0, 0, width, height);
        area.removeFromTop(area.getHeight()/3);
        g.setColour(Colours::white);
        g.fillRect(area);
        area = Rectangle<int>(0, 0, width, height);
        area.removeFromTop(height/3);
        area.removeFromBottom(height/3);
        g.setColour(Colours::pink);
        g.fillRect(area);
        area = Rectangle<int>(0, 0, width, height);
        g.setColour(Colours::black);
        g.fillRect(area);
        g.setColour(Colours::white);
        g.setFont(panelFont);
        area.removeFromTop(height/4 * 3);
        area.removeFromBottom(30);
        g.drawText("OSCILLATOR BANK", area, Justification::centredBottom, true);
        
        g.setFont(knobFont);
        area = Rectangle<int>(0, 0, width, height);
        area.removeFromRight(width/3*2);
        g.drawText("RANGE", area, Justification::centredTop, true);
        area = Rectangle<int>(0, 0, width, height);
        area.removeFromLeft(width/3*2);
        g.drawText("WAVEFORM", area, Justification::centredTop, true);
        
        area = Rectangle<int>(0, 0, width, height);
        area.removeFromLeft(width/3);
        area.removeFromRight(width/3);
        area.removeFromBottom(height*.75);
        area.setPosition(area.getX(), area.getY()+10);
        g.drawText("OSCILLATOR-1", area, Justification::centredTop, true);
        area.setPosition(area.getX(), area.getY()+(height*.28));
        g.drawText("OSCILLATOR-2", area, Justification::centredTop, true);
        area.setPosition(area.getX(), area.getY()+(height*.28));
        g.drawText("OSCILLATOR-3", area, Justification::centredTop, true);
        
        g.drawLine(0, 0, width, 0, lineThickness);
        g.drawLine(width, 0, width, height, lineThickness);
        g.drawLine(width, height, 0, height, lineThickness);
        g.drawLine(0, height, 0, 0, lineThickness);
        
    }

    void resized() override
    {
        area = Rectangle<int>(0, 0, width, height);
        area.removeFromRight(width*.75);
        area.removeFromLeft(15);
        area.removeFromBottom(height*.75);
        area.setPosition(area.getX()+22, area.getY()+18);
        range1.setBounds(area);
        area.setPosition(area.getX(), area.getY()+(height*.28));
        range2.setBounds(area);
        area.setPosition(area.getX(), area.getY()+(height*.28));
        range3.setBounds(area);
        
        area.setPosition(width*.3 * 2 +30, area.getY()-(height*.56));
        waveform1.setBounds(area);
        area.setPosition(area.getX(), area.getY() + (height*.28));
        waveform2.setBounds(area);
        area.setPosition(area.getX(), area.getY() + (height*.28));
        waveform3.setBounds(area);
        
        area.setPosition(width*.3 + 30, area.getY() - (height*.28));
        oscillator2.setBounds(area);
        area.setPosition(area.getX(), area.getY() + (height*.28));
        oscillator3.setBounds(area);

    }

private:
    Rectangle<int> area;
    CustomLookAndFeel customLook;
    
    Slider range1;
    Slider range2;
    Slider range3;
    Slider waveform1;
    Slider waveform2;
    Slider waveform3;
    Slider oscillator2;
    Slider oscillator3;
    
    float lineThickness = 3.0f;
    
    int height = 350;
    int width = 325;
    int knobBorder = 5;
    int leftKnobOffset = 10;
    
    Font panelFont;
    Font knobFont;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorBankPanel)
};
