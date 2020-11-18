#include	<stdio.h>
#include	<string.h>

#define	MAX_ITEMS	20
#define	MAX_LEN		30

#define	OPEN_BRACKET	'('
#define	CLOSE_BRACKET	')'
/*
#define IS_OPERAND(char ch)	return((ch >= 'A' && ch <= 'Z') ? 1 : 0));
*/
struct Stack
{
	char Items[MAX_ITEMS][MAX_LEN];
	int Top;
};

void	InitStack (struct Stack *ptr);
int		IsEmpty (struct Stack *ptr);
int		IsFull (struct Stack *ptr);
void	Push (struct Stack *ptr, char *element);
int	Pop(struct Stack *ptr, char *ptr2);

void	InitStack (struct Stack *ptr)
{
	
	ptr->Top = -1;
}

int		IsEmpty (struct Stack *ptr)
{
	if (ptr->Top == -1)
		return (1);
	else
		return (0);
}

int		IsFull (struct Stack *ptr)
{
	if (ptr->Top == MAX_ITEMS - 1)
		return (1);
	else
		return (0);	
}
void	Push (struct Stack *ptr, char element[MAX_LEN])
{
	if (IsFull (ptr))
	{
		printf ("Stack overflow\n");
	}
	else
	{
		ptr->Top++;
		strcpy (ptr->Items[ptr->Top] , element);
	}
}

int	Pop(struct Stack *ptr, char *ptr2)
{
	int flag;
	if (IsEmpty (ptr))
	{
		flag = 0;
	}
	else
	{
		strcpy (ptr2 , ptr->Items[ptr->Top]);
		ptr->Top--;
		flag = 1;
	}
	
	return (flag);
}

int		IsOperand (char ch)
{
	int Operand = 0;
	/*
	if (ch >= 'A' && ch <= 'Z')
		Operand = 1;
	*/
	return((ch >= 'A' && ch <= 'Z') ? 1 : 0);
	/*
	return (Operand);
	*/
	
}

int		IsOperator (char ch)
{
	int Operator = 0;
	
	if (ch == '+' || ch == '-'|| ch == '*' || ch == '/')
		Operator = 1;
	
	return (Operator);
	
}

void	PostfixToInfix (char *Postfix, char *Infix)
{
	struct Stack OpndStk;
	char symbol;
	char expr[MAX_LEN], Opnd1[MAX_LEN], Opnd2[MAX_LEN];
	
	InitStack (&OpndStk);
	strcpy (Infix, "\0");
	
	while ((symbol = *Postfix)!= '\0')
	{
		if(IsOperand (symbol))
		{
			sprintf (expr, "%c", symbol);
			Push(&OpndStk, expr);
		}
		else if (IsOperator (symbol))
		{
			Pop(&OpndStk, Opnd2);
			Pop(&OpndStk, Opnd1);
			
			sprintf (expr,"(%s %c %s )", 
				Opnd1, symbol, Opnd2);
			Push (&OpndStk, expr);
		}
		
		Postfix++;
	}
	
	Pop(&OpndStk,Infix);
}


void	main()
{
	char Infix [MAX_LEN], Postfix[MAX_LEN] ;
	
	strcpy (Postfix, "AB+");
	PostfixToInfix (Postfix, Infix);
	puts (Infix);
	getchar();
}

