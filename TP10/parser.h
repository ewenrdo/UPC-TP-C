enum expr_type {
    EXPR_NUMBER = 1,
    EXPR_VAR,
    EXPR_PLUS,
    EXPR_MINUS,
    EXPR_TIMES,
    EXPR_DIV,
    EXPR_EOF,
};

struct expr {
    enum expr_type tpe;
    union {
        int value;              // case EXPR_NUMBER
        char *name;             // case EPR_VAR
        struct {
            struct expr *left;
            struct expr *right;
        } p;
    } u;
};

struct expr *getexpr(struct lexer *in);
void free_expr(struct expr *expr);
