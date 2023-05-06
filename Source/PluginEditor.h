/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class QrsdemoAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                        public juce::Slider::Listener
{
public:
    QrsdemoAudioProcessorEditor (QrsdemoAudioProcessor&);
    ~QrsdemoAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    QrsdemoAudioProcessor& audioProcessor;
    
    juce::Slider roomSizeSlider;
    juce::Slider dampingSlider;
    juce::Slider wetDryMixSlider;
    juce::Label label;
   // std::unique_ptr<QrsdemoAudioProcessorEditor> editor; // Add editor member variable here


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QrsdemoAudioProcessorEditor)
};
