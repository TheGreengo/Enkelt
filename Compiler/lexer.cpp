#include <iostream>
#include <fstream>
#include <string>

class Lexer {
    std::ifstream file;

    Lexer(std::string loadFile) {
        file = std::ifstream(loadFile);
    }

    ~Lexer() { 
        file.close(); 
    }

    void run() {
        
    }
};