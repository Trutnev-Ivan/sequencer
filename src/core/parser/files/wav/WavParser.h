#pragma once
#include <bit/BitParser.h>
#include <fstream>
#include <string>
#include <filesystem>

#include "WavFormatFactory.h"

#include "exceptions/RiffException.h"
#include "exceptions/WaveException.h"
#include "exceptions/FormatChunkException.h"

class WavParser
{
private:
    static const unsigned int RIFF = 0x46464952;
    static const unsigned int WAVE = 0x45564157;
    static const unsigned int FORMAT_ID = 0x20746d66;
    static const unsigned int DATA_ID = 0x61746164;
protected:
    std::ifstream* file = nullptr;
    BitParser* bitParser = nullptr;
    WavFormat* parsingStrategy = nullptr;
    uint32_t fileSize = 0;
    uint32_t dataSize = 0;
    uint32_t startDataPosition = 0;

    void parseHeader();
public:
    WavParser(std::string path);
    ~WavParser();
};