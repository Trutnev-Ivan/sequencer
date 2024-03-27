#include "TestManager.h"
#include "json/JsonItemTest.h"
#include "json/JsonTest.h"
#include <wav/WavParser.h>
#include <iostream>

#include <portaudio.h>

static PaError initialize_port_audio();
static void play_audio();
//static PaError clean_up();

int pa_stream_callback(const void*, void*, unsigned long, const PaStreamCallbackTimeInfo*, PaStreamCallbackFlags, void*);

wav::WavParser* parser = nullptr;
PaStream* _stream = NULL;

int main(int argc, char** argv)
{
    parser = new wav::WavParser("StarWars3.wav");
    
    void* a;
    int b = 1234;
    a = &b;

    std::cout << *static_cast<int*>(a) << std::endl;

    delete parser;

    return EXIT_SUCCESS;
}

PaError initialize_port_audio(double sampleRate)
{
    PaError error = paNoError;

	error = Pa_Initialize();
	if (error) { return error; }

	error = Pa_OpenDefaultStream(&_stream, 1, 2, paFloat32, sampleRate,
		paFramesPerBufferUnspecified, pa_stream_callback, parser);
	if (error) { return error; }

	return paNoError;
}

void play_audio()
{
    Pa_StartStream(_stream);
	while (Pa_IsStreamActive(_stream)) {
		Pa_Sleep(100);
	}
	Pa_StopStream(_stream);

	Pa_CloseStream(_stream);
}

int pa_stream_callback(const void* input, void* output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo,
	PaStreamCallbackFlags statusFlags, void* userData)
{
    wav::WavParser* data = (wav::WavParser*)userData;
	unsigned long framesRead = 0;
	unsigned long frames = frameCount * (unsigned long)data->getHeader()->getChannels();

	memset(output, 0, sizeof(float) * frameCount * data->getHeader()->getChannels()); 	/* clear output buffer */

	//framesRead = sf_readf_float(data->file, output, frameCount);

	if (framesRead < frameCount) {
		return paComplete;
	}

	return paContinue;
}