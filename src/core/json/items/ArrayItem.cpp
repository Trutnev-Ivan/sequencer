#include "ArrayItem.h"
#include "ObjectItem.h"
#include "StringItem.h"
#include "BoolItem.h"
#include "FloatItem.h"
#include "IntItem.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdelete-incomplete"
ArrayItem::~ArrayItem()
{
    for (int i = 0; i < this->value->size(); ++i)
    {
        std::tuple<const std::type_info&, void*> tuple = this->value->at(i);

        if (typeid(ArrayItem).hash_code() == std::get<0>(tuple).hash_code())
            delete static_cast<ArrayItem*>(std::get<1>(tuple));
        else if (typeid(ObjectItem).hash_code() == std::get<0>(tuple).hash_code())
            delete static_cast<ObjectItem*>(std::get<1>(tuple));
    }

    delete this->value;
}
#pragma GCC diagnostic pop

const std::type_info& ArrayItem::getType(int index)
{
    return std::get<0>(this->get(index));
}

int ArrayItem::getLength()
{
    return this->value->size();
}

std::string ArrayItem::toString()
{
    std::string str = "[";
    for (std::tuple<const std::type_info&, void*> tuple: *this->value)
    {
        if (typeid(StringItem).hash_code() == std::get<0>(tuple).hash_code())
            str += static_cast<StringItem*>(std::get<1>(tuple))->toString() + ", ";
        else if (typeid(ArrayItem).hash_code() == std::get<0>(tuple).hash_code())
            str += static_cast<ArrayItem*>(std::get<1>(tuple))->toString() + ", ";
        else if (typeid(BoolItem).hash_code() == std::get<0>(tuple).hash_code())
            str += static_cast<BoolItem*>(std::get<1>(tuple))->toString() + ", ";
        else if (typeid(FloatItem).hash_code() == std::get<0>(tuple).hash_code())
            str += static_cast<FloatItem*>(std::get<1>(tuple))->toString() + ", ";
        else if (typeid(IntItem).hash_code() == std::get<0>(tuple).hash_code())
            str += static_cast<IntItem*>(std::get<1>(tuple))->toString() + ", ";
        else if (typeid(ObjectItem).hash_code() == std::get<0>(tuple).hash_code())
            str += static_cast<ObjectItem*>(std::get<1>(tuple))->toString() + ", ";
    }
    str += "\b\b]";

    return str;
}

std::ostream& operator<<(std::ostream& out, ArrayItem arrayItem)
{
    out << arrayItem.toString();
    return out;
}

std::ostream& operator<<(std::ostream& out, ArrayItem* arrayItem)
{
    out << arrayItem->toString();
    return out;
}

std::tuple<const std::type_info&, void*> ArrayItem::get(int index)
{
    return this->value->at(index);
}