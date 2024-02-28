#include "AppendState.h"

JsonParserState* AppendState::appendToObject(MetaInfo* metaInfo)
{
    ObjectItemInfo* objectItemInfo = static_cast<ObjectItemInfo*>(metaInfo);
    ObjectInfo* objectInfo = static_cast<ObjectInfo*>(this->parsingElement->top());

    objectInfo->appendItem(objectItemInfo);

    return new ObjectState(this->parsingElement);
}

JsonParserState* AppendState::appendToObjectItem(MetaInfo* metaInfo)
{
    ObjectItemInfo* objectItemInfo = static_cast<ObjectItemInfo*>(this->parsingElement->top());
    objectItemInfo->setValue(metaInfo);

    return new ObjectItemState(this->parsingElement);
}