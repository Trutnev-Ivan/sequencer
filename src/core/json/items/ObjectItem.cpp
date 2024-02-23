#include "ObjectItem.h"
#include "ArrayItem.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdelete-incomplete"
ObjectItem::~ObjectItem()
{
    for (const auto& [key, tuple]: *this->value)
    {
        if (typeid(ArrayItem).hash_code() == std::get<0>(tuple).hash_code())
            delete static_cast<ArrayItem*>(std::get<1>(tuple));
        else if (typeid(ObjectItem) == std::get<0>(tuple))
            delete static_cast<ObjectItem*>(std::get<1>(tuple));
    }

    delete this->value;
}
#pragma GCC diagnostic pop