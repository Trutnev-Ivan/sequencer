#include "JsonArrayItemStateException.h"

const char* JsonArrayItemStateException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
    return "No array item";
}