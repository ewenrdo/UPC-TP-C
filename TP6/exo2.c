#include <stdio.h>
#include <stdlib.h>

struct array
{
    int *a;
    int len;
};

struct array *new_array(int n)
{
    struct array *res = malloc(sizeof(struct array));
    if (res == NULL)
    {
        return NULL;
    }
    res->a = calloc(n, sizeof(int));
    if (res->a == NULL)
    {
        free(res);
        return NULL;
    }
    res->len = n;
    return res;
}

void destroy_array(struct array *a)
{
    free(a->a);
    free(a);
}

struct array *read_array(int n)
{
    struct array *res = new_array(n);
    if (res == NULL)
        return NULL;

    for (size_t i = 0; i < n; i++)
    {
        printf(">> ");
        scanf("%d", res->a + i);
        puts("");
    }

    return res;
}

void print_array(struct array *a) {
    for (size_t i = 0; i < a->len; i++)
    {
        printf("%d\n", *(a->a + i));
    }
    
}

void print_array_inverse(struct array *a) {
    
    for (int i = a->len - 1; i >= 0 ; i--)
    {
        printf("%d\n", *(a->a + i)); // équivalent à a->a[i]
    }
}

int main(void) {
    struct array* tableau = read_array(5);
    print_array(tableau);
    puts("============");
    print_array_inverse(tableau);
}