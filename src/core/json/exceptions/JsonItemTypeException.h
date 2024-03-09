#pragma once
#include "JsonException.h"

namespace json
{
    class JsonItemTypeException: public JsonException
    {
    public:
        virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
    };
}