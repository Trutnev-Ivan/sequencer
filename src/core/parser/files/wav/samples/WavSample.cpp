#include "WavSample.h"

wav::WavSample::WavSample(int8_t value)
{
    this->value = &value;
    this->type = WAV_STORE_TYPE::INT8;
}

wav::WavSample::WavSample(uint8_t value)
{
    this->value = &value;
    this->type = WAV_STORE_TYPE::UINT8;
}

wav::WavSample::WavSample(int16_t value)
{
    this->value = &value;
    this->type = WAV_STORE_TYPE::INT16;
}

wav::WavSample::WavSample(uint16_t value)
{
    this->value = &value;
    this->type = WAV_STORE_TYPE::UINT16;
}

wav::WavSample::WavSample(int32_t value)
{
    this->value = &value;
    this->type = WAV_STORE_TYPE::INT32;
}

wav::WavSample::WavSample(uint32_t value)
{
    this->value = &value;
    this->type = WAV_STORE_TYPE::UINT32;
}

wav::WavSample::WavSample(int64_t value)
{
    this->value = &value;
    this->type = WAV_STORE_TYPE::INT64;
}

wav::WavSample::WavSample(uint64_t value)
{
    this->value = &value;
    this->type = WAV_STORE_TYPE::UINT64;
}

wav::WavSample::WavSample(float value)
{
    this->value = &value;
    this->type = WAV_STORE_TYPE::FLOAT;
}

wav::WavSample::WavSample(double value)
{
    this->value = &value;
    this->type = WAV_STORE_TYPE::DOUBLE;
}
