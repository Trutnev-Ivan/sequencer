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
    ObjectItemInfo(char keyQuotesType);
    char getKeyQuotesType();
    void endKeyParse();
    bool isKeyParsed();
    void setValue(MetaInfo* value);
    MetaInfo* getValue();
    void appendToKey(char c);
    bool isEscaped();
    std::string getKey();
    virtual PARSING_ELEMENT getType() override;
    virtual std::string toString() override;
};