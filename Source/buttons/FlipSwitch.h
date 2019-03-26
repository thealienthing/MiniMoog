/*
  ==============================================================================

    FlipSwitch.h
    Created: 22 Mar 2019 3:36:58pm
    Author:  Benjamin Stoneking

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
*/
class FlipSwitch    :   public Component
{
public:
    FlipSwitch()
    {
        Image normalButton = ImageCache::getFromMemory (BinaryData::off_png, BinaryData::off_pngSize);
        Image overButton = ImageCache::getFromMemory (BinaryData::on_png, BinaryData::on_pngSize);
        Image downButton = ImageCache::getFromMemory (BinaryData::on_png, BinaryData::on_pngSize);
        
        myImageButton.setImages (false, false, true, normalButton, 1.0f, {}, Image(), 1.0f, {}, downButton, 1.0f, {});
        
        addAndMakeVisible(myImageButton);
    }

    ~FlipSwitch()
    {
    }

    void paint (Graphics& g) override
    {
        
    }

    void resized() override
    {
        myImageButton.setBounds(getLocalBounds());
    }

private:
    ImageButton myImageButton;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FlipSwitch)
};


