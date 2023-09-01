#pragma once
#include <JuceHeader.h>

class OscirenderAudioProcessor;
class PitchDetector : public juce::Thread, public juce::AsyncUpdater {
public:
	PitchDetector(OscirenderAudioProcessor& audioProcessor);
	~PitchDetector();

    void run() override;
    void handleAsyncUpdate() override;
    int addCallback(std::function<void(float)> callback);
    void removeCallback(int index);
    void setSampleRate(float sampleRate);

    std::atomic<float> frequency = 0.0f;

private:
	static constexpr int fftOrder = 15;
	static constexpr int fftSize = 1 << fftOrder;

    std::vector<float> buffer = std::vector<float>(2 * fftSize);
    juce::dsp::FFT forwardFFT{fftOrder};
    std::array<float, fftSize * 2> fftData;
    OscirenderAudioProcessor& audioProcessor;
    std::vector<std::function<void(float)>> callbacks;
    juce::SpinLock lock;
    float sampleRate = 192000.0f;

    float frequencyFromIndex(int index);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PitchDetector)
};
