/*
  ==============================================================================

    driver.cpp
    Created: 6 May 2023 4:52:08pm
    Author:  Leanne Dong

  ==============================================================================
*/
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "PluginEditor.h"

class MainComponent : public juce::Component{
public:
    MainComponent()
    {
        // Set up the audio processor
        audioProcessor = std::make_unique<QrsdemoAudioProcessor>();
        
        // Create the audio processor and its editor
        auto audioProcessor = std::make_unique<QrsdemoAudioProcessor>();
        auto audioProcessorEditor = std::make_unique<QrsdemoAudioProcessorEditor>(*audioProcessor);

        // Set up the user interface
        addAndMakeVisible(*audioProcessorEditor);

        setSize(800, 600);
    }
    
    ~MainComponent() override
        {
            audioProcessorEditor = nullptr;
        }

        void paint (juce::Graphics&) override
        {
            // This is where you would paint your background if you have one
        }

        void resized() override
        {
            // Make the user interface fill the component's bounds
            audioProcessorEditor->setBounds(getLocalBounds());
        }

    private:
        std::unique_ptr<QrsdemoAudioProcessor> audioProcessor;
        std::unique_ptr<QrsdemoAudioProcessorEditor> audioProcessorEditor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent);
};
