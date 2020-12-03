#include "prototypes.h"
#include "datatype.h"
double trignomet(char *str, int func);
int readline(char *line, int len) {
	int i = 0;
	char ch;
	while(((ch = getchar()) != '\n') && ch != -1 && i < len - 1)
		if(ch != ' ')
			line[i++] = ch;
	line[i] = '\0';
	return i;
}
int main() {
	char line[MAX], prev[MAX], trig[10], c;
	char *res = NULL;
	printf("\n\t\t\t\t\t\t\t\t\t");
	printf("BC\n");
	printf("\t\t\t\t\t\t");
	printf("This is free software with ABSOLUTELY NO WARRANTY\n");
	printf("\t\t\t\t\t\t\t");
	printf("For options and instructions type 'help'\n");
	printf("\t\t\t\t\t\t\t");
	printf("For details type `warranty'.\n"); 
	int y = 0;
	help :
	while(readline(line, MAX)) {
		int reset = 1, new = 0, ans = 0, i, j = 0, len;
		c = *line;
		double x;
		len = strlen(line);
		switch(c) {
			case 'h':
				if(strlen(line) == 4) {
					strncpy(trig, line, 4);
					strcat(trig, "");
					if (!strcmp(trig, "help")) {
						int fd;
						char ch;
						fd = open("help.txt",  O_RDONLY);	
						if(fd == -1) {
							printf("file missing\n");
							goto help;
						}
						while(read(fd, &ch, 1))
							putchar(ch);
						close(fd);
						printf("\n\n");
					}
					else {
						res = malloc(6);
						strcpy(res, "error");
						new = 1;
					}
				}
				else {
					res = malloc(6);
					strcpy(res, "error");
					new = 1;
				}
				goto help;
				break;
			case 'w':
				if(strlen(line) == 8) {
					strncpy(trig, line, 8);
					strcat(trig, "");
					if (!strcmp(trig, "warranty")) {
						int fd;
						char ch;
						fd = open("warranty.txt",  O_RDONLY);
						if(fd == -1) {
							printf("file missing\n");
							goto help;
						}	
						while(read(fd, &ch, 1))
							putchar(ch);
						printf("\n\n\n");
					}
					else {
						res = malloc(6);
						strcpy(res, "error");
						new = 1;
					}
				}
				else {
					res = malloc(6);
					strcpy(res, "error");
					new = 1;
				}
				goto help;
				break;
			case 's': case 'c': case 't':
				if(*(line + 3) >= 48 && *(line + 3) <= 57) {
					for (i = 0; i < 3; i++)
						trig[i] = line[i];
					trig[3] = '\0';
					//strncpy(trig, line, 3);
					//strcat(trig, "");
					while(j + 3 <= len) {
						line[j] = line[j + 3];
						j++;
					}
					if (!strcmp(trig,"sin")) {
						x = trignomet(line, SIN);
						new = 1;
						ans = 1;
					}
					else if (!strcmp(trig,"cos")) {
						x = trignomet(line, COS);
						new = 1;
						ans = 1;
					}
					else if (!strcmp(trig,"tan")) {
						x = trignomet(line, TAN);
						new = 1;
						ans = 1;
					}
					else if (!strcmp(trig,"csc")) {
						x = trignomet(line, COSEC);
						new = 1;
						ans = 1;
					}
					else if (!strcmp(trig,"sec")) {
						x = trignomet(line, SEC);
						new = 1;
						ans = 1;
					}
					else if (!strcmp(trig,"cot")) {
						x = trignomet(line, COT);
						new = 1;
						ans = 1;
					}
				}
				else {
					res = malloc(6);
					strcpy(res, "error");
					new = 1;
				}
					break;
			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
			case '8': case '9': case '-': case'(':
			case '^':
				res = solvestring(line, &reset);
				new = 1;
				break;
			case '.' :
				if (strlen(line) == 1) {
					new = 0;
					if(!ans && y) {
						if (strcmp(res ,"error") != 0)
							printf("%s\n", prev);
						else
							printf("%lf\n", x);
					}
					/*else {
						printf("sorry!!! Last Result Not Defined\n");
						goto help;
					}*/
				}
				else {
					res = solvestring(line, &reset);
					new =  1;
				}
				break;
			default : 
					res = malloc(6);
					strcpy(res, "error");
					new = 1;
		}
		if(new) {
			if(!ans) {
				if ((strcmp(res ,"error") != 0)) {
            		printf("%s\n", res);
            		if((*res >= 48) && (*res <= 57)) {
            			strcpy(prev, res);
            			y = 1;
            		}
				}
        		else
        			printf("(standard_in) : syntax error\n");
        		free(res);
        	}
        	else
        		printf("%lf\n", x);
    	}
    }
	return 0;
}