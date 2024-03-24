#include "FmtChunk.h"

uint16_t FmtChunk::getChannels()
{
    return this->channels;
}

uint32_t FmtChunk::getSampleRate()
{
    return this->sampleRate;
}

uint32_t FmtChunk::getByteRate()
{
    return this->byteRate;
}

uint16_t FmtChunk::getBlockAlign()
{
    return this->blockAlign;
}

uint16_t FmtChunk::getBitsPerSample()
{
    return this->bitsPerSample;
}

void FmtChunk::setChannels(uint16_t channels)
{
    this->channels = channels;
}

void FmtChunk::setSampleRate(uint32_t sampleRate)
{
    this->sampleRate = sampleRate;
}

void FmtChunk::setByteRate(uint32_t byteRate)
{
    this->byteRate = byteRate;
}

void FmtChunk::setBlockAlign(uint16_t blockAlign)
{
    this->blockAlign = blockAlign;
}

void FmtChunk::setBitsPerSample(uint16_t bitsPerSample)
{
    this->bitsPerSample = bitsPerSample;
}
