#pragma once
#include <exception>

class JsonTypeException: std::exception
{
public:
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};