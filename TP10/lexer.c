#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

static struct token *make_token(int tpe) {
    struct token *token;
    token = malloc(sizeof(struct token));
    if(token == NULL)
        return NULL;
    token->tpe = tpe;
    return token;
}

void free_token(struct token *token) {
    if(token == NULL)
        return;
    if(token->tpe == TOKEN_VAR)
        free(token->u.name);
    free(token);
}

static struct token *make_op(int op) {
    switch(op) {
    case '+': return make_token(TOKEN_PLUS);
    case '-': return make_token(TOKEN_MINUS);
    case '*': return make_token(TOKEN_TIMES);
    case '/': return make_token(TOKEN_DIV);
    default: return NULL;
    }
}

struct lexer {
    FILE *in;
    struct token *peeked;
};

struct lexer *make_lexer(FILE *in) {
    struct lexer *lexer = malloc(sizeof(struct lexer));
    lexer->in = in;
    lexer->peeked = NULL;
    return lexer;
}

void free_lexer(struct lexer *lexer) {
    if(lexer->peeked != NULL)
        free_token(lexer->peeked);
    free(lexer);
}

static struct token *getnumber(struct lexer *lexer, int c) {
    int n = c - '0';
    while(1) {
        int c = getc(lexer->in);
        if(c == EOF)
            break;
        if(c >= '0' && c <= '9') {
            n = n * 10 + c - '0';
        } else {
            ungetc(c, lexer->in);
            break;
        }
    }
    struct token *token = make_token(TOKEN_NUMBER);
    token->u.value = n;
    return token;
}

static struct token *getvar(struct lexer *lexer, int c) {
    char buf[1024];
    buf[0] = c;
    int n = 1;
    while(n < 1024 - 1) {
        int c = getc(lexer->in);
        if(c == EOF)
            break;
        if((c >= 'a' && c <= 'z') || c == '_') {
            buf[n++] = c;
        } else {
            ungetc(c, lexer->in);
            break;
        }
    }
    if(n == 1024)
        return NULL;
    char *s = malloc(n + 1);
    if(s == NULL)
        return NULL;
    memcpy(s, buf, n);
    s[n] = '\0';
    struct token *token = make_token(TOKEN_VAR);
    if(token == NULL) {
        free(s);
        return NULL;
    }
    token->u.name = s;
    return token;
}

struct token *gettoken(struct lexer *lexer) {
    if(lexer->peeked != NULL) {
        struct token *token = lexer->peeked;
        lexer->peeked = NULL;
        return token;
    }

    int c = getc(lexer->in);
    if(c == EOF)
        return make_token(TOKEN_EOF);

    if(c >= '0' && c <= '9')
        return getnumber(lexer, c);
    else if((c >= 'a' && c <= 'z') || c == '_')
        return getvar(lexer, c);
    else if(c == '(')
        return make_token(TOKEN_OPENPAR);
    else if(c == ')')
        return make_token(TOKEN_CLOSEPAR);
    else if(c == '+' || c == '-' || c == '*' || c == '/')
        return make_op(c);
    else if(c == '\n')
        return make_token(TOKEN_EOL);
    else {
        ungetc(c, lexer->in);
        return NULL;
    }
}

struct token *peektoken(struct lexer *lexer) {
    if(lexer->peeked != NULL)
        return lexer->peeked;

    struct token *token;
    token = gettoken(lexer);
    if(token == NULL)
        return NULL;

    lexer->peeked = token;
    return token;
}
