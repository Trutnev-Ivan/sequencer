#include "ObjectState.h"

ObjectState::ObjectState(std::stack<MetaInfo*>* stack):
    JsonParserState(stack)
    {}

void ObjectState::mustNextElem()
{
    this->isMustNextElem = true;
}

JsonParserState* ObjectState::next(char c)
{
        if (std::isspace(c))
            return this;

        if (c == '}')
        {
            if (this->isMustNextElem)
                throw new std::runtime_error("Must next elem"); // TODO: change error type

            if (this->parsingElement->size() == 1)
                return new EndState(this->parsingElement);
            else
            {
                AppendState* appendState = new AppendState(this->parsingElement);
                return appendState->next(c);

                //TODO: добавить добавление объекта в массив
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