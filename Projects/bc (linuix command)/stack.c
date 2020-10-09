#include "prototypes.h"
void init(stack *s) {
	s->i = 0;
}
void push(stack *s, char *no) {
	s->a[s->i] = malloc(strlen(no) + 10);
    strcpy(s->a[s->i], no);
    s->i++;
}
char *pop(stack *s) {
	char *t = s->a[s->i - 1];
	s->i--;
	return t;
}
int isempty(stack *s) {
	return s->i == 0;
}
int isfull(stack *s) {
	return s->i == MAX;
}
int size(stack *s) {
    return s->i;
}