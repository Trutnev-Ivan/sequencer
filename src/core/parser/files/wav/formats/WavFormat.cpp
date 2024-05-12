#include "WavFormat.h"

wav::WavFormat::WavFormat(BitParser* parser)
{
    this->parser = parser;
}

wav::FmtChunk* wav::WavFormat::getFmtChunk()
{
    return this->fmtChunk;
}

wav::WavFormat::~WavFormat()
{
    delete this->fmtChunk;
    delete this->interpolationStrategy;
    this->fmtChunk = nullptr;
    this->interpolationStrategy = nullptr;
}

void wav::WavFormat::changeSampleRate(uint32_t sampleRate)
{
    this->recalculateSampleRate = sampleRate;
}

wav::WavSample* wav::WavFormat::getSample()
{
    if (this->recalculateSampleRate != 0 && this->interpolationStrategy != nullptr)
    {
        return this->interpolationStrategy->nextSample();
    }

    return this->nextSample();
}

void wav::WavFormat::setInterpolation(wav::Interpolation* interpolation)
{
    this->interpolationStrategy = interpolation;
}

uint32_t wav::WavFormat::getInterpolationSampleRate()
{
    return this->recalculateSampleRate;
}

bool wav::WavFormat::isFileEnd()
{
    return this->parser->isFileEnd();
}