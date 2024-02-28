#include "ObjectItemState.h"

void ObjectItemState::parseKey(char c)
    {
        ObjectItemInfo* objectItemInfo = static_cast<ObjectItemInfo*>(this->parsingElement->top());

        if (objectItemInfo->getKeyQuotesType() == c)
        {
            if (objectItemInfo->isEscaped())
                objectItemInfo->appendToKey(c);
            else
            {
                objectItemInfo->endKeyParse();
                isFilledKey = true;
            }
        }
        else
        {
            objectItemInfo->appendToKey(c);
        }
    }

    void ObjectItemState::parseDelimiter(char c)
    {
        if (std::isspace(c))
            return;
        
        if (c == ':')
        {
            hasDelimiter = true;
            return;
        }
        
        throw new std::runtime_error("Error parsing delimiter char: " + c); // TODO: change error type
    }

    JsonParserState* ObjectItemState::parseValue(char c)
    {
        if (std::isspace(c))
            return this;

        if (c == '\'' || c == '"')
        {
            this->parsingElement->push(new StringInfo(c));
            return new StringState(this->parsingElement);
        }
        else if (c == '{')
        {
            this->parsingElement->push(new ObjectInfo);
            return new ObjectState(this->parsingElement);
        }

        //TODO: добавить парсинг для др. типов
    }

    JsonParserState* ObjectItemState::parseEnd(char c)
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
        else if (c == '}')
        {
            AppendState* appendState = new AppendState(this->parsingElement);
            JsonParserState* next = appendState->next(c);

            delete appendState;
            return next->next(c);
        }

        throw new std::runtime_error("Error end parsing obj item: " + c); // TODO: change error type
    }