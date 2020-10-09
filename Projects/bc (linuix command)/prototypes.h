/*
*includes :
	*all header files
	*prototypes of my functions
	*hashdef file
*/
#ifndef _PROTOTYPESH_
#define _PROTOTYPESH_
#include "hashdefs.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "getoken.h"
#include "datatype.h"
#include "stack.h"
#include "cstack.h"
#include "getoken.h"
char* solvestring(char *line,  int* reset);
char* operation(char *a, char *b, char ch);
int solve(char x, char y, char z, int c);
token getnext(char *str, int *reset);
#endif