#include "ArrayItemState.h"

ArrayItemState::ArrayItemState(std::stack<MetaInfo*>* stack):
    JsonParserState(stack)
    {
        if (this->parsingElement->top()->getType() != PARSING_ELEMENT::ARRAY_ITEM)
            throw new std::runtime_error("No array item"); // TODO: change error
    }

JsonParserState* ArrayItemState::next(char c) 
{
    if (std::isspace(c))
        return this;

    if (c == ',')
    {
        AppendState* appendState = new AppendState(this->parsingElement);
        JsonParserState* next = appendState->next(c);

        delete appendState;
        return next;
    }
    else if (c == ']')
    {
        AppendState* appendState = new AppendState(this->parsingElement);
        JsonParserState* next = appendState->next(c);

        delete appendState;
        return next->next(c);
    }
    else
    {
        throw new std::runtime_error("Invalid array item char: " + c); // TODO: change error
    }
}