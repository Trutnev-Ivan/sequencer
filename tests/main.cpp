#include "TestManager.h"
#include "json/JsonItemTest.h"
#include "json/JsonTest.h"

int main(int argc, char** argv)
{
    TestManager testManager;
    testManager.add(new JsonItemTest);
    testManager.add(new JsonTest);
    
    testManager.run();
    
    return EXIT_SUCCESS;
}