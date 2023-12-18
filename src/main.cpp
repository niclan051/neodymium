#include <fstream>
#include <iostream>
#include <sstream>

#include "tokens.h"
#include "utils.h"

using namespace neodymium;
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Incorrect usage, expected: neodym <filename>";
        return EXIT_FAILURE;
    }
    std::ifstream file(argv[1]);
    std::stringstream contents_stream;
    contents_stream << file.rdbuf();
    file.close();
    std::string contents = contents_stream.str();
    for (const token& token : tokenizer::tokenize(contents)) {
        std::cout << token.getTypeName() << ':' << token.getValue().value()
                  << " ";
    }
    return EXIT_SUCCESS;
}
