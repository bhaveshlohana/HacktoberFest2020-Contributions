#ifndef _DATATYPEH_
#define _DATATYPEH_
#include "hashdefs.h"
typedef struct Num {
	char arr[MIN];
	int ni, nf, sign;
}Num;
/*
*The no would be stored as chars in a dcll 
*with Num as well as float part
*ni = No. of Num digits
*nf = No. of floating digits
*/
void initNum(Num *a);
Num createNumFromString(char *a);
char *createStringFromNum(Num a);
char *addNum(char *a, char *b);
char *substractNum(char *a, char *b);
char *mulscalNum(char *a, char b);
char *mulNum(char *a, char *b);
char *divNum(char *a, char *b, char x);
char *rightshiftNum(char *a, int b);
char *leftshiftNum(char *a, int b);
char *powNum(char *a, char *b);
double trignomet(char *a, int func);
int compare(char *a, char *b);
void removeZeroFromFront(char *a);
void getnum(char *a, char *b);
void division(char *a, char *b, char *c, char *d);
void quotient(char *a, char *b, char *c, char *d);
char  *leftShift(char *str1, char *str2);
char  *rightShift(char *str1, char *str2);
double sine(double x);
double cosine(double x);
#endif