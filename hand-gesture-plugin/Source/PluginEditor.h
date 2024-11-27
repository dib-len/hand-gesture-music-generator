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
class HandgesturepluginAudioProcessorEditor : public juce::AudioProcessorEditor,
    private juce::Slider::Listener, juce::FilenameComponentListener
{
public:
    HandgesturepluginAudioProcessorEditor (HandgesturepluginAudioProcessor&);
    ~HandgesturepluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged(juce::Slider* slider)  override;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    HandgesturepluginAudioProcessor& audioProcessor;

    juce::Slider effectSlider;

    std::unique_ptr<juce::FilenameComponent> fileComp;
    std::unique_ptr<juce::TextEditor> textContent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HandgesturepluginAudioProcessorEditor)
};
