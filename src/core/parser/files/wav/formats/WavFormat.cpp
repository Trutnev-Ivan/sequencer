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
    this->fmtChunk = nullptr;
}