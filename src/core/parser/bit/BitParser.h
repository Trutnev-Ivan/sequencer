#pragma once
#include <cstdint>
#include <fstream>
#include <cassert>

enum BIT_ORDER {LSB, MSB};

/**
 * https://habr.com/ru/articles/359122/
*/
class BitParser
{
protected:
    uint64_t buffer = 0;
    int length = 0;
    BIT_ORDER order;
    std::ifstream* file = nullptr;

    uint64_t getBigEndian(int count);
    uint64_t getLittleEndian(int count);
public:
    BitParser(std::ifstream* file, BIT_ORDER order);
    BitParser(std::ifstream* file);
    uint64_t get(int count);
};