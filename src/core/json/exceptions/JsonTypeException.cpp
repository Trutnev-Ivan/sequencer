#include "JsonTypeException.h"

const char* JsonTypeException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
    return "Type must be inherited of JsonItem class";
}