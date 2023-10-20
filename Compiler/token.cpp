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
    MULT_SYM,
    ADD_SYM,
    SUB_SYM,
    EQU_SYM,
    LES_SYM,
    GRT_SYM,
    COMMA,
    PERIOD,
    L_PAR,
    R_PAR,
    SEMI_COLON,
    COLON,
    L_BRACK,
    R_BRACK,
    L_BRACE,
    R_BRACE,
    FORW_SL,
    BACK_SL,
    D_QUOTE,
    S_QUOTE,
    BAR
}

class Token {
    std::string name;
    TokenType type;

    Token() { this->name, this->type };

    std::string toString() {
        std::string result = "";
        result.append(name);
        switch (type)
        {
        case INT:
            result.append(": INT");
            break;
        case FLOAT:
            result.append(": FLOAT");
            break;
        case CHAR:
            result.append(": CHAR");
            break;
        case STRING:
            result.append(": STRING");
            break;
        case BOOL:
            result.append(": BOOL");
            break;
        case TYPE:
            result.append(": TYPE");
            break;
        case KEY_WORD:
            result.append(": KEY_WORD");
            break;
        case VAR_NAME:
            result.append(": VAR_NAME");
            break;
        case MULT_SYM:
            result.append(": MULT_SYM");
            break;
        case ADD_SYM:
            result.append(": ADD__SYM");
            break;
        case SUB_SYM:
            result.append(": SUB_SYM");
            break;
        case EQU_SYM:
            result.append(": EQU_SYM");
            break;
        case LES_SYM:
            result.append(": LES_SYM");
            break;
        case GRT_SYM:
            result.append(": GRT_SYM");
            break;
        case COMMA:
            result.append(": COMMA");
            break;
        case PERIOD:
            result.append(": PERIOD");
            break;
        case L_PAR:
            result.append(": L_PAR");
            break;
        case R_PAR:
            result.append(": R_PAR");
            break;
        case SEMI_COLON:
            result.append(": SEMI_COLON");
            break;
        case COLON:
            result.append(": COLON");
            break;
        case L_BRACK:
            result.append(": L_BRACK");
            break;
        case R_BRACK:
            result.append(": R_BRACK");
            break;
        case L_BRACE:
            result.append(": L_BRACE");
            break;
        case R_BRACE:
            result.append(": R_BRACE");
            break;
        case FORW_SL:
            result.append(": FORW_SL");
            break;
        case BACK_SL:
            result.append(": BACK_SL");
            break;
        case D_QUOTE:
            result.append(": D_QUOTE");
            break;
        case S_QUOTE:
            result.append(": S_QUOTE");
            break;
        case BAR:
            result.append(": BAR");
            break;
        default:
            result.append("INVALID");
            break;
        }
    }
};