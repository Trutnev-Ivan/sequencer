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

    std::tuple<int> t {2};

    //std::vector<std::tuple<int>>* v = new std::vector<std::tuple<int>>;
    //v->insert(v->begin() + 0, t);

    ArrayItem item;

    try
    {
        ArrayItem* subItem = new ArrayItem;

        subItem->push_back<StringItem>(new StringItem("str1"))
        ->push_back<StringItem>(new StringItem("str2"))
        ->push_back<StringItem>(new StringItem("str3"))
        ->push_back<StringItem>(new StringItem("str4"));

        item.push_back<StringItem>(new StringItem("test"))
        ->push_back<IntItem>(new IntItem(3))
        ->push_back<FloatItem>(new FloatItem(3.5))
        ->push_back<ArrayItem>(subItem)
        ->push_back<BoolItem>(new BoolItem(true));
        
        item.insert<StringItem>(1, new StringItem("INSERTED VALLUE"));

        std::cout << static_cast<StringItem*>(item[0].getItem()) << std::endl << std::endl;

        std::cout << item << std::endl;

        StringItem* i = item.cast<StringItem>(0);
        std::cout << i << std::endl;
        StringItem* i_ = item.cast<StringItem>(1);
        std::cout << i_ << std::endl;
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