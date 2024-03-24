#pragma once
#include "WavFormat.h"
#include "../chunks/PcmFmtChunk.h"

class PcmFormat: public WavFormat
{
protected:
    PcmFmtChunk* fmtChunk = nullptr;
public:
    PcmFormat(BitParser* parser);
    ~PcmFormat();
    virtual void parseFmtChunk() override;
};