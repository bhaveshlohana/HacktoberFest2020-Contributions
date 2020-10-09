#ifndef _CSTACK_
#define _CSTACK_
typedef struct cstack {
	char a[100];
	int i;
}cstack;
/* The caller should ensure that
 * init() is called before any other function is called
 * isfull() is checked before push() is called
 * isemtpy() is checked before pop() is called 
 */
void cinit(cstack *s);
void cpush(cstack *s, char no);
char cpop(cstack *s);
int cisempty(cstack *s);
int cisfull(cstack *s);
char ctop(cstack *s);
void printstack(cstack s);
#endif
