#pragma once
#include "WavSample.h"

namespace wav
{
    class PcmSample: public WavSample
    {
    public:
        PcmSample(int8_t value);
        PcmSample(uint8_t value);
        PcmSample(int16_t value);
        PcmSample(uint16_t value);
        PcmSample(int32_t value);
        PcmSample(uint32_t value);
        PcmSample(int64_t value);
        PcmSample(uint64_t value);
        PcmSample(float value);
        PcmSample(double value);
    
        virtual double normalize(double start, double end) override;
        virtual int64_t normalize(int64_t start, int64_t end) override;
    };
}