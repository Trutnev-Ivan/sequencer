#include "JsonParser.h"

JsonParser::JsonParser(std::ifstream* file)
{
    this->parsingElement = new std::stack<MetaInfo*>;
    JsonParserState* state = new StartState(this->parsingElement);

    while (!file->eof())
    {
        char c = file->get();
        state = state->next(c);
    }

    std::cout << state->getTopElement()->toString() << std::endl;
    delete state;
}