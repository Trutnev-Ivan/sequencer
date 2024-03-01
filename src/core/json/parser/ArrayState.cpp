#include "ArrayState.h"

ArrayState::ArrayState(std::stack<MetaInfo*>* stack):
    JsonParserState(stack)
    {}

void ArrayState::mustNextElement()
{
    this->isMustNextElement = true;
}

JsonParserState* ArrayState::next(char c)
{
    if (std::isspace(c))
        return this;

    if (c == '[')
    {
        this->parsingElement->push(new ArrayItemInfo);
        this->parsingElement->push(new ArrayInfo);
        return new ArrayState(this->parsingElement);
    }
    else if (c == ']')
    {
        if (this->isMustNextElement)
            throw new std::runtime_error("Must next element"); // TODO: change error type

        if (this->parsingElement->size() == 1)
            return new EndState(this->parsingElement);
        else
        {
            AppendState* appendState = new AppendState(this->parsingElement);
            return appendState->next(c);

            //TODO добавить добавление в др. массив или объект
        }
    } // TODO добавить обработку элементов массива
    else if (c == '\'' || c == '"')
    {
        this->parsingElement->push(new ArrayItemInfo);
        this->parsingElement->push(new StringInfo(c));
        return new StringState(this->parsingElement);
    }
    else if (c == '{')
    {
        this->parsingElement->push(new ArrayItemInfo);
        this->parsingElement->push(new ObjectInfo);
        return new ObjectState(this->parsingElement);
    }
    else if (std::isdigit(c))
    {
        this->parsingElement->push(new ArrayItemInfo);
        this->parsingElement->push(new NumberInfo);
        NumberState* numberState = new NumberState(this->parsingElement);
        return numberState->next(c);
    }
    else
    {
        throw new std::runtime_error("Invalid array parsing char: " + c); // TODO: change exception
    }
}