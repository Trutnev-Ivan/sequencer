#pragma once
#include <fstream>
#include <bit/BitParser.h>

class WavFormat
{
protected:
    BitParser* parser = nullptr;
public:
    WavFormat(BitParser* parser);
    virtual void parseFmtChunk() = 0;
};