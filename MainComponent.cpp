#include "MainComponent.h"
// Based a demo project provided by the JUCE developer: https://docs.juce.com/master/tutorial_simple_synth_noise.html
//==============================================================================
class MainContentComponent : public juce::AudioAppComponent {
public:
    MainContentComponent()
    {
        // Make sure you set the size of the component after
        // you add any child components.
        setSize(800, 600);

        // Some platforms require permissions to open input channels so request that here
        if (juce::RuntimePermissions::isRequired(juce::RuntimePermissions::recordAudio)
            && !juce::RuntimePermissions::isGranted(juce::RuntimePermissions::recordAudio))
        {
            juce::RuntimePermissions::request(juce::RuntimePermissions::recordAudio,
                [&](bool granted) { setAudioChannels(granted ? 2 : 0, 2); });
        }
        else
        {
            // Specify the number of input and output channels that we want to open
            setAudioChannels(0, 2);
        }
    }

    ~MainContentComponent()override
    {
        // This shuts down the audio device and clears the audio source.
        shutdownAudio();
    }

    //==============================================================================
    void MainContentComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
    {
        // This function will be called when the audio device is started, or when
        // its settings (i.e. sample rate, block size, etc) are changed.
        juce::String message;
        message << "Starting playback...\n";
        message << "Expected frequency = " << samplesPerBlockExpected << "/n";
        message << "Sampling rate = " << sampleRate;
        juce::Logger::getCurrentLogger()->writeToLog(message);
        // You can use this function to initialise any resources you might need,
        // but be careful - it will be called on the audio thread, not the GUI thread.

        // For more details, see the help for AudioProcessor::prepareToPlay()
    }


    void MainContentComponent::releaseResources()
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.
        juce::Logger::getCurrentLogger()->writeToLog("Freeing Resources");
        // For more details, see the help for AudioProcessor::releaseResources()
    }
    void MainContentComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)override
    {
        // Your audio-processing code goes here!
        for (auto channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel) {
            auto* buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);
            for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
            buffer[sample] = random.nextFloat() * 0.25f - 0.125f;
            
                // For more details, see the help for AudioProcessor::getNextAudioBlock()

                // Right now we are not producing any data, in which case we need to clear the buffer
                // (to prevent the output of random noise)
                bufferToFill.clearActiveBufferRegion();
            }
        }
    private:
        juce::Random random;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)
    };
    //==============================================================================