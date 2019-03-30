/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 28 Mar 2019 9:09:30pm
    Author:  Benjamin Stoneking

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class CustomLookAndFeel    : public LookAndFeel_V4
{
public:
    CustomLookAndFeel()
    {
        setColour (Slider::thumbColourId, Colours::red);
    }

    ~CustomLookAndFeel()
    {
    }

    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        auto outerRadius = jmin (35, 35) - 4.0f;
        auto innerRadius = jmin (28, 28) - 4.0f;
        auto centreX = x + width  * 0.5f;
        auto centreY = y + height * 0.5f;
        
        auto outerx = centreX - outerRadius;
        auto outery = centreY - outerRadius;
        auto innerx = centreX - innerRadius;
        auto innery = centreY - innerRadius;
        
        auto outerw = outerRadius * 2.0f;
        auto innerw = innerRadius * 2.0f;
        auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        // fill
        g.setColour (Colour (30, 30, 30));
        g.fillEllipse (outerx, outery, outerw, outerw);
        // outline
        g.setColour (Colour (170, 170, 170));
        g.fillEllipse (innerx, innery, innerw, innerw);
        
        Path p;
        auto pointerLength = outerRadius * 0.33f;
        auto pointerThickness = 3.0f;
        p.addRectangle (-pointerThickness * 0.5f, -outerRadius, pointerThickness, pointerLength);
        p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY));
        
        g.setColour (Colour (206, 206, 206));
        g.fillPath (p);
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomLookAndFeel)
};
