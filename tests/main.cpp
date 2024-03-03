#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <json/JSON.h>

#include <vector>
#include <tuple>

int main()
{
/*
    try
    {
        ArrayItem* subItem = new ArrayItem;

        subItem
        ->push_back<StringItem>(new StringItem("str1"))
        ->push_back<StringItem>(new StringItem("str2"))
        ->push_back<StringItem>(new StringItem("str3"))
        ->push_back<StringItem>(new StringItem("str4"));

        item.push_back<StringItem>(new StringItem("test"))
        ->push_back<IntItem>(new IntItem(3))
        ->push_back<FloatItem>(new FloatItem(3.5))
        ->push_back<ArrayItem>(subItem)
        ->push_back<BoolItem>(new BoolItem(true));
        
        obj->push<StringItem>("key1", new StringItem("test"))
            ->push<IntItem>("key2", new IntItem(3))
            ->push<ArrayItem>("array", subItem);

        item.insert<StringItem>(1, new StringItem("INSERTED VALLUE"));
        item.insert<ObjectItem>(3, obj);

        //std::cout << static_cast<StringItem*>(item[0].getItem()) << std::endl << std::endl;

        //std::cout << item << std::endl;


        //StringItem* i = item.cast<StringItem>(0);
        //std::cout << i << std::endl;
        //StringItem* i_ = item.cast<StringItem>(1);
        //std::cout << i_ << std::endl;
 

        std::cout << item << std::endl << std::endl;
        delete subItem;
    }
    catch (JsonTypeException* e)
    {
        std::cout << e->what() << std::endl;
    }
    catch (JsonCastTypeException* e)
    {
        std::cout << e->what() << std::endl;
    }
*/

    std::string path = "E:/Project/our-free-sequencer/bin/test.json";
    
    //JSON json(path);
    JSON json;
    std::ifstream file(path);
    file >> json;
    
    std::cout << json.cast<ObjectItem>(1)->cast<ArrayItem>("ar") << std::endl;
    //out.close();


    //ArrayItem item(StringItem(path), FloatItem(10.3), IntItem(3), BoolItem(true));

    //std::cout << std::filesystem::exists(path) << std::endl;
    //std::cout << ::static_cast<JsonItem>(vec[0]) << std::endl;
    std::cin.get();

    return EXIT_SUCCESS;
}