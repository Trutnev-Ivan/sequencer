#pragma once

#include <cstdint>

namespace wav{
    enum WAV_STORE_TYPE {
        INT8, 
        UINT8, 
        INT16, 
        UINT16, 
        INT32,
        UINT32,
        INT64,
        UINT64,
        FLOAT,
        DOUBLE
    };
    
    class WavSample
    {
    protected:
        void* value;
        WAV_STORE_TYPE type;
    public:
        WavSample(int8_t value);
        WavSample(uint8_t value);
        WavSample(int16_t value);
        WavSample(uint16_t value);
        WavSample(int32_t value);
        WavSample(uint32_t value);
        WavSample(int64_t value);
        WavSample(uint64_t value);
        WavSample(float value);
        WavSample(double value);
        ~WavSample();
    
        virtual double normalize(double start, double end) = 0;
        virtual float normalize(float start, float end) = 0;
        virtual int64_t normalize(int64_t start, int64_t end) = 0;
    };
}