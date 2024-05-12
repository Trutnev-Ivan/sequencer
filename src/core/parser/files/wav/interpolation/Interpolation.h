#pragma once
#include "../samples/WavSample.h"

namespace wav
{
    class WavFormat;

    class Interpolation {
    protected:
        WavFormat* format = nullptr;
    public:
        Interpolation(WavFormat* format);
        virtual WavSample* nextSample() = 0;
    };
}