#pragma once
#include "MetaInfo.h"
#include <string>

class ObjectItemInfo: public MetaInfo
{
protected:
    char keyQuotesType;
    bool keyParsed = false;
    char prevKeyChar;
    std::string key;
    MetaInfo* value;
public:
    ObjectItemInfo(char keyQuotesType)
    {
        this->keyQuotesType = keyQuotesType;
    }

    char getKeyQuotesType()
    {
        return this->keyQuotesType;
    }

    void endKeyParse()
    {
        this->keyParsed = true;
    }

    bool isKeyParsed()
    {
        return this->keyParsed;
    }

    void setValue(MetaInfo* value)
    {
        this->value = value;
    }

    MetaInfo* getValue()
    {
        return this->value;
    }

    void appendToKey(char c)
    {
        if (this->key.length())
            prevKeyChar = this->key[this->key.length() - 1];

        this->key += c;
    }

    bool isEscaped()
    {
        return this->prevKeyChar == '\\';
    }

    std::string getKey()
    {
        return this->key;
    }

    virtual PARSING_ELEMENT getType() override
    {
        return PARSING_ELEMENT::OBJECT_ITEM;
    }

    virtual std::string toString() override
    {
        return "\"" + this->getKey() + "\": " + this->getValue()->toString();
    }
};