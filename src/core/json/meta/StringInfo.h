#pragma once

#include "MetaInfo.h"
#include <string>

class StringInfo: public MetaInfo
{
protected:
    char quoteType;
    char prevChar;
    std::string value;
public:
    StringInfo(char quoteType)
    {
        this->quoteType = quoteType;
    }

    char getQuoteType()
    {
        return this->quoteType;
    }

    bool isEscaped()
    {
        return this->prevChar == '\\';
    }

    std::string getValue()
    {
        return this->value;
    }

    void appendChar(char c)
    {
        if (this->value.length())
            this->prevChar = this->value[this->value.length() - 1];

        this->value += c;
    }

    virtual PARSING_ELEMENT getType() override
    {
        return PARSING_ELEMENT::STRING;
    }

    virtual std::string toString() override
    {
        return "\"" + this->getValue() + "\"";
    }
};