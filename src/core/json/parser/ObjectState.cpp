#include "ObjectState.h"

JsonParserState* ObjectState::next(char c)
{
        if (std::isspace(c))
            return this;

        if (c == '}')
        {
            if (this->parsingElement->size() == 1)
                return new EndState(this->parsingElement);
            else
            {
                return nullptr;
                //TODO: добавить добавление объекта в др. объект или в массив
            }
        }
        else if (c == '\'' || c == '"')
        {
            this->parsingElement->push(new ObjectItemInfo(c));
            return new ObjectItemState(this->parsingElement);
        }
        else
        {
            throw new std::runtime_error("Object parser ivalid char: " + c); // TODO: заменить 
        }
}