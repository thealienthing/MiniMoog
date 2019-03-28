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
class FlipSwitch    :   public ImageButton
{
public:
    
    FlipSwitch ()
    {
        setSize(70, 27);
        onButton = ImageCache::getFromMemory (BinaryData::on_png, BinaryData::on_pngSize);
        offButton= ImageCache::getFromMemory (BinaryData::off_png,BinaryData::off_pngSize);
        myImageButton.setImages(false, false, false, offButton, 1.0f, {}, Image(), 1.0f, {}, onButton, 1.0f, {});
        myImageButton.setClickingTogglesState(true);
        addAndMakeVisible(myImageButton);
        myImageButton.setAlwaysOnTop(true);
        
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
    Image onButton;
    Image offButton;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FlipSwitch)
};


