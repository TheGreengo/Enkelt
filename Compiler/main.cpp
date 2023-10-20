#include <iostream>
#include <fstream>
#include "lexer.cpp"


int main(int argc, char ** argv) {
    std::cout << "Enkelt compiler starting" << std::endl;

    Lexer lex = Lexer("test.txt");
    lex.run();

    std::cout << lex.toString() << std::endl;

    return 0;
}