#pragma once
#include "Interpolation.h"
#include <vector>

namespace wav
{
    class LinearInterpolation: public Interpolation
    {
    protected:
        std::vector<WavSample*> buffer;
        float countAppend = 0;
        WavSample* getFirstElementFromBuffer();
        void fillBuffer();
        WavSample* getInterpolationSample(int i, WavSample* start, WavSample* end);
        WavSample* prevSample = nullptr;
    public:
        LinearInterpolation(WavFormat* format);
        virtual WavSample* nextSample();
    };
}