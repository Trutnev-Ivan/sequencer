#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "parser/JsonParser.h"

class JSON
{
protected:
    ArrayItem* arrayItem;
    ObjectItem* objectItem;
    void parseFile(std::string path);
    void parseString(std::string value);
public:
    JSON();
    JSON(std::string value);
    ~JSON();
    bool isArray() const;
    bool isObject() const;
    CommonItem get(int index) const;
    CommonItem get(std::string key) const;
    int size() const;
    JSON* erase(int index);
    JSON* erase(int start, int end);
    JSON* erase(std::string key);
    bool contains(std::string key) const;
    CommonItem pop();
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& out, const JSON& json);
    friend std::ostream& operator<<(std::ostream& out, const JSON* json);
    friend std::ifstream& operator>>(std::ifstream& in, JSON& json);
    friend std::ifstream& operator>>(std::ifstream& in, JSON* json);
    CommonItem operator[](int index) const;
    CommonItem operator[](std::string key) const;

    template<class T>
    T* cast(int index) const
    {
        return this->arrayItem->cast<T>(index);
    }

    template<class T>
    T* cast(std::string key) const
    {
        return this->objectItem->cast<T>(key);
    }

    template<class T>
    JSON* push(T* item)
    {
        this->arrayItem->push_back<T>(item);
        return this;
    }

    template<class T>
    JSON* push(std::string key, T* item)
    {
        this->objectItem->push(key, item);
        return this;
    }

    template<class T>
    JSON* insert(int index, T* item)
    {
        this->arrayItem->insert<T>(index, item);
        return this;
    }
};