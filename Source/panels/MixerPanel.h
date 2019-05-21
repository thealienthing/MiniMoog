/*
  ==============================================================================

    MixerPanel.h
    Created: 21 Mar 2019 2:04:18pm
    Author:  Ben Stoneking

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../buttons/FlipSwitch.h"
#include "../MoogDefaultKnob.h"
#include <stdio.h>

//==============================================================================
/*
*/
class MixerPanel    : public Component
{
public:
    MixerPanel()
    {
        setSize(width, height);
    
        addAndMakeVisible(volume1);
        addAndMakeVisible(volume2);
        addAndMakeVisible(volume3);
        addAndMakeVisible(extInputVolume);
        addAndMakeVisible(noiseVolume);
        addAndMakeVisible(volumeToggle1);
        addAndMakeVisible(volumeToggle2);
        addAndMakeVisible(volumeToggle3);
        addAndMakeVisible(extInputVolumeToggle);
        addAndMakeVisible(noiseVolumeToggle);
        setLookAndFeel(&customLook);
        
        volume1.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        volume2.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        volume3.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        extInputVolume.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        noiseVolume.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
        
        volume1.setSliderStyle(Slider::SliderStyle::Rotary);
        volume2.setSliderStyle(Slider::SliderStyle::Rotary);
        volume3.setSliderStyle(Slider::SliderStyle::Rotary);
        extInputVolume.setSliderStyle(Slider::SliderStyle::Rotary);
        noiseVolume.setSliderStyle(Slider::SliderStyle::Rotary);
        
        volumeToggle1.setSwitchColour("blue");
        volumeToggle2.setSwitchColour("blue");
        volumeToggle3.setSwitchColour("blue");
        extInputVolumeToggle.setSwitchColour("blue");
        noiseVolumeToggle.setSwitchColour("blue");
        
        
        knobFont.setTypefaceName("Futura");
        knobFont.setHeight(12.0f);
        panelFont.setTypefaceName("Futura");
        panelFont.setHeight(28.0f);
        panelFont.setExtraKerningFactor(0.075);
        
    }

    ~MixerPanel()
    {
    }

    void paint (Graphics& g) override
    {
        area = Rectangle<int>(0, 0, width, height);
        g.setColour(Colours::black);
        g.fillRect(area);
        g.setColour(Colours::white);
        g.setFont(panelFont);
        area.removeFromTop(height/4 * 3);
        area.removeFromBottom(30);
        g.drawText("MIXER", area, Justification::centredBottom, true);
        
        g.drawLine(0, 0, width, 0, lineThickness);
        g.drawLine(width, 0, width, height, lineThickness);
        g.drawLine(width, height, 0, height, lineThickness);
        g.drawLine(0, height, 0, 0, lineThickness);
        
        g.drawLine(volumeToggle1.getX() + 20, volumeToggle1.getY()+volumeToggle1.getHeight()/2, volumeToggle1.getX() - 10, volumeToggle1.getY()+volumeToggle1.getHeight()/2, lineThickness);
        g.drawLine(volumeToggle2.getX() + 20, volumeToggle2.getY()+volumeToggle2.getHeight()/2, volumeToggle2.getX() - 10, volumeToggle2.getY()+volumeToggle2.getHeight()/2, lineThickness);
        g.drawLine(volumeToggle3.getX() + 20, volumeToggle3.getY()+volumeToggle3.getHeight()/2, volumeToggle3.getX() - 10, volumeToggle3.getY()+volumeToggle3.getHeight()/2, lineThickness);
        
        g.drawLine(extInputVolumeToggle.getRight() - 22, extInputVolumeToggle.getY()+extInputVolumeToggle.getHeight()/2, extInputVolumeToggle.getRight() + 12, extInputVolumeToggle.getY()+extInputVolumeToggle.getHeight()/2, lineThickness);
        
        g.drawLine(noiseVolumeToggle.getRight() - 22, noiseVolumeToggle.getY()+noiseVolumeToggle.getHeight()/2, noiseVolumeToggle.getRight() + 12, noiseVolumeToggle.getY()+noiseVolumeToggle.getHeight()/2, lineThickness);
        
        area = Rectangle<int>(0, 0, width, height);
        area.removeFromRight(width/2);
        area.removeFromLeft(width/4);
        area.removeFromBottom(height*.835);
        area.setPosition(area.getX(), area.getHeight());
        
        
        
        
    }
    
    void resized() override
    {
        area = Rectangle<int>(0, 0, width, height);
        area.removeFromRight(width*.75);
        area.removeFromBottom(height*.75);
        area.setPosition(area.getX()+4, area.getY()+18);
        volume1.setBounds(area);
        area.setPosition(area.getX(), area.getY()+(height*.28));
        volume2.setBounds(area);
        area.setPosition(area.getX(), area.getY()+(height*.28));
        volume3.setBounds(area);
        area.setPosition(area.getWidth()*2 +10, area.getY() - (height*.14));
        extInputVolume.setBounds(area);
        area.setPosition(area.getWidth()*2 +10, area.getY() - (height*.28));
        noiseVolume.setBounds(area);
        
        area = Rectangle<int>(0, 0, width, height);
        area.removeFromRight(width/2);
        area.removeFromLeft(width/4);
        area.removeFromBottom(height*.86);
        area.setPosition(area.getX()+5, area.getHeight()/3 + 25);
        volumeToggle1.setBounds(area);
        area.setPosition(area.getX(), area.getY() + area.getHeight());
        extInputVolumeToggle.setBounds(area);
        area.setPosition(area.getX(), area.getY() + area.getHeight());
        volumeToggle2.setBounds(area);
        area.setPosition(area.getX(), area.getY() + area.getHeight());
        noiseVolumeToggle.setBounds(area);
        area.setPosition(area.getX(), area.getY() + area.getHeight());
        volumeToggle3.setBounds(area);
    }

private:
    Rectangle<int> area;
    
    MoogDefaultKnob customLook;
    
    
    Slider volume1;
    Slider volume2;
    Slider volume3;
    Slider extInputVolume;
    Slider noiseVolume;
    
    FlipSwitch volumeToggle1;
    FlipSwitch volumeToggle2;
    FlipSwitch volumeToggle3;
    FlipSwitch extInputVolumeToggle;
    FlipSwitch noiseVolumeToggle;
    
    
    
    
    float lineThickness = 3.0f;
    
    int height = 350;
    int width = 375;
    int knobBorder = 5;
    int leftKnobOffset = 10;
    
    Font panelFont;
    Font knobFont;
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerPanel)
};
