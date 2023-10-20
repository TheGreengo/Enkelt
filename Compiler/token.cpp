#include <string>

enum TokenType {
    INT,
    FLOAT,
    CHAR,
    STRING,
    BOOL,
    TYPE,
    KEY_WORD,
    VAR_NAME,
    FUNC_NAME
}

class Token {
    std::string name;

};