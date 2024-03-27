#include "FmtChunk.h"

uint16_t wav::FmtChunk::getChannels()
{
    return this->channels;
}

uint32_t wav::FmtChunk::getSampleRate()
{
    return this->sampleRate;
}

uint32_t wav::FmtChunk::getByteRate()
{
    return this->byteRate;
}

uint16_t wav::FmtChunk::getBlockAlign()
{
    return this->blockAlign;
}

uint16_t wav::FmtChunk::getBitsPerSample()
{
    return this->bitsPerSample;
}

void wav::FmtChunk::setChannels(uint16_t channels)
{
    this->channels = channels;
}

void wav::FmtChunk::setSampleRate(uint32_t sampleRate)
{
    this->sampleRate = sampleRate;
}

void wav::FmtChunk::setByteRate(uint32_t byteRate)
{
    this->byteRate = byteRate;
}

void wav::FmtChunk::setBlockAlign(uint16_t blockAlign)
{
    this->blockAlign = blockAlign;
}

void wav::FmtChunk::setBitsPerSample(uint16_t bitsPerSample)
{
    this->bitsPerSample = bitsPerSample;
}
