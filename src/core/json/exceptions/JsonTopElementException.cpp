#include "JsonTopElementException.h"

const char* JsonTopElementException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
    return "Top element in json mus be object or array";
}