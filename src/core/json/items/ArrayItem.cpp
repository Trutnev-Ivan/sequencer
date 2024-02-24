#include "ArrayItem.h"
#include "ObjectItem.h"
#include "StringItem.h"
#include "BoolItem.h"
#include "FloatItem.h"
#include "IntItem.h"
#include <cstring>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdelete-incomplete"
ArrayItem::~ArrayItem()
{
    for (int i = 0; i < this->value->size(); ++i)
    {
        CommonItem item = this->value->at(i);

        if (typeid(ArrayItem).hash_code() == item.getType()->hash_code())
            delete static_cast<ArrayItem*>(item.getItem());
        else if (typeid(ObjectItem).hash_code() == item.getType()->hash_code())
            delete static_cast<ObjectItem*>(item.getItem());
    }

    delete this->value;
}
#pragma GCC diagnostic pop

std::type_index* ArrayItem::getType(int index)
{
    return this->get(index).getType();
}

int ArrayItem::getLength()
{
    return this->value->size();
}

std::string ArrayItem::toString() const
{
    std::string str = "[";

    for (CommonItem item: *this->value)
    {   
        if (typeid(StringItem).hash_code() == item.getType()->hash_code())
            str += static_cast<StringItem*>(item.getItem())->toString() + ", ";
        else if (typeid(ArrayItem).hash_code() == item.getType()->hash_code())
            str += static_cast<ArrayItem*>(item.getItem())->toString() + ", ";
        else if (typeid(BoolItem).hash_code() == item.getType()->hash_code())
            str += static_cast<BoolItem*>(item.getItem())->toString() + ", ";
        else if (typeid(FloatItem).hash_code() == item.getType()->hash_code())
            str += static_cast<FloatItem*>(item.getItem())->toString() + ", ";
        else if (typeid(IntItem).hash_code() == item.getType()->hash_code())
            str += static_cast<IntItem*>(item.getItem())->toString() + ", ";
        else if (typeid(ObjectItem).hash_code() == item.getType()->hash_code())
            str += static_cast<ObjectItem*>(item.getItem())->toString() + ", ";
    }
    
    str += "\b\b]";

    return str;
}

std::ostream& operator<<(std::ostream& out, const ArrayItem& arrayItem)
{
    out << arrayItem.toString();
    return out;
}

std::ostream& operator<<(std::ostream& out, const ArrayItem* arrayItem)
{
    out << arrayItem->toString();
    return out;
}

CommonItem ArrayItem::get(int index)
{
    return this->value->at(index);
}

CommonItem ArrayItem::pop()
{
    CommonItem item = this->get(this->getLength() - 1);
    this->getValue()->pop_back();
    return item;
}

std::vector<CommonItem>::const_iterator ArrayItem::begin()
{
    return this->value->begin();
}

std::vector<CommonItem>::const_iterator ArrayItem::end()
{
    return this->value->end();
}

void ArrayItem::erase(int index)
{
    this->value->erase(this->begin() + index);
}

void ArrayItem::erase(std::vector<CommonItem>::const_iterator iterator)
{
    this->value->erase(iterator);
}

void ArrayItem::erase(int start, int end)
{
    this->value->erase(this->begin() + start, this->begin() + end);
}

void ArrayItem::erase(
        std::vector<CommonItem>::const_iterator startIterator,
        std::vector<CommonItem>::const_iterator endIterator
        )
        {
            this->value->erase(startIterator, endIterator);
        }

CommonItem ArrayItem::operator[](int index)
{
    return this->get(index);
}