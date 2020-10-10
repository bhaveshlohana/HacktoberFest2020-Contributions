#include "prototypes.h"
/* input: a postfix string, possibly with errors
 * output: the 'next' token from string, separated on operator
 * type: OPERAND, OPERATOR, END, ERROR
 */
enum states {START, DIG, OP, STOP, ERR};
token getnext(char *str, int *reset) {
    int currstate = START;
    int nextstate;
    static int i = 0, prev = CHECK;
    token t;
    int j = 0;
    char currchar, currop;
    if(*reset == 1) {
        *reset = 0;
        i = 0;
        prev = CHECK;
    }
    if(prev == CHECK) {
        if(*(str + i) == '-') {
            t.arr[j++] = '-';
            i++;
        }
    }
    while(1) {
        currchar = str[i];
        switch(currstate) {
            case START:
                switch(currchar) {
                    case '0': case '1': case '2':
                    case '3': case '4': case '5':
                    case '7': case '8': case '9':
                    case '6': case '.':
                        nextstate = DIG;
                        t.arr[j++] = str[i];
                        break;
                    case '+': case '-': case '*':
                    case '/': case '%': case '(':
                    case ')': case '^': case '<': case '>':
                        nextstate = OP;
                        currop = currchar;
                        break;
                    case '\0':
                        nextstate = STOP;
                        break;
                    default:
                        t.type = ERROR;
                        return t;
                        break;
                }
                break;
            case DIG:
                switch(currchar) {
                    case '0': case '1': case '2':
                    case '3': case '4': case '5':
                    case '7': case '8': case '9':
                    case '6': case '.':
                        nextstate = DIG;
                       t.arr[j++] = str[i];
                        break;
                    case '+': case '-': case '*':
                    case '/': case '%': case ')':
                    case '(': case '^': case '<': case '>':
                        t.type = OPERAND;
                        t.arr[j] = '\0';
                        prev = UNCHECK;
                        return t;
                        break;
                    case '\0':
                        t.type = OPERAND;
                        t.arr[j] = '\0';
                        prev = UNCHECK;
                        return t;
                        break;
                    default:
                        t.type = OPERAND;
                        t.arr[j] = '\0';
                        prev = UNCHECK;
                        return t;
                        break;
                }
                break;
            case OP:
                switch(currchar) {
                    case '0': case '1': case '2':
                    case '3': case '4': case '5':
                    case '7': case '8': case '9':
                    case '6': case '.':
                        t.type = OPERATOR;
                        t.op = currop;
                        prev = CHECK;
                        return t;
                        break;
                    case '+': case '-': case '*':
                    case '/': case '%': case '(':
                    case ')': case '^': case '<': case '>':
                        t.type = OPERATOR;
                        t.op = currop;
                        prev = CHECK;
                        return t;
                        break;
                    case '\0':
                        t.type = OPERATOR;
                        t.op = currop;
                        prev = CHECK;
                        return t;
                        break;
                    default:
                        t.type = OPERATOR;
                        t.op = currop;
                        prev = CHECK;
                        return t;
                        break;
                }
            case STOP:
                t.type = END;
                return t;
                break;
            case ERR:
                t.type = ERROR;
                return t;
                break;
        }
        currstate = nextstate;
        i++;
    }
}
/*
*input : the string entered by the user
*processing : gets tokens from getnext
*stores the operators in 1 stack precedence wise
*stores the number(string) in another stack
*gets the operation performed untill the operator
 stack is empty
*returns the string when it is the last string
*/
char* solvestring(char *expr, int* reset) {
	token t;
	stack s;
	cstack cs;
	init(&s);
	cinit(&cs);
	char prevop, *num1, *num2, *num3;
	while(1) {
		t = getnext(expr, reset);
		if(t.type == OPERAND)
				push(&s, t.arr);
		else if(t.type == OPERATOR) {
			/*
			*while prevop != ( 
			*pop previous operator (prevop)
			*pop two numbers and perform prevop on them
			*push the result into stack
			*push current operator
			*/
			if(t.op == ')') {
				prevop = ctop(&cs);
				while(prevop != '(') {
					prevop = cpop(&cs);
					if(!isempty(&s)) 
						num2 = pop(&s);
					if(!isempty(&s))
						num1 = pop(&s);
					num3 =  operation(num1, num2, prevop);
					free(num1);
					free(num2);
					push(&s, num3);
					if(!cisempty(&cs))
						prevop = ctop(&cs);
					else
						break;
				}
				prevop = cpop(&cs);
			}
			/*
			*while precedence of previous >= precedence of current 
			*pop previous operator (prevop)
			*pop two numbers and perform prevop on them
			*push the result into stack
			*push current operator
			*/
			else if(!cisempty(&cs)) {
				prevop = ctop(&cs); 
				while(precedence(prevop) > precedence(t.op)) {
					prevop = cpop(&cs);
					if(!isempty(&s))
						num2 = pop(&s);
					if(!isempty(&s))
						num1 = pop(&s);
					num3 =  operation(num1, num2, prevop);
					free(num1);
					free(num2);
					push(&s, num3);
					if(!cisempty(&cs))
						prevop = ctop(&cs);
					else
						break;
				}
			}
			if(!cisfull(&cs) && t.op != ')')
				cpush(&cs, t.op);
			else if (t.op != ')'){
				strcpy(num3, "error");
				return num3;
			}
		}
		else if(t.type == END) {
			while(!cisempty(&cs)) {
				prevop = cpop(&cs);
				if(!isempty(&s))
					num2 = pop(&s);
				if(!isempty(&s))
					num1 = pop(&s);
				num3 =  operation(num1, num2, prevop);
				free(num1);
				free(num2);
				push(&s, num3);
			}
			break;	
		}
		else if(t.type == ERROR) {
			num3 = malloc(6); 
			strcpy(num3, "error");
			return num3;
		}
	}
	if((!isempty(&s)) && (cisempty(&cs))) {
		num3 = pop(&s);
		return num3;
	}
	else {
		num3 = malloc(7); 
		strcpy(num3, "error");
		return num3;
	}
}
/*
*receives two strings(numbers) and an operator
*calls the function depending on the operator 
*returns the result
*/
char *operation(char* a, char* b, char ch) {
	char *c;
	switch(ch) {
		case '+' :
			c = addNum(a, b);
			break;
		case '-' :
			c = substractNum(a, b);
			break;
		case '*' :
			c = mulNum(a, b);
			break;
		case '/' :
			c = divNum(a, b, '/');
			break;
		case '%' :
			c = divNum(a, b, '%');
			break;
		case '^' :
			c = powNum(a, b);
			break;
		case '<' :
			c = leftShift(a, b);
			break;
		case '>' :
			c = rightShift(a, b);
			break;
	}
	return c;
}
/*
*Gives the precedence of operators
*/
int precedence(char op) {
	switch(op) {
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
		case '%':
			return 3;
		case '^':
			return 4;
		case '(':
			return 0;
	}
	return INT_MIN;
}