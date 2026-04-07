#include <stdio.h>
#include "lexer.h"
#include "parser.h"
void print_expr(struct expr *expr);
int eval_expr(struct expr *expr);
// Tests
int main()
{
    struct lexer *lexer;
    struct expr *expr;
    lexer = make_lexer(stdin);
    expr = getexpr(lexer);
    if (expr == NULL)
    {
        fprintf(stderr, "Erreur!\n");
        return 1;
    }

    print_expr(expr);
    printf("\n");
    printf("Résultat: %d\n", eval_expr(expr));
    struct expr *der = derive_expr(expr, "x");
    print_expr(der);

    free_expr(expr);
    free_lexer(lexer);
    return 0;
}

// Implémentation

int eval_expr(struct expr *expr)
{
    int res = 0;
    int gauche = 0;
    int droite = 0;
    if (expr == NULL)
    {
        return res;
    }
    if (expr->tpe == EXPR_VAR)
    {
        return res;
    }
    else if (expr->tpe == EXPR_NUMBER)
    {
        return expr->u.value;
    }
    else
    {
        switch (expr->tpe)
        {
        case EXPR_EOF:
            return res;
        case EXPR_PLUS:
            gauche = eval_expr(expr->u.p.left);
            droite = eval_expr(expr->u.p.right);
            res = gauche + droite;
            break;
        case EXPR_DIV:
            gauche = eval_expr(expr->u.p.left);
            droite = eval_expr(expr->u.p.right);
            if (droite == 0)
            {
                puts("Erreur : division par 0, le résultat sera incorrect.");
                return 0;
            }
            res = gauche / droite;
            break;
        case EXPR_MINUS:
            gauche = eval_expr(expr->u.p.left);
            droite = eval_expr(expr->u.p.right);
            res = gauche - droite;
            break;
        case EXPR_TIMES:
            gauche = eval_expr(expr->u.p.left);
            droite = eval_expr(expr->u.p.right);
            res = gauche * droite;
            break;
        default:
            break;
        }
    }
    return res;
}

void print_expr(struct expr *expr)
{
    if (expr == NULL)
    {
        return;
    }
    if (expr->tpe == EXPR_VAR)
    {
        printf("%s", expr->u.name);
    }
    else if (expr->tpe == EXPR_NUMBER)
    {
        printf("%d", expr->u.value);
    }
    else
    {
        printf("(");
        switch (expr->tpe)
        {
        case EXPR_PLUS:
            print_expr(expr->u.p.left);
            printf("+");
            print_expr(expr->u.p.right);
            break;
        case EXPR_DIV:
            print_expr(expr->u.p.left);
            printf("/");
            print_expr(expr->u.p.right);
            break;
        case EXPR_MINUS:
            print_expr(expr->u.p.left);
            printf("-");
            print_expr(expr->u.p.right);
            break;
        case EXPR_TIMES:
            print_expr(expr->u.p.left);
            printf("*");
            print_expr(expr->u.p.right);
            break;
        default:
            break;
        }
        printf(")");
    }
}