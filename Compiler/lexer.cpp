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
                if (curr == ':') {
                    tokens.push_back(Token(":", COLON));
                }
                if (curr == ';') {
                    tokens.push_back(Token(";", SEMI_COLON));
                }
                if (curr == '(') {
                    tokens.push_back(Token("(", L_PAR));
                }
                if (curr == ')') {
                    tokens.push_back(Token(")", R_PAR));
                }
                if (curr == '[') {
                    tokens.push_back(Token("[", L_BRACK));
                }
                if (curr == ']') {
                    tokens.push_back(Token("]", R_BRACK));
                }
                if (curr == '{') {
                    tokens.push_back(Token("{", L_BRACE));
                }
                if (curr == '}') {
                    tokens.push_back(Token("}", R_BRACE));
                }
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
                        tokens.push_back(Token("==", EQU_SYM));
                        file.get();
                    } else {
                        tokens.push_back(Token("=", ASSIGNMENT));
                    }
                }
                if (curr == '/') {
                    if (file.peek() == '/') {
                        while (curr != '\n') {
                            curr = file.get();
                        }
                    }
                    else if (file.peek() == '*') {
                        while (!((curr == '*') && (file.peek() == '/'))) {
                            curr = file.get();
                        }
                        file.get();
                    }
                    else if (file.peek() == '=') {
                        tokens.push_back(Token("/=", D_EQ));
                        file.get();
                    } 
                    else if (file.peek() == '/') { 
                        while (curr != '\n') {
                            curr = file.get();
                        }
                    }
                    else {
                        tokens.push_back(Token("/", FORW_SL));
                    }
                }
                if (curr == '&') {
                    if (file.peek() == '&') {
                        tokens.push_back(Token("&&", AND));
                        file.get();
                    }
                }
                if (curr == '|') {
                    if (file.peek() == '|') {
                        tokens.push_back(Token("||", OR));
                        file.get();
                    }
                }
                if (curr == '\\') {
                    tokens.push_back(Token('\\', BACK_SL));
                }
                if (curr == ',') {
                    tokens.push_back(Token(',', COMMA));
                }
                if (curr == '.') {
                    tokens.push_back(Token('.', PERIOD));
                }
                if (curr == '>') {
                    tokens.push_back(Token('>', GRT_SYM));
                }
                if (curr == '<') {
                    tokens.push_back(Token('<', LES_SYM));
                }
                if (curr == EOF) {
                    tokens.push_back(Token(EOF, FILE_END));
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