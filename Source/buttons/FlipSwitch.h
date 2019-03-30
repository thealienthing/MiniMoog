/*
  ==============================================================================

    FlipSwitch.h
    Created: 29 Mar 2019 11:37:41am
    Author:  Benjamin Stoneking

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class FlipSwitch    : public ImageButton
{
public:
    FlipSwitch()
    {
        setSize(52, 20);
        pointerLine = 0;
        onButton = ImageCache::getFromMemory (BinaryData::redOn_png, BinaryData::redOn_pngSize);
        offButton= ImageCache::getFromMemory (BinaryData::redOff_png,BinaryData::redOff_pngSize);
        myImageButton.setImages(false, false, false, offButton, 1.0f, {}, Image(), 1.0f, {}, onButton, 1.0f, {});
        myImageButton.setClickingTogglesState(true);
        addAndMakeVisible(myImageButton);
        myImageButton.setAlwaysOnTop(true);
    }

    ~FlipSwitch()
    {
    }
    
    void setSwitchColour(const juce::String colourArg)
    {
        if (colourArg == "blue")
        {
            onButton = ImageCache::getFromMemory (BinaryData::blueOn_png, BinaryData::blueOn_pngSize);
            offButton= ImageCache::getFromMemory (BinaryData::blueOff_png,BinaryData::blueOff_pngSize);
            myImageButton.setImages(false, false, false, offButton, 1.0f, {}, Image(), 1.0f, {}, onButton, 1.0f, {});
        }
        else if (colourArg == "red")
        {
            onButton = ImageCache::getFromMemory (BinaryData::redOn_png, BinaryData::redOn_pngSize);
            offButton= ImageCache::getFromMemory (BinaryData::redOff_png,BinaryData::redOff_pngSize);
            myImageButton.setImages(false, false, false, offButton, 1.0f, {}, Image(), 1.0f, {}, onButton, 1.0f, {});
        }
    }
    
    void setPointerLine(int setNumber)
    {
        pointerLine = setNumber;
        repaint();
    }

    void paint (Graphics& g) override
    {
        g.setColour(Colours::white);
        Rectangle<int> area = getLocalBounds();
        
        if (pointerLine == 0)
            pointerLine = 0;
        
        else if (pointerLine == 1)
            g.drawLine(area.getRight()-20, area.getHeight()/2, area.getRight()+30, area.getHeight()/2, 3.0);
        
        else if (pointerLine == -1)
            g.drawLine(area.getX()+20, area.getHeight()/2, area.getX()-30, area.getHeight()/2, 3.0);
    }

    void resized() override
    {
        myImageButton.setBounds(getLocalBounds());

    }

private:
    ImageButton myImageButton;
    Image onButton;
    Image offButton;
    
    int pointerLine; //if 0 then no pointer line. -1 is left and 1 is right
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FlipSwitch)
};
