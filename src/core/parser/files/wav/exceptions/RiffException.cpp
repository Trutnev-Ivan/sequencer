#include "RiffException.h"

const char* RiffException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
    return "Header doesn`t have a RIFF id";
}