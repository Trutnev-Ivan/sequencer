#include <json/items/StringItem.h>
#include <json/items/IntItem.h>
#include <json/items/FloatItem.h>
#include <json/items/BoolItem.h>
#include <json/items/ArrayItem.h>
#include <json/items/ObjectItem.h>
#include "../Test.h"

class JsonItemTest: public Test
{
public:
    virtual void run() override
    {
        ASSERT_EQUALS(json::StringItem("value").getValue(), "value");
        ASSERT_EQUALS(json::StringItem("text").getValue(), "text");
        ASSERT_EQUALS(json::StringItem("1234qwer").getValue(), "1234qwer");

        ASSERT_FLOATS_ARE_SAME(json::FloatItem(2.3).getValue(), 2.3f);
        ASSERT_FLOATS_ARE_SAME(json::FloatItem(2).getValue(), 2.f);
        ASSERT_FLOATS_ARE_SAME(json::FloatItem(1.00023328).getValue(), 1.00023328f);
        ASSERT_FLOATS_ARE_SAME(json::FloatItem(-2.3).getValue(), -2.3f);
        ASSERT_FLOATS_ARE_SAME(json::FloatItem(-2).getValue(), -2.f);
        ASSERT_FLOATS_ARE_SAME(json::FloatItem(-1.00023328).getValue(), -1.00023328f);

        ASSERT_TRUE(json::BoolItem(true).getValue());
        ASSERT_FALSE(json::BoolItem(false).getValue());

        ASSERT_EQUALS(json::IntItem(2).getValue(), 2);
        ASSERT_EQUALS(json::IntItem(10234).getValue(), 10234);
        ASSERT_EQUALS(json::IntItem(-2).getValue(), -2);
        ASSERT_EQUALS(json::IntItem(-10234).getValue(), -10234);

        json::ArrayItem arrayItem;
        ASSERT_EQUALS(arrayItem.getLength(), 0);
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.push_back<json::StringItem>(new json::StringItem("test")););
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.push_back<json::IntItem>(new json::IntItem(5)););
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.push_back<json::FloatItem>(new json::FloatItem(-2.5)););
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.push_back<json::BoolItem>(new json::BoolItem(false)););
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.push_back<json::ObjectItem>(new json::ObjectItem););
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.push_back<json::ArrayItem>(new json::ArrayItem););
        ASSERT_EQUALS(arrayItem.getLength(), 6);
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.push_back<json::StringItem>(new json::StringItem("qwer")););
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.push_back<json::StringItem>(new json::StringItem("sacasd")););
        ASSERT_THROWS_EXCEPTION(arrayItem.push_back<std::string>(new std::string("qwerty")), json::JsonItemTypeException);
        ASSERT_THROWS_EXCEPTION(arrayItem.push_back<int>(new int(5)), json::JsonItemTypeException);
        ASSERT_THROWS_EXCEPTION(arrayItem.push_back<float>(new float(5)), json::JsonItemTypeException);
        ASSERT_THROWS_EXCEPTION(arrayItem.push_back<double>(new double(5)), json::JsonItemTypeException);
        ASSERT_THROWS_EXCEPTION(arrayItem.push_back<bool>(new bool(5)), json::JsonItemTypeException);
        ASSERT_THROWS_EXCEPTION(arrayItem.push_back<char>(new char('c')), json::JsonItemTypeException);
        ASSERT_THROWS_EXCEPTION(arrayItem[30], std::out_of_range);
        ASSERT_THROWS_EXCEPTION(arrayItem.cast<json::IntItem>(0), json::JsonCastTypeException);
        ASSERT_EQUALS(arrayItem.cast<json::StringItem>(0)->getValue(), "test");
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.push_back<json::IntItem>(new json::IntItem(2)););
        json::IntItem* intItem = arrayItem.pop<json::IntItem>();
        ASSERT_EQUALS(intItem->getValue(), 2);
        delete intItem;
        ASSERT_THROWS_EXCEPTION(arrayItem.pop<json::BoolItem>(), json::JsonCastTypeException);
        int arrayLength = arrayItem.getLength();
        ASSERT_THROWS_EXCEPTION(arrayItem.insert<std::string>(1, new std::string("TEST")), json::JsonItemTypeException);
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.insert<json::StringItem>(1, new json::StringItem("VALUE")));
        ASSERT_EQUALS(arrayItem.getLength(), arrayLength + 1);
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.erase(0));
        ASSERT_EQUALS(arrayItem.getLength(), arrayLength);
        ASSERT_NO_THROWS_EXCEPTION(arrayItem.erase(arrayItem.begin(), arrayItem.end()));
        ASSERT_EQUALS(arrayItem.getLength(), 0);

        json::ObjectItem objectItem;
        ASSERT_EQUALS(objectItem.getLength(), 0);
        ASSERT_NO_THROWS_EXCEPTION(objectItem.push<json::StringItem>("string", new json::StringItem("test")));
        ASSERT_NO_THROWS_EXCEPTION(objectItem.push<json::IntItem>("int", new json::IntItem(1)));
        ASSERT_NO_THROWS_EXCEPTION(objectItem.push<json::FloatItem>("float", new json::FloatItem(2.5)));
        ASSERT_NO_THROWS_EXCEPTION(objectItem.push<json::BoolItem>("bool", new json::BoolItem(true)));
        ASSERT_NO_THROWS_EXCEPTION(objectItem.push<json::ObjectItem>("object", new json::ObjectItem));
        ASSERT_NO_THROWS_EXCEPTION(objectItem.push<json::ArrayItem>("array", new json::ArrayItem));
        ASSERT_EQUALS(objectItem.getLength(), 6);
        ASSERT_THROWS_EXCEPTION(objectItem.push<std::string>("val", new std::string("val")), json::JsonItemTypeException);
        ASSERT_THROWS_EXCEPTION(objectItem.push<int>("val", new int(2)), json::JsonItemTypeException);
        ASSERT_THROWS_EXCEPTION(objectItem.push<float>("val", new float(2.523f)), json::JsonItemTypeException);
        ASSERT_THROWS_EXCEPTION(objectItem.push<double>("val", new double(-34.92)), json::JsonItemTypeException);
        ASSERT_THROWS_EXCEPTION(objectItem.push<bool>("val", new bool(false)), json::JsonItemTypeException);
        ASSERT_THROWS_EXCEPTION(objectItem.push<char>("val", new char('c')), json::JsonItemTypeException);
        ASSERT_TRUE(objectItem.contains("string"));
        ASSERT_FALSE(objectItem.contains("key"));
        ASSERT_NO_THROWS_EXCEPTION(objectItem.cast<json::StringItem>("string"));
        ASSERT_THROWS_EXCEPTION(objectItem.cast<std::string>("string"), json::JsonCastTypeException);
        ASSERT_THROWS_EXCEPTION(objectItem.cast<json::IntItem>("string"), json::JsonCastTypeException);
        ASSERT_THROWS_EXCEPTION(objectItem.cast<json::FloatItem>("string"), json::JsonCastTypeException);
        ASSERT_THROWS_EXCEPTION(objectItem.cast<json::BoolItem>("string"), json::JsonCastTypeException);
        ASSERT_THROWS_EXCEPTION(objectItem.cast<json::ArrayItem>("string"), json::JsonCastTypeException);
        ASSERT_THROWS_EXCEPTION(objectItem.cast<json::ObjectItem>("string"), json::JsonCastTypeException);
        int objectLength = objectItem.getLength();
        ASSERT_NO_THROWS_EXCEPTION(objectItem.erase("string"));
        ASSERT_EQUALS(objectItem.getLength(), objectLength - 1);
        ASSERT_NO_THROWS_EXCEPTION(objectItem.erase(objectItem.begin(), objectItem.end()));
        ASSERT_EQUALS(objectItem.getLength(), 0);
    }
};