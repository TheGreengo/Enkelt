#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "token.cpp"

// OK, before I get too far along, I need to think about how this actually is going to work
// For this lexer, here's my thought, it takes each char and then checks what tokens 

class Lexer {
    std::ifstream file;
    std::vector<TokenType> tokens;

    Lexer(std::string loadFile) {
        file = std::ifstream(loadFile);
    }

    ~Lexer() { 
        file.close(); 
    }

    std::vector<TokenType> run() {
        char curr;
    
        while (curr != EOF) {
            curr = file.get();
            std::cout << curr;
        }

        return tokens;
    }

    bool isWhite(char curr) {
        return curr == ' ' || curr == '\t' || curr == '\n' || curr == '\r';
    }
};