#include "JSON.h"

JSON::JSON()
{

}

JSON::JSON(std::string value)
{
    if (std::filesystem::is_regular_file(value))
        this->parseFile(value);
    else
        this->parseString(value);
}

JSON::~JSON()
{
    delete this->arrayItem;
    delete this->objectItem;
}

void JSON::parseFile(std::string path)
{
    if (!std::filesystem::exists(path))
        throw std::ifstream::failure("File " + path + " not exists");

    if (std::filesystem::path(path).extension() != ".json")
        throw std::ifstream::failure("File extension must be .json");

    std::ifstream* file = new std::ifstream(path);
    JsonParser* parser = new JsonParser(file);

    if (parser->isArray())
        this->arrayItem = parser->getArray();
    else if (parser->isObject())
        this->objectItem = parser->getObject();
    else
        throw JsonTopElementException();

    file->close();
    delete file;
    delete parser;
}

void JSON::parseString(std::string value)
{
    JsonParser* parser = new JsonParser(value);

    if (parser->isArray())
        this->arrayItem = parser->getArray();
    else if (parser->isObject())
        this->objectItem = parser->getObject();
    else
        throw JsonTopElementException();

    delete parser;
}

bool JSON::isArray() const
{
    return this->arrayItem != nullptr;
}

bool JSON::isObject() const
{
    return this->objectItem != nullptr;
}

CommonItem JSON::get(int index) const
{
    return this->arrayItem->get(index);
}

CommonItem JSON::get(std::string key) const
{
    return this->objectItem->get(key);
}

int JSON::size() const
{
    if (this->isArray())
        return this->arrayItem->getLength();
    else
        return this->objectItem->getLength();
}

JSON* JSON::erase(int index)
{
    this->arrayItem->erase(index);
    return this;
}

JSON* JSON::erase(int start, int end)
{
    this->arrayItem->erase(start, end);
    return this;
}

JSON* JSON::erase(std::string key)
{
    this->objectItem->erase(key);
    return this;
}

bool JSON::contains(std::string key) const
{
    return this->objectItem->contains(key);
}

CommonItem JSON::pop()
{
    return this->arrayItem->pop();
}

std::string JSON::toString() const
{
    if (this->isArray())
        return this->arrayItem->toString();
    
    return this->objectItem->toString();
}

std::ostream& operator<<(std::ostream& out, const JSON& json)
{
    out << json.toString();
    return out;
}

std::ostream& operator<<(std::ostream& out, const JSON* json)
{
    out << json->toString();
    return out;
}

CommonItem JSON::operator[](int index) const
{
    return this->get(index);
}

CommonItem JSON::operator[](std::string key) const
{
    return this->get(key);
}

std::ifstream& operator>>(std::ifstream& in, JSON& json)
{
    JsonParser* parser = new JsonParser(&in);

    if (parser->isArray())
        json.arrayItem = parser->getArray();
    else if (parser->isObject())
        json.objectItem = parser->getObject();
    else
        throw JsonTopElementException();

    return in;
}

std::ifstream& operator>>(std::ifstream& in, JSON* json)
{
JsonParser* parser = new JsonParser(&in);

    if (parser->isArray())
        json->arrayItem = parser->getArray();
    else if (parser->isObject())
        json->objectItem = parser->getObject();
    else
        throw JsonTopElementException();

    return in;
}