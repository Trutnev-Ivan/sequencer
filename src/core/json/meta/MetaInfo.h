#pragma once

enum PARSING_ELEMENT {
        STRING,
        NUMBER,
        BOOL,
        ARRAY,
        OBJECT,
        OBJECT_ITEM
    };

class MetaInfo
{
public:
    virtual PARSING_ELEMENT getType() = 0;
    virtual std::string toString() = 0;
};