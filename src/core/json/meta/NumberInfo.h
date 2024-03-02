#pragma once
#include "MetaInfo.h"
#include <string>

class NumberInfo: public MetaInfo
{
protected:
    std::string value;
public:
    virtual PARSING_ELEMENT getType() override;
    void appendChar(char c);
    std::string getValue();
    virtual std::string toString() override;
};