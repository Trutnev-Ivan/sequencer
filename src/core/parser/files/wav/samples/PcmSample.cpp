#include "PcmSample.h"

wav::PcmSample::PcmSample(int8_t value):
    WavSample(value){}
wav::PcmSample::PcmSample(uint8_t value):
    WavSample(value){}
wav::PcmSample::PcmSample(int16_t value):
    WavSample(value){}
wav::PcmSample::PcmSample(uint16_t value):
    WavSample(value){}
wav::PcmSample::PcmSample(int32_t value):
    WavSample(value){}
wav::PcmSample::PcmSample(uint32_t value):
    WavSample(value){}
wav::PcmSample::PcmSample(int64_t value):
    WavSample(value){}
wav::PcmSample::PcmSample(uint64_t value):
    WavSample(value){}
wav::PcmSample::PcmSample(float value):
    WavSample(value){}
wav::PcmSample::PcmSample(double value):
    WavSample(value){}

double wav::PcmSample::normalize(double start, double end)
{
    switch (this->type)
    {
        case wav::WAV_STORE_TYPE::UINT8:
            uint8_t value = *static_cast<uint8_t*>(this->value);
            return 0.0;
    }
}

int64_t wav::PcmSample::normalize(int64_t start, int64_t end)
{
    return 0;
}