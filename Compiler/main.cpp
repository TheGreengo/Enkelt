#include <iostream>
#include <fstream>
#include "lexer.cpp"


int main(int argc, char ** argv) {
    if (argc < 2) {
        std::cout << "Error: please provide name of file to be compiled." \
        << std::endl;
        return 1;
    }

    std::cout << "Enkelt compiler starting" << std::endl;

    Lexer lex(argv[1]);

    try {
        lex.run();
    } catch (std::string err) {
        std::cout << "Parsing error: " << err << std::endl;
        return 2;
    }

    std::cout << lex.toString() << std::endl;

    std::cout << "Enkelt compiler finished" << std::endl;

    return 0;
}