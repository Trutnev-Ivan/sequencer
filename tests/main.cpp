#include "TestManager.h"
#include "json/JsonItemTest.h"
#include "json/JsonTest.h"
#include <bit/BitParser.h>
#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
    std::ifstream* file = new std::ifstream("StarWars3.wav", std::ios::binary);

    BitParser parser(file, BIT_ORDER::MSB);

    int ch = parser.get(32);
    std::cout << (ch == 0x52494646);

    file->close();
    delete file;
    
    return EXIT_SUCCESS;
}