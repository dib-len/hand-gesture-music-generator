/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class HandgesturepluginAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    HandgesturepluginAudioProcessor();
    ~HandgesturepluginAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;


    //=========================================

    float effect1;

    

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HandgesturepluginAudioProcessor)

    //juce::dsp::ProcessorChain<juce::dsp::Chorus<float>, juce::dsp::Gain<float>> processorChain;
	juce::dsp::Chorus<float> chorus;
	juce::dsp::Reverb reverb;
	juce::dsp::Reverb::Parameters reverbParameters;

    juce::dsp::ProcessSpec spec;

    std::unique_ptr<juce::FilenameComponent> fileComp;
    //juce::FilenameComponent gestureFile;

};
