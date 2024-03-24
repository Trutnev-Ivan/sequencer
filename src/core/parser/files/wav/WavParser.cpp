#include "WavParser.h"
#include <iostream>

WavParser::WavParser(std::string path)
{
    if (!std::filesystem::exists(path))
        throw std::ifstream::failure("File " + path + " not exists");

    if (std::filesystem::path(path).extension() != ".wav")
        throw std::ifstream::failure("File extension must be .wav");

    this->file = new std::ifstream(path, std::ios::binary);
    this->bitParser = new BitParser(file, BIT_ORDER::LSB);

    this->parseHeader();
}

void WavParser::parseHeader()
{
    if (this->bitParser->get(32) != WavParser::RIFF)
        throw RiffException();

    this->fileSize = this->bitParser->get(32) + 8;

    if (this->bitParser->get(32) != WavParser::WAVE)
        throw WaveException();

    if (this->bitParser->get(32) != WavParser::FORMAT_ID)
        throw FormatChunkException();

    uint32_t formatChunkSize = this->bitParser->get(32);

    this->parsingStrategy = WavFormatFactory::getInstance(this->bitParser, this->bitParser->get(16));
    this->parsingStrategy->parseFmtChunk();

    uint32_t chunkId = this->bitParser->get(32);

    //TODO: добавить парсинг др. типов чанков
    if (chunkId == WavParser::DATA_ID)
    {
        this->dataSize = this->bitParser->get(32);
        this->startDataPosition = this->file->tellg();
    }
}

WavParser::~WavParser()
{
    this->file->close();
    
    delete this->file;
    delete this->bitParser;
    delete this->parsingStrategy;

    this->file = nullptr;
    this->bitParser = nullptr;
    this->parsingStrategy = nullptr;
}