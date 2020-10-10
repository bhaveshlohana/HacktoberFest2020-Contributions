#ifndef _GETOKENH_
#define _GETOKENH_
typedef struct token{
    int type;
    char arr[MAX];
    char op;
}token;
token getnext(char *str, int *reset);
int precedence(char op);
#endif