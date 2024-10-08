cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME our-free-sequencer)
project(${PROJECT_NAME}
        VERSION 1.0
        LANGUAGES CXX)

option(TEST "Build test cases" OFF)
set(INCLUDE_CORE_DIRECTORY "src/core/" CACHE INTERNAL "Include header files of core" FORCE)

add_library(tools
            "${INCLUDE_CORE_DIRECTORY}tools/NumberTools.h")
set_target_properties(tools PROPERTIES LINKER_LANGUAGE CXX)

add_library(json
            "${INCLUDE_CORE_DIRECTORY}json/JSON.h"
            "${INCLUDE_CORE_DIRECTORY}json/JSON.cpp"

            "${INCLUDE_CORE_DIRECTORY}json/items/JsonItem.h"
            "${INCLUDE_CORE_DIRECTORY}json/items/CommonItem.h"
            "${INCLUDE_CORE_DIRECTORY}json/items/CommonItem.cpp"
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

            "${INCLUDE_CORE_DIRECTORY}json/meta/ArrayInfo.h"
            "${INCLUDE_CORE_DIRECTORY}json/meta/ArrayInfo.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/meta/ArrayItemInfo.h"
            "${INCLUDE_CORE_DIRECTORY}json/meta/ArrayItemInfo.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/meta/BoolInfo.h"
            "${INCLUDE_CORE_DIRECTORY}json/meta/BoolInfo.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/meta/MetaInfo.h"
            "${INCLUDE_CORE_DIRECTORY}json/meta/NumberInfo.h"
            "${INCLUDE_CORE_DIRECTORY}json/meta/NumberInfo.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/meta/ObjectInfo.h"
            "${INCLUDE_CORE_DIRECTORY}json/meta/ObjectInfo.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/meta/ObjectItemInfo.h"
            "${INCLUDE_CORE_DIRECTORY}json/meta/ObjectItemInfo.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/meta/StringInfo.h"
            "${INCLUDE_CORE_DIRECTORY}json/meta/StringInfo.cpp"

            "${INCLUDE_CORE_DIRECTORY}json/parser/AppendState.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/AppendState.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/parser/ArrayItemState.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/ArrayItemState.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/parser/ArrayState.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/ArrayState.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/parser/BoolState.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/BoolState.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/parser/EndState.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/EndState.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/parser/JsonParser.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/JsonParser.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/parser/NumberState.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/NumberState.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/parser/JsonParserState.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/JsonParserState.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/parser/ObjectItemState.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/ObjectItemState.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/parser/ObjectState.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/ObjectState.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/parser/StartState.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/StartState.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/parser/StringState.h"
            "${INCLUDE_CORE_DIRECTORY}json/parser/StringState.cpp"
            
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonAppendStateException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonAppendStateException.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonArrayItemStateException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonArrayItemStateException.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonCastTypeException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonCastTypeException.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonEmptyNextElementException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonEmptyNextElementException.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonNumberPointException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonNumberPointException.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonObjectItemDelimiterException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonObjectItemDelimiterException.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonParseException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonParseException.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonParseKeyException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonParseKeyException.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonTopElementException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonTopElementException.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonItemTypeException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonItemTypeException.cpp"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonTypeException.h"
            "${INCLUDE_CORE_DIRECTORY}json/exceptions/JsonTypeException.cpp")

add_library(bit
            "${INCLUDE_CORE_DIRECTORY}parser/bit/BitParser.h"
            "${INCLUDE_CORE_DIRECTORY}parser/bit/BitParser.cpp")
            
add_library(wav
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/WavParser.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/WavParser.cpp"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/samples/WavSample.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/samples/WavSample.cpp"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/samples/PcmSample.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/samples/PcmSample.cpp"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/WavFormatFactory.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/WavFormatFactory.cpp"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/formats/WavFormat.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/formats/WavFormat.cpp"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/formats/PcmFormat.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/formats/PcmFormat.cpp"

            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/interpolation/Interpolation.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/interpolation/Interpolation.cpp"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/interpolation/LinearInterpolation.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/interpolation/LinearInterpolation.cpp"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/interpolation/Fir.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/interpolation/Fir.cpp"

            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/chunks/FmtChunk.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/chunks/FmtChunk.cpp"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/chunks/PcmFmtChunk.h"

            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/exceptions/WavException.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/exceptions/WavHeaderException.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/exceptions/RiffException.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/exceptions/RiffException.cpp"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/exceptions/WaveException.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/exceptions/WaveException.cpp"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/exceptions/FormatChunkException.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/exceptions/FormatChunkException.cpp"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/exceptions/WaveUnknownFormatException.h"
            "${INCLUDE_CORE_DIRECTORY}parser/files/wav/exceptions/WaveUnknownFormatException.cpp")
target_link_libraries(wav PRIVATE bit)
target_link_libraries(wav PRIVATE tools)
target_include_directories(wav PRIVATE 
                            ${INCLUDE_CORE_DIRECTORY}
                            "${INCLUDE_CORE_DIRECTORY}parser/")

include("cmake/findPortAudio.cmake")

if(TEST)
    add_executable(test "tests/main.cpp")
    target_compile_features(test PUBLIC cxx_std_20)
    target_link_libraries(test PRIVATE json)
    target_link_libraries(test PRIVATE wav)

    if (${PORTAUDIO_FOUND})
        target_include_directories(test PRIVATE ${PORTAUDIO_INCLUDE_DIRS})
        target_link_libraries(test PRIVATE ${PORTAUDIO_LIBRARY})
    endif()
    
    target_include_directories(test
        PRIVATE
        ${INCLUDE_CORE_DIRECTORY}
        "${INCLUDE_CORE_DIRECTORY}parser/"
        "${INCLUDE_CORE_DIRECTORY}parser/files/"
        )
endif()
