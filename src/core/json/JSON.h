#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stack>

#include "meta/MetaInfo.h"
#include "meta/ObjectInfo.h"
#include "meta/ArrayInfo.h"
#include "meta/ObjectItemInfo.h"
#include "meta/StringInfo.h"
#include "meta/NumberInfo.h"
#include "meta/BoolInfo.h"

class JSON
{
protected:
    std::stack<MetaInfo*> parsingElement;
    MetaInfo* topElement;
public:
    
    JSON(std::string path)
    {
        if (!std::filesystem::exists(path))
            throw new std::ifstream::failure("File " + path + " not exists");

        if (std::filesystem::path(path).extension() != ".json")
            throw new std::ifstream::failure("File extension must be .json");

        std::ifstream file(path);
        
        while (!file.eof())
        {
            char c = file.get();

            switch (c)
            {
                
            }

            //std::cout << c;
        }

        //if (this->parsingElement.size())
        //    throw new std::exception; // TODO: change exception

        ObjectInfo* obj = static_cast<ObjectInfo*>(this->topElement);
        
        std::vector<ObjectItemInfo*> items = obj->getItems();

        std::cout << "SIZE: " << items.size() << std::endl;

        std::cout << obj->toString();
        

        file.close();
    }
};