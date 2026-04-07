#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "parser.h"

static struct expr *make_number(int n) {
    struct expr *expr = malloc(sizeof(struct expr));
    if(expr == NULL)
        return NULL;
    expr->tpe = EXPR_NUMBER;
    expr->u.value = n;
    return expr;
}

static struct expr *make_var(char *name) {
    struct expr *expr = malloc(sizeof(struct expr));
    if(expr == NULL)
        return NULL;
    char *copy = strdup(name);
    if(copy == NULL) {
        free(expr);
        return NULL;
    }

    expr->tpe = EXPR_VAR;
    expr->u.name = copy;
    return expr;
}

static struct expr *make_binary_expr(enum token_type ttpe,
                                     struct expr *expr1,
                                     struct expr *expr2) {
    enum expr_type etpe;
    switch(ttpe) {
    case TOKEN_PLUS:
        etpe = EXPR_PLUS;
        break;
    case TOKEN_MINUS:
        etpe = EXPR_MINUS;
        break;
    case TOKEN_TIMES:
        etpe = EXPR_TIMES;
        break;
    case TOKEN_DIV:
        etpe = EXPR_DIV;
        break;
    default:
        return NULL;
    }

    struct expr *expr = malloc(sizeof(struct expr));
    if(expr == NULL)
        return NULL;

    expr->tpe = etpe;
    expr->u.p.left = expr1;
    expr->u.p.right = expr2;
    return expr;
}

void free_expr(struct expr *expr) {
    if(expr == NULL)
        return;

    switch(expr->tpe) {
    case EXPR_VAR:
        free(expr->u.name);
        break;
    case EXPR_PLUS:
    case EXPR_MINUS:
    case EXPR_TIMES:
    case EXPR_DIV:
        free_expr(expr->u.p.left);
        free_expr(expr->u.p.right);
        break;
    default:
        /* nothing */
    }
    free(expr);
}

static struct expr *getfactor(struct lexer *in) {
    struct token *token;
    token = peektoken(in);
    if(token->tpe == TOKEN_NUMBER) {
        struct expr *factor;
        token = gettoken(in);
        factor = make_number(token->u.value);
        free_token(token);
        if(factor == NULL)
            return NULL;
        return factor;
    } else if(token->tpe == TOKEN_VAR) {
        struct expr *factor;
        token = gettoken(in);
        factor = make_var(token->u.name);
        free_token(token);
        if(factor == NULL)
            return NULL;
        return factor;
    } else if(token->tpe == TOKEN_OPENPAR) {
        struct expr *expr;
        token = gettoken(in);
        expr = getexpr(in);
        free_token(token);
        if(expr == NULL)
            return NULL;
        return expr;
    } else {
        return NULL;
    }
}

static struct expr *getterm(struct lexer *in) {
    struct expr *expr1;
    expr1 = getfactor(in);
    if(expr1 == NULL)
        return NULL;
    if(expr1->tpe == EXPR_EOF) {
        return expr1;
    }

    struct token *token;
    token = peektoken(in);
    if(token->tpe == TOKEN_EOF || token->tpe == TOKEN_EOL)
        return expr1;

    if(token->tpe == TOKEN_TIMES || token->tpe == TOKEN_DIV) {
        struct expr *expr2;
        token = gettoken(in);
        expr2 = getterm(in);
        if(expr2 == NULL) {
            free(expr1);
            free_token(token);

            return NULL;
        }
        struct expr *expr;
        expr = make_binary_expr(token->tpe, expr1, expr2);
        if(expr == NULL) {
            free(expr1);
            free(expr2);
            free_token(token);
            return NULL;
        }
        free_token(token);
        return expr;
    } else {
        return expr1;
    }
}

struct expr *getexpr(struct lexer *in) {
    struct token *token;

    while(1) {
        token = peektoken(in);
        if(token->tpe != TOKEN_EOL)
            break;
        token = gettoken(in);
        free_token(token);
    }

    struct expr *expr1;
    expr1 = getterm(in);
    if(expr1 == NULL)
        return NULL;
    if(expr1->tpe == EXPR_EOF) {
        return expr1;
    }

    token = peektoken(in);
    if(token->tpe == TOKEN_EOF || token->tpe == TOKEN_EOL)
        return expr1;

    if(token->tpe == TOKEN_PLUS || token->tpe == TOKEN_MINUS) {
        struct expr *expr2;
        token = gettoken(in);
        expr2 = getexpr(in);
        if(expr2 == NULL) {
            free(expr1);
            free_token(token);
            return NULL;
        }
        struct expr *expr;
        expr = make_binary_expr(token->tpe, expr1, expr2);
        if(expr == NULL) {
            free(expr1);
            free(expr2);
            free_token(token);
            return NULL;
        }
        free_token(token);
        return expr;
    } else {
        return expr1;
    }
}
