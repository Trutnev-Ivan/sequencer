#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <json/JSON.h>
#include <json/items/ArrayItem.h>
#include <json/items/IntItem.h>
#include <json/items/FloatItem.h>
#include <json/items/BoolItem.h>
#include <json/items/StringItem.h>

#include <vector>
#include <tuple>

int main()
{
    std::string path = "E:/Project/our-free-sequencer/bin";

    ArrayItem item;

    try
    {
        ArrayItem* subItem = new ArrayItem;

        subItem->push_back<StringItem>(new StringItem("str1"));
        subItem->push_back<StringItem>(new StringItem("str2"));
        subItem->push_back<StringItem>(new StringItem("str3"));
        subItem->push_back<StringItem>(new StringItem("str4"));

        item.push_back<StringItem>(new StringItem("test"));
        item.push_back<IntItem>(new IntItem(3));
        item.push_back<FloatItem>(new FloatItem(3.5));
        item.push_back<ArrayItem>(subItem);
        item.push_back<BoolItem>(new BoolItem(true));

        std::cout << item << std::endl;

        //StringItem* i = item.cast<StringItem>(0);
        //std::cout << i << std::endl;
    }
    catch (JsonTypeException* e)
    {
        std::cout << e->what() << std::endl;
    }
    catch (JsonCastTypeException* e)
    {
        std::cout << e->what() << std::endl;
    }

    JSON json(path);
    //ArrayItem item(StringItem(path), FloatItem(10.3), IntItem(3), BoolItem(true));

    //std::cout << std::filesystem::exists(path) << std::endl;
    //std::cout << ::static_cast<JsonItem>(vec[0]) << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}