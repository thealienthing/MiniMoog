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
class RedFlipSwitch    :   public ImageButton
{
public:
    
    RedFlipSwitch ()
    {
        setSize(70, 27);
        onButton = ImageCache::getFromMemory (BinaryData::redOn_png, BinaryData::redOn_pngSize);
        offButton= ImageCache::getFromMemory (BinaryData::redOff_png,BinaryData::redOff_pngSize);
        myImageButton.setImages(false, false, false, offButton, 1.0f, {}, Image(), 1.0f, {}, onButton, 1.0f, {});
        myImageButton.setClickingTogglesState(true);
        addAndMakeVisible(myImageButton);
        myImageButton.setAlwaysOnTop(true);
        
    }
    
    ~RedFlipSwitch()
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
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RedFlipSwitch)
};


