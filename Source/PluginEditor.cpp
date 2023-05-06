/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
QrsdemoAudioProcessorEditor::QrsdemoAudioProcessorEditor (QrsdemoAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    // Room size slider
            roomSizeSlider.setSliderStyle (juce::Slider::LinearBarVertical);
            roomSizeSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
            roomSizeSlider.setRange (0.0, 1.0, 0.01);
            roomSizeSlider.setValue (0.5);
            roomSizeSlider.addListener (this);
            addAndMakeVisible (roomSizeSlider);
            
            // Damping slider
            dampingSlider.setSliderStyle (juce::Slider::LinearBarVertical);
            dampingSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
            dampingSlider.setRange (0.0, 1.0, 0.01);
            dampingSlider.setValue (0.5);
            dampingSlider.addListener (this);
            addAndMakeVisible (dampingSlider);
    

            
}

QrsdemoAudioProcessorEditor::~QrsdemoAudioProcessorEditor()
{
}

//==============================================================================
void QrsdemoAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void QrsdemoAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void QrsdemoAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    // Get the value of the slider
        auto value = slider->getValue();

        // Convert the value to a string
        auto valueString = juce::String(value);

        // Display the value in a label
        label.setText(valueString, juce::NotificationType::dontSendNotification);
    
}
