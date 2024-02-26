#pragma once
#include "MetaInfo.h"
#include <string>

class NumberInfo: public MetaInfo
{
protected:
    std::string value;
public:
    virtual PARSING_ELEMENT getType() override
    {
        return PARSING_ELEMENT::NUMBER;
    }

    void appendChar(char c)
    {
        //if (!std::isdigit(c) && c != '.')
        //    throw new std::exception;//TODO: change excpetion

        this->value += c;
    }

    std::string getValue()
    {
        return this->value;
    }

    virtual std::string toString() override
    {
        return this->getValue();
    }
};