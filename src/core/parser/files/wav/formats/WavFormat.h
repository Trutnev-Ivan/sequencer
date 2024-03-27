#pragma once
#include <fstream>
#include <bit/BitParser.h>
#include "../chunks/FmtChunk.h"
#include "../samples/WavSample.h"

namespace wav
{
    class WavFormat
    {
    protected:
        BitParser* parser = nullptr;
        FmtChunk* fmtChunk = nullptr;
    public:
        WavFormat(BitParser* parser);
        ~WavFormat();
        virtual void parseFmtChunk() = 0;
        FmtChunk* getFmtChunk();
        virtual WavSample* getSample() = 0;
    };
}
