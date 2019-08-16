#include "tracker.h"

Tracker::Tracker()
{
    for (int i = 0; i < CHANNELS; i++)
    {
        loadSinWave(i); //load sinwave into all channels (for testing)
    }
}

void Tracker::loadSinWave(int c)
{
    const unsigned SAMPLES = 44100;
	const unsigned SAMPLE_RATE = 44100;
	const unsigned AMPLITUDE = 30000;
	sf::Int16 raw[SAMPLES];
	const double TWO_PI = 6.28318;
	double increment = 440./44100;
	double x = 0;
	for (unsigned i = 0; i < SAMPLES; i++) {
		raw[i] = AMPLITUDE * sin(x*TWO_PI);
		x += increment;
	}
	sf::SoundBuffer buffer;
	if (!buffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)) {
		std::cerr << "Loading failed!" << std::endl;
		return;
	}

	channel[c].setBuffer(buffer);

}
