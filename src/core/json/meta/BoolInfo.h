#pragma once
#include "MetaInfo.h"

class BoolInfo: public MetaInfo
{
private:
    bool isValidChar(char c)
    {
        if (this->value.length())
        {
            if (this->value.length() == 5 && std::isalpha(c))
                return false;

            int index = this->value.length() - 1;
            char prevChar = this->value[index];

            switch (index)
            {
                case 0:
                    return prevChar == 't' && c == 'r' || prevChar == 'f' && c == 'a';
                case 1:
                    return prevChar == 'r' && c == 'u' || prevChar == 'a' && c == 'l';
                case 2:
                    return prevChar == 'u' && c == 'e' || prevChar == 'l' && c == 's';
                case 3:
                    return prevChar == 's' && c == 'e';
            }
        }

        return true;
    }
protected:
    std::string value;
public:
    virtual PARSING_ELEMENT getType() override
    {
        return PARSING_ELEMENT::BOOL;
    }

    void appendChar(char c)
    {
        if ((this->value.length() == 4 || this->value.length() == 5)
            && (std::isspace(c) || c == '\n'))
        {}
        else
        {
            if (!isValidChar(c))
            throw new std::exception; // TODO: change exception

            value += c;
        }        
    }

    std::string getValue()
    {
        return value;
    }

    virtual std::string toString() override
    {
        return this->getValue();
    }
};