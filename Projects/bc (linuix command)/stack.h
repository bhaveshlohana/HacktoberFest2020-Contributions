#include "prototypes.h"
typedef struct stack {
	char *a[MAX];
	int i;
}stack;
/* The caller should ensure that
 * init() is called before any other function is called
 * isfull() is checked before push() is called
 * isemtpy() is checked before pop() is called 
 */
void init(stack *s);
void push(stack *s, char *no);
char *pop(stack *s);
int isempty(stack *s);
int isfull(stack *s);
int size(stack *s);