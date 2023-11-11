#include <string>

enum TokenType {
    MAIN,              // main                            
    INT,               // Integer                         DONE
    FLOAT,             // Float                           DONE
    CHAR,              // Character                       NEEDS HELP WITH SPECIAL CHARACTERS
    STRING,            // String                          DONE
    BOOL,              // Boolean                         DONE
    FOR,               // for                             DONE
    WHILE,             // while                           DONE
    CLASS_DEC,         // class                           DONE
    VOID,              // void                            DONE
    INT_DEC,           // int                             DONE
    FLOAT_DEC,         // float                           DONE
    CHAR_DEC,          // char                            DONE
    STRING_DEC,        // string                          DONE
    BOOL_DEC,          // bool                            DONE
    FUNC,              // func                            DONE
    VAR_NAME,          // Variable name                   DONE
    MULT_SYM,          // *                               DONE
    ADD_SYM,           // +                               DONE
    SUB_SYM,           // -                               DONE
    EQU_SYM,           // ==                              DONE
    LES_SYM,           // <                               DONE
    GRT_SYM,           // >                               DONE
    COMMA,             // ,                               DONE
    PERIOD,            // .                               DONE
    REM_SYM,           // %                               DONE
    L_PAR,             // (                               DONE
    R_PAR,             // )                               DONE
    SEMI_COLON,        // ;                               DONE
    COLON,             // :                               DONE
    L_BRACK,           // [                               DONE
    R_BRACK,           // ]                               DONE
    L_BRACE,           // {                               DONE
    R_BRACE,           // }                               DONE
    FORW_SL,           // /                               DONE
    BACK_SL,           // reverse of above lolz           DONE   
    BARS,              // ||                              DONE
    P_EQ,              // %=                              DONE
    S_EQ,              // -=                              DONE
    M_EQ,              // *=                              DONE
    D_EQ,              // /=                              DONE
    R_EQ,              // %=                              DONE
    AND,               // &&                              DONE
    FILE_END,          // EOF                             DONE
    NOT,               // !                               DONE
    TILD,              // ~                               DONE
    BAR,               // |                               DONE
    ASSIGNMENT         // =                               DONE
};

class Token {
    public:
        std::string name;
        TokenType type;

        Token(std::string newName, TokenType newType) {
            name = newName;
            type = newType;
        };

        std::string toString() {
            std::string result = "";
            switch (type)
            {
            case MAIN:
                result.append("MAIN: ");
                break;
            case INT:
                result.append("INT: ");
                break;
            case FLOAT:
                result.append("FLOAT: ");
                break;
            case CHAR:
                result.append("CHAR: ");
                break;
            case STRING:
                result.append("STRING: ");
                break;
            case BOOL:
                result.append("BOOL: ");
                break;
            case VAR_NAME:
                result.append("VAR_NAME: ");
                break;
            case MULT_SYM:
                result.append("MULT_SYM: ");
                break;
            case ADD_SYM:
                result.append("ADD__SYM: ");
                break;
            case SUB_SYM:
                result.append("SUB_SYM: ");
                break;
            case REM_SYM:
                result.append("REM_SYM: ");
                break;
            case EQU_SYM:
                result.append("EQU_SYM: ");
                break;
            case LES_SYM:
                result.append("LES_SYM: ");
                break;
            case GRT_SYM:
                result.append("GRT_SYM: ");
                break;
            case COMMA:
                result.append("COMMA: ");
                break;
            case PERIOD:
                result.append("PERIOD: ");
                break;
            case L_PAR:
                result.append("L_PAR: ");
                break;
            case R_PAR:
                result.append("R_PAR: ");
                break;
            case SEMI_COLON:
                result.append("SEMI_COLON: ");
                break;
            case COLON:
                result.append("COLON: ");
                break;
            case L_BRACK:
                result.append("L_BRACK: ");
                break;
            case R_BRACK:
                result.append("R_BRACK: ");
                break;
            case L_BRACE:
                result.append("L_BRACE: ");
                break;
            case R_BRACE:
                result.append("R_BRACE: ");
                break;
            case FORW_SL:
                result.append("FORW_SL: ");
                break;
            case BACK_SL:
                result.append("BACK_SL: ");
                break;
            case BARS:
                result.append("BARS: ");
                break;
            case P_EQ:
                result.append("P_EQ: ");
                break;
            case S_EQ:
                result.append("S_EQ: ");
                break;
            case D_EQ:
                result.append("D_EQ: ");
                break;
            case M_EQ:
                result.append("M_EQ: ");
                break;
            case R_EQ:
                result.append("R_EQ: ");
                break;
            case AND:
                result.append("AND: ");
                break;
            case FILE_END:
                result.append("EOF: ");
                break;
            case ASSIGNMENT:
                result.append("ASSIGNMENT: ");
                break;
            case NOT:
                result.append("NOT: ");
                break;
            case TILD:
                result.append("TILD: ");
                break;
            case BAR:
                result.append("BAR: ");
                break;
            default:
                result.append("INVALID: ");
                break;
            }
            result.append(name);
            return result;
        }
};