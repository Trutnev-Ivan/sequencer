#pragma once

#include <typeindex>

class CommonItem
{
protected:
    std::type_index* type;
    void* item;
    int size;
public:
    CommonItem();
    CommonItem(CommonItem& item);
    CommonItem(const CommonItem& item);
    CommonItem(CommonItem* item);
    ~CommonItem();
    void* getItem() const;
    std::type_index* getType() const;
    int getSize() const;

    template<class T>
    void init(T* item)
    {
        this->item = static_cast<void*>(item);
        this->type = new std::type_index(typeid(T));
        this->size = sizeof(T);
    }
};