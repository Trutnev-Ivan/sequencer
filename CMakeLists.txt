cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME our-free-sequencer)
project(${PROJECT_NAME}
        VERSION 1.0
        LANGUAGES CXX)

option(TEST "Build test cases" OFF)
set(INCLUDE_CORE_DIRECTORY "src/core/" CACHE INTERNAL "Include header files of core" FORCE)

add_library(json
            "${INCLUDE_CORE_DIRECTORY}json/JSON.h"
            "${INCLUDE_CORE_DIRECTORY}json/JSON.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/items/JsonItem.h"
            "${INCLUDE_CORE_DIRECTORY}json/items/StringItem.h"
            "${INCLUDE_CORE_DIRECTORY}json/items/StringItem.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/items/IntItem.h"
            "${INCLUDE_CORE_DIRECTORY}json/items/IntItem.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/items/FloatItem.h"
            "${INCLUDE_CORE_DIRECTORY}json/items/FloatItem.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/items/ObjectItem.h"
            "${INCLUDE_CORE_DIRECTORY}json/items/ObjectItem.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/items/ArrayItem.h"
            "${INCLUDE_CORE_DIRECTORY}json/items/ArrayItem.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/items/BoolItem.h"
            "${INCLUDE_CORE_DIRECTORY}json/items/BoolItem.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonTypeException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonTypeException.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonCastTypeException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonCastTypeException.cpp")

if(TEST)
    add_executable(test "tests/main.cpp")
    target_compile_features(test PUBLIC cxx_std_20)
    target_link_libraries(test PRIVATE json)
    target_include_directories(test
        PRIVATE
        ${INCLUDE_CORE_DIRECTORY})
endif()
