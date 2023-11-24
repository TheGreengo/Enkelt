#include <iostream>
#include <fstream>
#include <string>
#include "lexer.cpp"

int main(int argc, char ** argv) {
    if (argc < 2) {
        std::cout << "Error: please provide name of file to be compiled." \
        << std::endl;
        return 1;
    }

    Lexer lex(argv[1]);

    try {
        lex.run();
    } catch (std::string err) {
        std::cout << "Parsing error: " << err << std::endl;
        return 2;
    }

    std::string oFile = argc > 2 ? argv[2] : "a.txt";

    std::ofstream out(oFile);

    out << lex.toString() << std::endl;

    out.close();

    std::cout << "Enkelt compiler finished. Results output to " << oFile << std::endl;

    return 0;
}