enum token_type {
    TOKEN_NUMBER = 1,
    TOKEN_VAR,
    TOKEN_OPENPAR,
    TOKEN_CLOSEPAR,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_TIMES,
    TOKEN_DIV,
    TOKEN_EOL,
    TOKEN_EOF,
};

struct token {
    enum token_type tpe;
    union {
        int value;              // case TOKEN_NUMBER
        char *name;             // case TOKEN_VAR
    } u;
};

void free_token(struct token *token);

struct lexer;

struct lexer *make_lexer(FILE *in);
void free_lexer(struct lexer *lexer);
struct token *gettoken(struct lexer *lexer);
struct token *peektoken(struct lexer *lexer);
