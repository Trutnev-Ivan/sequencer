#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stack>

#include "parser/JsonParser.h"

class JSON
{
public:
    
    JSON(std::string path)
    {
        if (!std::filesystem::exists(path))
            throw new std::ifstream::failure("File " + path + " not exists");

        if (std::filesystem::path(path).extension() != ".json")
            throw new std::ifstream::failure("File extension must be .json");

        std::ifstream* file = new std::ifstream(path);
        
        JsonParser* parser = new JsonParser(file);

        file->close();
        delete file;

        delete parser;
    }
};