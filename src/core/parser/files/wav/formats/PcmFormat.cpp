#include "PcmFormat.h"
#include <iostream>


PcmFormat::PcmFormat(BitParser* parser):
    WavFormat(parser)
    {}

PcmFormat::~PcmFormat()
{
    delete this->fmtChunk;
    this->fmtChunk = nullptr;
}

void PcmFormat::parseFmtChunk()
{
    this->fmtChunk = new PcmFmtChunk;

    this->fmtChunk->setChannels(static_cast<uint16_t>(this->parser->get(16)));
    this->fmtChunk->setSampleRate(this->parser->get(32));
    this->fmtChunk->setByteRate(this->parser->get(32));
    this->fmtChunk->setBlockAlign(this->parser->get(16));
    this->fmtChunk->setBitsPerSample(this->parser->get(16));
}