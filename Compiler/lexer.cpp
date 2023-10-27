#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "token.cpp"

class Lexer {
    public:
        std::string name;
        std::vector<Token> tokens;

        Lexer(std::string filename) : name(filename) { }

        ~Lexer() { }

        void run() {
            char curr;
            std::ifstream file(name);
        
            while (curr != EOF) {
                curr = file.get();
                if (curr == '+') {
                    if (file.peek() == '=') {
                        tokens.push_back(Token("+=", P_EQ));
                        file.get();
                    } else {
                        tokens.push_back(Token("+", ADD_SYM));
                    }
                }
                if (curr == '-') {
                    if (file.peek() == '=') {
                        tokens.push_back(Token("-=", S_EQ));
                        file.get();
                    } else {
                        tokens.push_back(Token("-", SUB_SYM));
                    }
                }
                if (curr == '*') {
                    if (file.peek() == '=') {
                        tokens.push_back(Token("*=", M_EQ));
                        file.get();
                    } else {
                        tokens.push_back(Token("*", MULT_SYM));
                    }
                }
                if (curr == '%') {
                    if (file.peek() == '=') {
                        tokens.push_back(Token("%=", R_EQ));
                        file.get();
                    } else {
                        tokens.push_back(Token("%", REM_SYM));
                    }
                }
                if (curr == '=') {
                    if (file.peek() == '=') {
                        tokens.push_back(Token("=", R_EQ));
                        file.get();
                    } else {
                        tokens.push_back(Token("%", REM_SYM));
                    }
                }
            }
            file.close();
        }

        std::string toString() {
            std::string result;
            for (int i = 0; i < tokens.size(); i++) {
                result += tokens[i].toString();
                if (tokens.size() - i > 1) {
                    result += '\n';
                }
            }
            return result;
        }

        bool isWhite(char curr) {
            return curr == ' ' || curr == '\t' || curr == '\n' || curr == '\r';
        }
};