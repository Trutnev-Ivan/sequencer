#include "JsonNumberPointException.h"

const char* JsonNumberPointException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
    return "Point parse error: the point has already been parsed";
}