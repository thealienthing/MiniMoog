/*
  ==============================================================================

    BlueFlipSwitch.h
    Created: 28 Mar 2019 1:17:21pm
    Author:  Benjamin Stoneking

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class BlueFlipSwitch    : public ImageButton
{
public:
    BlueFlipSwitch()
    {
        setSize(70, 27);
        onButton = ImageCache::getFromMemory (BinaryData::blueOn_png, BinaryData::blueOn_pngSize);
        offButton= ImageCache::getFromMemory (BinaryData::blueOff_png,BinaryData::blueOff_pngSize);
        myImageButton.setImages(false, false, false, offButton, 1.0f, {}, Image(), 1.0f, {}, onButton, 1.0f, {});
        myImageButton.setClickingTogglesState(true);
        addAndMakeVisible(myImageButton);
        myImageButton.setAlwaysOnTop(true);

    }

    ~BlueFlipSwitch()
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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BlueFlipSwitch)
};
