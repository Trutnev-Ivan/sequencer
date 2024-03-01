#include "NumberState.h"

NumberState::NumberState(std::stack<MetaInfo*>* stack):
    JsonParserState(stack)
    {}

JsonParserState* NumberState::next(char c)
{
    NumberInfo* numberInfo = static_cast<NumberInfo*>(this->parsingElement->top());
    
    if (std::isdigit(c))
    {
        numberInfo->appendChar(c);
        return this;
    }
    else if (c == '.')
    {
        if (this->hasPoint)
            throw new std::runtime_error("Point parsed error"); // TODO: change error

        this->hasPoint = true;
        numberInfo->appendChar(c);
        return this;
    }
    else if (c == ',' || c == ']' || c == '}' || std::isspace(c))
    {
        AppendState* appendState = new AppendState(this->parsingElement);
        JsonParserState* next = appendState->next(c);

        delete appendState;
        return next->next(c);
    }
    else
    {
        throw new std::runtime_error("Number parse error char: " + c); // TODO: change error
    }
}