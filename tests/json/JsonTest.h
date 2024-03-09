#pragma once
#include "../Test.h"
#include <json/JSON.h>

class JsonTest: public Test
{
public:
    virtual void run() override
    {
        json::JSON* Json;

        ASSERT_NO_THROWS_EXCEPTION(Json = new json::JSON("[]"));
        delete Json;
        ASSERT_NO_THROWS_EXCEPTION(Json = new json::JSON("{}"));
        delete Json;
        ASSERT_NO_THROWS_EXCEPTION(Json = new json::JSON("{'value': true}"));
        delete Json;
        ASSERT_NO_THROWS_EXCEPTION(Json = new json::JSON("{'string': 'str', 'bool': false, 'int': -32, 'float': 12.324, 'array': [1, 'sate'], 'obj': {'key': 'value'}}"));
        delete Json;
        ASSERT_NO_THROWS_EXCEPTION(Json = new json::JSON("[1, 2, 3, 4]"));
        delete Json;
        ASSERT_NO_THROWS_EXCEPTION(Json = new json::JSON("[1, -2.324, 'string', true, false, [1, -3, 2.3, 'va', false, {}], {'key': 'value'}]"));
        delete Json;
        ASSERT_NO_THROWS_EXCEPTION(Json = new json::JSON("{'asfvx': 'test'}"));
        delete Json;
        ASSERT_NO_THROWS_EXCEPTION(Json = new json::JSON("[1, false, 'string', 4.323, [1,23], {'key': 23}]"));
        delete Json;
        ASSERT_NO_THROWS_EXCEPTION(Json = new json::JSON("{'value': 'asqw'}"));
        delete Json;

        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("[1, 2, 3, ]"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("[,1, 2, 3]"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("[1 2 3]"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("1, 2, 3]"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("[1, 2, 3"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("[asdcasdw]"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("[tru]"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("[fals]"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("[1, false, 'string, 4.323, [1,23], {'key': 23}]"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("[1, false, string', 4.323, [1,23], {'key': 23}]"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("[1, false, string, 4.323, [1,23], {'key': 23}]"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("{'value': true,}"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("{'value: true}"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("'value': true}"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("{'value': true"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("{value': true}"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("{value: true}"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("{: 'value'}"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("{:}"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("{'value': "), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON(""), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("1"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("true"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("false"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("1.23"), json::JsonException);
        ASSERT_THROWS_EXCEPTION(Json = new json::JSON("qwxcwe"), json::JsonException);

        ASSERT_NO_THROWS_EXCEPTION(Json = new json::JSON("{'string': 'str', 'bool': false, 'int': -32, 'float': 12.324, 'array': [1, 'sate'], 'obj': {'key': 'value'}}"));
        ASSERT_FALSE(Json->isArray());
        ASSERT_TRUE(Json->isObject());
        ASSERT_THROWS_EXCEPTION(Json->cast<json::IntItem>("string"), json::JsonCastTypeException);
        ASSERT_THROWS_EXCEPTION(Json->cast<json::StringItem>(0), json::JsonTypeException);
        ASSERT_NO_THROWS_EXCEPTION(Json->cast<json::StringItem>("string"));
        ASSERT_EQUALS(Json->cast<json::StringItem>("string")->getValue(), "str");
        ASSERT_EQUALS(Json->cast<json::BoolItem>("bool")->getValue(), false);
        ASSERT_EQUALS(Json->cast<json::IntItem>("int")->getValue(), -32);
        ASSERT_FLOATS_ARE_SAME(Json->cast<json::FloatItem>("float")->getValue(), 12.324f);
        ASSERT_EQUALS(Json->cast<json::ArrayItem>("array")->cast<json::IntItem>(0)->getValue(), 1);
        ASSERT_EQUALS(Json->cast<json::ArrayItem>("array")->cast<json::StringItem>(1)->getValue(), "sate");
        ASSERT_EQUALS(Json->cast<json::ObjectItem>("obj")->cast<json::StringItem>("key")->getValue(), "value");
        ASSERT_THROWS_EXCEPTION(Json->erase(Json->arrayBegin(), Json->arrayEnd()), json::JsonTypeException);
        ASSERT_NO_THROWS_EXCEPTION(Json->erase(Json->objectBegin(), Json->objectEnd()));
        ASSERT_EQUALS(Json->size(), 0);
        delete Json;

        ASSERT_NO_THROWS_EXCEPTION(Json = new json::JSON("[1, -23.34, 'string', true, [5, false], {'qwer': 42}]"));
        ASSERT_FALSE(Json->isObject());
        ASSERT_TRUE(Json->isArray());
        ASSERT_THROWS_EXCEPTION(Json->cast<json::StringItem>(0), json::JsonCastTypeException);
        ASSERT_THROWS_EXCEPTION(Json->cast<json::IntItem>("val"), json::JsonTypeException);
        ASSERT_NO_THROWS_EXCEPTION(Json->cast<json::IntItem>(0));
        ASSERT_EQUALS(Json->cast<json::IntItem>(0)->getValue(), 1);
        ASSERT_EQUALS(Json->cast<json::FloatItem>(1)->getValue(), -23.34f);
        ASSERT_EQUALS(Json->cast<json::StringItem>(2)->getValue(), "string");
        ASSERT_EQUALS(Json->cast<json::BoolItem>(3)->getValue(), true);
        ASSERT_EQUALS(Json->cast<json::ArrayItem>(4)->cast<json::IntItem>(0)->getValue(), 5);
        ASSERT_EQUALS(Json->cast<json::ArrayItem>(4)->cast<json::BoolItem>(1)->getValue(), false);
        ASSERT_EQUALS(Json->cast<json::ObjectItem>(5)->cast<json::IntItem>("qwer")->getValue(), 42);
        ASSERT_THROWS_EXCEPTION(Json->erase(Json->objectBegin(), Json->objectEnd()), json::JsonTypeException);
        ASSERT_NO_THROWS_EXCEPTION(Json->erase(Json->arrayBegin(), Json->arrayEnd()));
        ASSERT_EQUALS(Json->size(), 0);
        delete Json;
    }
};