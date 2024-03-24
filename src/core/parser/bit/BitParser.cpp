#include "BitParser.h"

BitParser::BitParser(std::ifstream* file, BIT_ORDER order)
{
    this->file = file;
    this->order = order;
}

BitParser::BitParser(std::ifstream* file)
{
    this->file = file;
    this->order = BIT_ORDER::LSB;
}

uint64_t BitParser::get(int count)
{
    if (this->order == BIT_ORDER::MSB)
        return this->getBigEndian(count);
    else
        return this->getLittleEndian(count);
}

uint64_t BitParser::getBigEndian(int count)
{
    assert(count >= 0 && count <= 57);

    while (this->length < count)
    {
        this->buffer |= static_cast<uint64_t>(this->file->get()) << (56 - this->length);
        this->length += 8;
    }

    uint64_t result = (this->buffer >> 1) >> (63 - count);

    this->buffer << count;
    this->length -= count;

    return result;
}

uint64_t BitParser::getLittleEndian(int count)
{
    assert(count >= 0 && count <= 57);

    while (this->length < count) 
    {
        this->buffer |= static_cast<uint64_t>(this->file->get()) << this->length;
        this->length += 8;
    }

    uint64_t result = this->buffer & ((1ull << count) - 1);

    this->buffer >>= count;
    this->length -= count;

    return result;
}