#include "prototypes.h"
int ii = 0, j = 0;		//for division
/*
*used in division 
*copies a char(digit) from dividend into
*other string for comparision
*/
void getnum(char *str1, char *str2) {
	int t;
	t = strlen (str2);
	str2[t] = str1[ii];
	str2[t + 1] = '\0';
	ii++;
	return;
}
/*
*to reverse a string
*/
char *strrev(char *str)  {
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1;
       p2 > p1; ++p1, --p2) {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
/*
*receives three characters (two digits and operator)
*and the last carry
*performs the operation on digits
*returns the value 
*/
int solve(char x, char y, char z, int c) {
	short int a, b, r;
	a = x - '0';
	b = y - '0';
	switch(z) {
		case'+' :
			if(c) 
				a = a + 1;
			return a + b;
		case'-' :
			if(c) 
				a = a - 1;
			return r = a - b;
		case'*': 
			r = a * b;
			if(c)
				r = r + c;
			return r;
	}
	return INT_MIN;
}
/*
*compares two string and returns an int 
*depending on which string is bigger(or equal)
*/
int compare(char *str1, char *str2) {
	int len1, len2, i;
	len1 = strlen(str1);
	len2 = strlen(str2);
	if (len1 > len2) {
		return 2;
	}
	if (len1 < len2) {
		return 3;
	}
	if ( len1 == len2 ) {
		i = strcmp( str1, str2);
		if ( i == 0)
			return 1;
		if ( i < 0 )
			return 3;
		if ( i > 0 )
			return 2;
	}
	return INT_MIN;
}
/*
*initializes the Num datatype
*/
void initNum(Num *a) {
		strcpy(a->arr, "");
		a->ni = a->nf = a->sign = 0;
}
/*
*removes zeroes at begining from strings
*/
void removeZeroFromFront(char *str) {
	int len1, i = 0;
	len1 = strlen(str);
	while (str[0] == '0') {
		len1 = strlen(str);
		if(len1 == 1 || str[0] == '.')
			break;
		while (i < len1 ) {
			str[i] = str[i + 1];
			i++;
		}
		i = 0;
	}
	return;
}
/*
*gets a string (number with '.' and/or '-')
*creates a Num type from it
*returns the Num
*/
Num createNumFromString(char *str) {
	Num a;
	initNum(&a);
	removeZeroFromFront(str);
	int i = 0, j = 0, no = 0;
	if (*(str) == '-') {
		a.sign = 1;
		i++;
	}
	else if (*(str) == '.') {
		i++;
		no = REAL;
	}
	while(*(str + i)) {
		if((*(str + i) == '.') || ((*(str + i) >= 48) && (*(str + i) <= 57))) {
			if(*(str + i) == '.') {
				if(no == REAL) {
					strcpy(a.arr, "error");
					return a;
				}
				no = BOTH;
			}
			else {
				a.arr[j++] = *(str + i);
				if(no == BOTH)
					a.nf++;
				else
					a.ni++;
			}
		}		else {
			strcpy(a.arr, "error");			
			return a;
		}
		i++;	
	}
	a.arr[j++] = '\0';
	if(no == REAL) {
		a.nf = strlen(a.arr);
		a.ni = 0;
	}
	return a;
}
/*
*gets a Num input
*creates a string out of Num
*places '.' and/or '-' in it
*returns the string
*/
char *createStringFromNum(Num a) {
	char *c;
	int i = 0, j;
	j = strlen(a.arr);
	c = malloc(j + 3); //the caller should free this string
	strcpy(c,"");
	if(a.sign) {
		*c = '-';
		i++;
		c[1] = '\0';
		j++;
	}
	strcat(c, a.arr);
	if(a.nf) {
		for(i = j; i > a.ni; i--)
			c[i] = c[i - 1];
		c[a.ni] = '.';
		j++;
		c[j] = '\0';
	}
	return c;
}
/*
*adds 2 strings
*/
char *addNum(char *str1, char *str2) {
	Num res, a, b;
	initNum(&a);
	initNum(&b);
	initNum(&res);
	char *bb, *cc;
	removeZeroFromFront(str1);
	removeZeroFromFront(str2);
	int x, carry = 0, d = 0, i = 0, len1, len2, cont, cmp;
		unsigned short int k;
	a = createNumFromString(str1);
	b = createNumFromString(str2);
	if(!strcmp(a.arr, "error") || !strcmp(b.arr, "error")) {
		bb = malloc(7);
		strcpy(bb, "error");
		return bb;
	}
	cmp = compare(a.arr, b.arr);
	if (a.sign && b.sign) {
		res.sign = 1;
		cont = 1;
	}
	else if(a.sign || b.sign) {
		if(a.sign) {
			while(*(str1 + i)) {
				str1[i] = str1[i + 1];
				i++;
			}
			if(cmp == 2) {
				cc = substractNum(str1, str2);
				bb = malloc(strlen(cc) + 2);
				strcpy(bb, "-");
			}
			else {
				cc = substractNum(str2, str1);
				bb = malloc(strlen(cc) + 2);
				strcpy(bb, "");
			}
			strcat(bb, cc);
			free(cc);
			return bb;
		}
		else if(b.sign) {
			while(*(str2 + i)) {
				str2[i] = str2[i + 1];
				i++;
			}
			if(cmp == 3) {
				cc = substractNum(str2, str1);
				bb = malloc(strlen(cc) + 2);
				strcpy(bb, "-");
			}
			else {
				cc = substractNum(str1, str2);
				bb = malloc(strlen(cc) + 2);
				strcpy(bb, "");
			}
			strcat(bb, cc);
			free(cc);
			return bb;
		}
	}
	else if (!a.sign && !b.sign) 
		cont = 1;
	if (cont) {
		k = a.nf - b.nf;
		if(a.nf > b.nf) {
			b.nf = a.nf;
			d = B;
		}
		else if(a.nf < b.nf) {
			a.nf = b.nf;
			d = A;
		}
		if(d) {
			for (i = 0; i < k; i++)	{
				if(d == A)
					strcat(a.arr, "0");
				else if(d == B) 
					strcat(b.arr, "0");
			}
		}
		i = 0;
		len1 = strlen(a.arr);
		len2 = strlen(b.arr);
		while(1) {
			if((len1 || len2)) {
				if(len1 && len2)
					x = solve(a.arr[len1 - 1], b.arr[len2 - 1], '+', carry);
				else if (!len1)
					x = solve('0', b.arr[len2 - 1], '+', carry);				
				else if (!len2)
					x = solve(a.arr[len1 - 1], '0', '+', carry);
				if (x > 9) {
					x = x % 10;
					res.arr[i++] = x + '0';
					carry = 1;
				}
				else {
					res.arr[i++] = x + '0';
					carry = 0;
				}
				if(len1)
					len1--;
				if(len2)
					len2--;
			}
			else {
				if(carry) {
					res.arr[i++] = 1 + '0';
					break;
				}
				else
					break;
			}

		}
	}
	res.arr[i++] = '\0';
	strrev(res.arr);
	res.nf = a.nf;
	x = strlen(res.arr);
	res.ni = x - res.nf;
	if(res.nf || res.sign) {
		cc = createStringFromNum(res);
		bb = malloc(strlen(cc));
		strcpy(bb, cc);
		return bb;
	}
	bb = malloc(x + 1);
	strcpy(bb, res.arr);
	removeZeroFromFront(bb);
	return bb;
}
/*
*subtracts 2 strings
*/
char *substractNum(char *str1, char *str2) {
	Num res, a, b;
	initNum(&a);
	initNum(&b);
	initNum(&res);
	char *bb, *cc;
	int x, borrow = 0, d = 0, i, len1, len2, cmp;
	unsigned int k;
	a = createNumFromString(str1);
	b = createNumFromString(str2);
	if(!strcmp(a.arr, "error") || !strcmp(b.arr, "error")) {
		bb = malloc(7);
		strcpy(bb, "error");
		return bb;
	}
	cmp = compare(str1, str2);
	if(a.sign && b.sign) {
		while(*(str1 + i)) {
				str1[i] = str1[i + 1];
				i++;
		}
		i = 0;
		while(*(str2 + i)) {
				str2[i] = str2[i + 1];
				i++;
		}
		if(cmp == 3) {
			cc = substractNum(str2, str1);
			//bb = malloc(strlen(cc) + 2);
			//strcpy(bb, "");
			//strcat(bb, cc);
			//free(cc);
			return cc;
		}
		else {
			cc = substractNum(str1, str2);
			bb = malloc(strlen(cc) + 2);
			strcpy(bb, "-");
			strcat(bb, cc);
			free(cc);
			return bb;
		}
	}
	else if(a.sign || b.sign) {
		if(a.sign) {
			while(*(str1 + i)) {
				str1[i] = str1[i + 1];
				i++;
			}
			cc = addNum(str1, str2);
			bb = malloc(strlen(cc) + 2);
			strcpy(bb, "-");
			strcat(bb, cc);
			free(cc);
			return bb;
		}
		else {
			while(*(str2 + i)) {
				str2[i] = str2[i + 1];
				i++;
			}
			cc = addNum(str1, str2);
			return cc;
		}
	}
	if((cmp == 3) && a.ni < b.ni) {
		cc = substractNum(str2, str1);
		bb = malloc(max);
		strcpy(bb, "-");
		strcat(bb, cc);
		free(cc);
		return bb;
	}
	k = a.nf - b.nf;
	if(a.nf > b.nf)
		d = B;
	else if(a.nf < b.nf)
		d = A;
	if(d) {
		for (i = 0; i < k; i++)	{
			if (d == A)
				strcat(a.arr, "0");
			else 
				strcat(b.arr, "0");
		}
	}
	i = 0;
	len1 = strlen(a.arr);
	len2 = strlen(b.arr);
	while(len1 || len2) {
		if(len1 && len2)
			x = solve(a.arr[len1 - 1], b.arr[len2 - 1],
			 '-', borrow);
		else if (!len1)
			x = solve('0', b.arr[len2 - 1], '-', borrow);				
		else if (!len2)
			x = solve(a.arr[len1 - 1], '0', '-', borrow);
		if (x < 0) {
			x = 10 + x;
			res.arr[i++] = x + '0';
			borrow = 1;
		}
		else {
			res.arr[i++] = x + '0';
			borrow = 0;
		}
		if(len1)
			len1--;
		if(len2)
			len2--;
	}
	res.arr[i++] = '\0';
	strrev(res.arr);
	res.nf = a.nf;
	x = strlen(res.arr);
	res.ni = x - res.nf;
	if(res.nf || res.sign) {
		cc = createStringFromNum(res);
		bb = malloc(strlen(cc));
		strcpy(bb, cc);
		return bb;
	}
		bb = malloc(x + 1);
	strcpy(bb, res.arr);
	removeZeroFromFront(bb);
	return bb;
}
/*
*multiplies 2 strings
*/
char *mulNum(char *str1, char *str2) {
	Num res, a, b;
	initNum(&a);
	initNum(&b);
	stack ab;
	init(&ab);
	initNum(&res);
	char *aa, *bb, *cc, *num1, *num2, *num3;
	a = createNumFromString(str1);
	b = createNumFromString(str2);
	if(!strcmp(a.arr, "error") || !strcmp(b.arr, "error")) {
		bb = malloc(7);
		strcpy(bb, "error1");
		return bb;
	}
	int x, i, len2;
	len2 = strlen(b.arr);
	i = 0;
	while(len2) {
		cc = mulscalNum(a.arr, b.arr[len2 - 1]);
		aa = malloc(strlen(cc) + i + 1);
		strcpy(aa, cc);
		free(cc);
		for(x = 0; x < i; x++)
			strcat(aa, "0");
		push(&ab, aa);
		i++;
		len2--;
	}
	i--;
	while(i) {
		if(!isempty(&ab))
			num2 = pop(&ab);
		if(!isempty(&ab))
			num1 = pop(&ab);
		num3 =  operation(num1, num2, '+');
		free(num1);
		free(num2);
		push(&ab, num3);
		i--;
	}
	if(!isempty(&ab))
		strcpy(res.arr, pop(&ab));
	res.nf = a.nf + b.nf;
	res.ni = strlen(res.arr) - res.nf;
	if(a.sign || b.sign)
		res.sign = 1;
	if(res.nf || res.sign) {
		cc = createStringFromNum(res);
		bb = malloc(strlen(cc));
		strcpy(bb, cc);
		return bb;
	}
	bb = malloc(strlen(res.arr) + 1);
	strcpy(bb, res.arr);
	return bb;
}
/*
*multiplies a string and a digit
*/
char *mulscalNum(char *a, char b) {
	int x, len1, carry = 0, i = 0;
	len1 = strlen(a);
	char *aa;
	aa = malloc(len1 + 1);
	if(b == '0') {
		strcpy(aa, "0");
		return aa;
	}
	if(b == '1') {
		strcpy(aa, a);
		return aa;
	}
	while(len1) {
		x = solve(a[len1 - 1], b, '*', carry);
		if (x > 9) {
			carry = x / 10;
			x = x % 10;
			aa[i++] = x + '0';
		}
		else {
			aa[i++] = x + '0';
			carry = 0;
		}
		len1--;
	}
	if(carry)
		aa[i++] = carry + '0';
	aa[i++] = '\0';
	strrev(aa);
	return aa;
}
/*
*divides 2 strings
*/
char *divNum(char *str1, char *str2, char x) {
	Num res, a, b;
	initNum(&a);
	initNum(&b);
	initNum(&res);
	char *bb, *cc, *result, *rem;
	int k;
	unsigned int bbb;
	removeZeroFromFront(str1);
	removeZeroFromFront(str2);
	if (strcmp(str1, "0") == 0) {
		char *bb = malloc(2);
		strcpy(bb, "0");
		return bb;
	}
	if (strcmp(str2, "0") == 0) {
		char *bb = malloc(12);
		strcpy(bb, "MATH ERROR");
		return bb;
	}
	if (strcmp(str1, str2) == 0) {
		char *bb = malloc(2);
		strcpy(bb, "1");
		return bb;
	}
	if (strcmp(str2, "1") == 0) {
		char *bb = malloc(strlen(str1) + 1);
		strcpy(bb, str1);
		return bb;
	}
	a = createNumFromString(str1);
	b = createNumFromString(str2);
	if(!strcmp(a.arr, "error") || 
		!strcmp(b.arr, "error")) {
		bb = malloc(7);
		strcpy(bb, "error");
		return bb;
	}
	result = malloc(MAX);
	rem = malloc(max);
	if(a.nf < b.nf)
		for (bbb = 0; bbb < b.nf; bbb++)
			strcat(a.arr, "0");
	division(a.arr, b.arr, result, rem);
	if(x == '/') {
		removeZeroFromFront(result);
		strcpy(res.arr, result);
		k = strlen(result);
		free(result);
		free(rem);
		bbb = a.nf - b.nf;
		res.nf = bbb;
		res.ni = k - bbb;
		if(a.sign != b.sign)
			res.sign = 1;
		if(res.sign || res.nf) {
			cc = createStringFromNum(res);
			bb = malloc(strlen(cc));
			strcpy(bb, cc);
			return bb;
		}
		bb = malloc(strlen(res.arr) + 1);
		strcpy(bb, res.arr);
		return bb;
	}
	else {
		removeZeroFromFront(rem);
		strcpy(res.arr, rem);
		k = strlen(rem);
		free(result);
		free(rem);
		bbb = a.nf - b.nf;
		res.nf = bbb;
		res.ni = k - bbb;
		if(a.sign != b.sign)
			res.sign = 1;
		if(res.sign || res.nf) {
			cc = createStringFromNum(res);
			bb = malloc(strlen(cc));
			strcpy(bb, cc);
			return bb;
		}
		bb = malloc(strlen(res.arr) + 1);
		strcpy(bb, res.arr);
		return bb;
	}
}
/*
*does the real division part by quotient and getnum
*/
void division( char *str1, char *str2, char *res, char *rem) {
	j = 0;
	int cmp;
	int len1, newl;
	int c1;
	c1 = compare( str1, str2);
	if (c1 == 3) {
		res[0] = '0';
		res[1] = '\0';
		strcpy( rem, str1);
		return;
	}
	len1 = strlen (str1);
	res[0] = '\0';
	char newres[MAX];
	char newno1[MAX];
	newno1[0] = '\0';
	ii = 0;
	while (ii < len1 ) {
		j = 0;
		while (1) {
			cmp = compare( str2, newno1);
			if (cmp == 3)
				break;
			newl = ii;
			if ( j > 0 && newl <= len1 ) {
				strcat( res, "0");
				newl++;
			}
			if ( newl == len1 + 1 ) {
				return;
			}
			getnum(str1, newno1);
			j++;
		}
		quotient(newno1, str2, newres, rem);
		strcat(res, newres);
		strcpy(newno1, rem);
	}
}
/*
*finds the quotient by multiplicating, addition,
*subtraction and comparisions
*/
void quotient(char *str1, char *str2, char *res, char *rem) {
	char mul[MAX];
	char *mult, *subt;
	int i;
	if (strcmp( str1, str2) == 0 ) {
		strcpy( res, str1);
		rem[0] = '0';
		rem[1] = '\0';
		return;
	}
	res[0] = '1';
	res[1] = '\0';
	rem[0] = '1';
	rem[1] = '\0';
	while ( 1 ) {
		res[0] = '1';
		res[1] = '\0';
		mult = mulNum(str2, rem);
		strcpy(mul, mult);
		free(mult);
		if (mul[0] == '0' && strlen ( mul ) != 1) {
			int j = strlen (mul);
			i = 0;
			while (j != 0) {
				mul[i] = mul[i + 1];
				i++;
				j--;
			}
		}
		i = compare (mul, str1);
		if (i == 1) {
			strcpy( res, rem);
			rem[0] = '0';
			rem[1] = '\0';
			return;
		}
		if (i == 2) {
			res[0] = '1';
			res[1] = '\0';
			subt = substractNum(rem, res);
			strcpy(res, subt);
			free(subt);
			mult = mulNum(res, str2);
			strcpy(mul, mult);
			free(mult);
			mult = substractNum(str1, mul);
			strcpy(rem, mult);
			free(mult);
			return;
		}
		if (i == 3) {
			mult = addNum(rem, res);
			strcpy(rem, mult);
			free(mult);
		}
	}
}
/*
*calls the math library trignometric functions
*/
double trignomet(char *str, int func) {
	double x, y;
	y = atol(str);
	switch (func) {
		case SIN:
			x = sine(y * PI / 180);
			break;
		case COS:
			x = cosine(y * PI / 180);
			break;
		case TAN:
			x = sine(y * PI / 180)/cosine(y * PI / 180);
			break;
		case SEC:
			x = 1 / cosine(y*PI/180);
			break;
		case COSEC:
			x = 1 / sine(y * PI / 180);
			break;
		case COT:
			x = cosine(y * PI / 180) / sine(y * PI / 180);
			break;
	}
	return x;
}
double sine(double x) {
	double xsq, sum, term, d;
	int sign, i;
	xsq = x * x;
	i = 1; 
	sum = term = x;
	sign = 1;
	while(fabs(term) > 1e-9) {
		d = (2 * (double) i + 1) * (2 * i);
		term = term / d ;
		term = term * xsq; 
		sign *= -1;
		sum = sum + sign * term;
		i++;
	}
	return sum;
}
double cosine(double x) {
	double xsq, sum, term, d;
	int sign, i;
	xsq = x * x;
	i = 1; 
	sum = term = 1;
	sign = 1;
	while(fabs(term) > 1e-9) {
		d = (2 * (double) i - 1) * (2 * i);
		term = term / d ;
		term = term * xsq; 
		sign *= -1;
		sum = sum + sign * term;
		i++;
	}
	return sum;
}



/*
*calculates exponent of a string
*/
char *powNum(char *str1, char *str2) {
	Num res, a, b;
	initNum(&a);
	initNum(&b);
	initNum(&res);
	removeZeroFromFront(str1);
	removeZeroFromFront(str2);
	char t[MAX], *aa, *bb, *cc;
	int y, x;
	a = createNumFromString(str1);
	b = createNumFromString(str2);
	if(!strcmp(a.arr, "error") || 
		!strcmp(b.arr, "error")) {
		bb = malloc(7);
		strcpy(bb, "error");
		return bb;
	}
	if(b.nf) {
		bb = malloc(40);
		strcpy(bb, "non-zero scale in exponent");
		return bb;
	}
	if(!strcmp(a.arr, "0") && 
		!strcmp(b.arr, "0")) {
		bb = malloc(15);
		strcpy(bb, "MATH ERROR");
		return bb;
	}
	if(!strcmp(a.arr, "0")) {
		bb = malloc(2);
		strcpy(bb, "0");
		return bb;
	}
	if(!strcmp(b.arr, "0")) {
		bb = malloc(2);
		strcpy(bb, "1");
		return bb;
	}
	x = strlen(a.arr);
	y = atoi(b.arr);
	if ((x * y) > 300) {
		bb = malloc(40);
		strcpy(bb, "Too Big Number.... Try Something little");
		return bb;
	}
	strcpy(res.arr, "1");
	strcpy(t, a.arr);
	
	x = y;
	while(y > 0) {
		if(y % 2) {
			aa = mulNum(res.arr, t);
			strcpy(res.arr, aa);
			free(aa);
		}
		aa = mulNum(t, t);
		strcpy(t, aa);
		free(aa);
		y = y /2;	
	}
	if(b.sign) {
		aa = divNum("1", res.arr, '/');
		strcpy(res.arr, aa);
		free(aa);
	}
	if (x % 2 && a.sign)
		res.sign = 1;
	//res.nf = a.nf;	
	res.nf = a.nf * x;
	res.ni = strlen(res.arr) - res.nf;
	if (res.nf > 10)
		res.nf = 10;
	if(res.nf || res.sign) {
		cc = createStringFromNum(res);
		bb = malloc(strlen(cc));
		strcpy(bb, cc);
		return bb;
	}
	bb = malloc(strlen(res.arr) + 1);
	strcpy(bb, res.arr);
	removeZeroFromFront(bb);
	return bb;
}

/*
*shifts number(str1) left by str2 digits
*/
char  *leftShift(char *str1, char *str2) {
	Num a, b;
	initNum(&a);
	initNum(&b);
	removeZeroFromFront(str1);
	removeZeroFromFront(str2);
	char *aa, *bb;
	a = createNumFromString(str1);
	b = createNumFromString(str2);
	if(!strcmp(a.arr, "error") || 
		!strcmp(b.arr, "error")) {
		bb = malloc(7);
		strcpy(bb, "error");
		return bb;
	}
	if(b.nf || b.sign) {
		bb = malloc(100);
		strcpy(bb, "Digits can't Be Negative or Floating numbers");
		return bb;
	}
	if(a.nf) {
		bb = malloc(100);
		strcpy(bb, "Floating numbers can't Be shifted");
		return bb;
	}
	aa = powNum(str2, "2");
	bb = mulNum(str1, aa);
	return bb;
}
/*
*shifts number (str2) right by str2 digits
*/
char  *rightShift(char *str1, char *str2) {
	Num a, b;
	initNum(&a);
	initNum(&b);
	removeZeroFromFront(str1);
	removeZeroFromFront(str2);
	char *aa, *bb;
	a = createNumFromString(str1);
	b = createNumFromString(str2);
	if(!strcmp(a.arr, "error") || 
		!strcmp(b.arr, "error")) {
		bb = malloc(7);
		strcpy(bb, "error");
		return bb;
	}
	if(b.nf || b.sign) {
		bb = malloc(100);
		strcpy(bb, "Digits can't Be Negative or Floating numbers");
		return bb;
	}
	if(a.nf) {
		bb = malloc(100);
		strcpy(bb, "Floating numbers can't Be shifted");
		return bb;
	}
	aa = powNum(str2, "2");
	bb = divNum(str1, aa, '/');
	return bb;
} 