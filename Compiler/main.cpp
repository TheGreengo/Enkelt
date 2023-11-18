#include <iostream>
#include <fstream>
#include "lexer.cpp"


int main(int argc, char ** argv) {
    std::cout << "Enkelt compiler starting" << std::endl;

    Lexer lex("zztest.txt");
    try {
        lex.run();
    } catch (std::string err) {
        return 1;
    }

    std::cout << lex.toString() << std::endl;

    std::cout << "Enkelt compiler finished" << std::endl;

    return 0;
}