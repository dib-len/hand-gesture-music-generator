/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HandgesturepluginAudioProcessorEditor::HandgesturepluginAudioProcessorEditor (HandgesturepluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    effectSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    effectSlider.setRange(0.0, 1.0, 0.01);
    effectSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    effectSlider.setPopupDisplayEnabled(true, false, this);
    effectSlider.setTextValueSuffix(" Wackiness");
    effectSlider.setValue(0.5);

    addAndMakeVisible(&effectSlider);

    effectSlider.addListener(this);

    fileComp.reset(new juce::FilenameComponent("fileComp",
        {},                       // current file
        false,                    // can edit file name,
        false,                    // is directory,
        false,                    // is for saving,
        {},                       // browser wildcard suffix,
        {},                       // enforced suffix,
        "Select file to open"));  // text when nothing selected
    addAndMakeVisible(fileComp.get());

    fileComp->addListener(this);

    
}

HandgesturepluginAudioProcessorEditor::~HandgesturepluginAudioProcessorEditor()
{
}

//==============================================================================
void HandgesturepluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hand Gesture Plugin Wooooo!", getLocalBounds(), juce::Justification::centredTop, 1);
}

void HandgesturepluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    effectSlider.setBounds(40, 30, 20, getHeight() - 60);
}

void HandgesturepluginAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    audioProcessor.effect1 = effectSlider.getValue();
}