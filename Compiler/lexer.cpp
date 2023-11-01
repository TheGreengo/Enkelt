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

        bool isNum(char curr) {
            return (int(curr) <= 57)  && (int(curr) >= 48);
        }

        bool isAlpha(char curr) {
            return (int(curr) <= 90)  && (int(curr) >= 65) || (int(curr) <= 122)  && (int(curr) >= 97);
        }

        void run() {
            char curr;
            std::ifstream file(name);
        
            while (curr != EOF) {
                curr = file.get();
                if (curr == ':') {
                    tokens.push_back(Token(":", COLON));
                }
                else if (curr == ';') {
                    tokens.push_back(Token(";", SEMI_COLON));
                }
                else if (curr == '(') {
                    tokens.push_back(Token("(", L_PAR));
                }
                else if (curr == ')') {
                    tokens.push_back(Token(")", R_PAR));
                }
                else if (curr == '[') {
                    tokens.push_back(Token("[", L_BRACK));
                }
                else if (curr == ']') {
                    tokens.push_back(Token("]", R_BRACK));
                }
                else if (curr == '{') {
                    tokens.push_back(Token("{", L_BRACE));
                }
                else if (curr == '}') {
                    tokens.push_back(Token("}", R_BRACE));
                }
                else if (curr == '+') {
                    if (file.peek() == '=') {
                        tokens.push_back(Token("+=", P_EQ));
                        file.get();
                    } else {
                        tokens.push_back(Token("+", ADD_SYM));
                    }
                }
                else if (curr == '-') {
                    if (file.peek() == '=') {
                        tokens.push_back(Token("-=", S_EQ));
                        file.get();
                    } else {
                        tokens.push_back(Token("-", SUB_SYM));
                    }
                }
                else if (curr == '*') {
                    if (file.peek() == '=') {
                        tokens.push_back(Token("*=", M_EQ));
                        file.get();
                    } else {
                        tokens.push_back(Token("*", MULT_SYM));
                    }
                }
                else if (curr == '%') {
                    if (file.peek() == '=') {
                        tokens.push_back(Token("%=", R_EQ));
                        file.get();
                    } else {
                        tokens.push_back(Token("%", REM_SYM));
                    }
                }
                else if (curr == '=') {
                    if (file.peek() == '=') {
                        tokens.push_back(Token("==", EQU_SYM));
                        file.get();
                    } else {
                        tokens.push_back(Token("=", ASSIGNMENT));
                    }
                }
                else if (curr == '/') {
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
                else if (curr == '&') {
                    if (file.peek() == '&') {
                        tokens.push_back(Token("&&", AND));
                        file.get();
                    }
                }
                else if (curr == '|') {
                    if (file.peek() == '|') {
                        tokens.push_back(Token("||", BARS));
                        file.get();
                    }
                }
                else if (curr == '\\') {
                    tokens.push_back(Token("\\", BACK_SL));
                }
                else if (curr == ',') {
                    tokens.push_back(Token(",", COMMA));
                }
                else if (curr == '.') {
                    tokens.push_back(Token(".", PERIOD));
                }
                else if (curr == '>') {
                    tokens.push_back(Token(">", GRT_SYM));
                }
                else if (curr == '<') {
                    tokens.push_back(Token("<", LES_SYM));
                }
                else if (curr == EOF) {
                    tokens.push_back(Token("EOF", FILE_END));
                }
                else if (curr == '\'') {
                    curr = file.get();
                    if ((curr != '\'') && (file.peek() == '\'')) {
                        std::string word = "";
                        word += curr;
                        tokens.push_back(Token(word, CHAR));
                    }
                    curr = file.get();
                }
                else if (curr == '\"') {
                std::string word = "";
                    while (file.peek() != '\"') {
                        curr = file.get();
                        word += curr;
                    }
                    curr = file.get();
                    tokens.push_back(Token(word, STRING));
                }
                else if (isAlpha(curr)) {
                    bool valInt = true;
                    bool valFloat = true;
                }
                else if (isNum(curr)) {
                    std::string num = "";
                    num += curr;
                    bool per = false;
                    while(1) {
                        if (isNum(file.peek())) {
                            curr = file.get();
                            num += curr;
                        }
                        else if ((file.peek() == '.') && (!per)) {
                            curr = file.get();
                            num += curr;
                            per = true;
                        }
                        else {
                            break;
                        }
                    }
                    if (per) {
                        tokens.push_back(Token(num, FLOAT));
                    } else {
                        tokens.push_back(Token(num, INT));
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