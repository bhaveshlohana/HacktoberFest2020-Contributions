#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 8
char AC[SIZE + 2];
int flg = 0;
char B[SIZE + 1], Q[SIZE + 1];

int btod(int bin1)
{
    int ans1 = 0;
    for (int i = 0; bin1 != 0; i++)
    {
        ans1 = (bin1 % 10) * (pow(2, i)) + ans1;
        bin1 = bin1 / 10;
    }
    return ans1;
}
char *twoComp(char *a)
{
    char onesComp[SIZE + 2], twosComp[SIZE + 2];
    int carry = 1, i;
    for (i = 0; i < SIZE + 1; i++)
    {
        if (a[i] == '1')
        {
            onesComp[i] = '0';
        }
        else if (a[i] == '0')
        {
            onesComp[i] = '1';
        }
    }
    onesComp[SIZE + 1] = '\0';
    for (i = SIZE; i >= 0; i--)
    {
        if (onesComp[i] == '1' && carry == 1)
        {
            twosComp[i] = '0';
        }
        else if (onesComp[i] == '0' && carry == 1)
        {
            twosComp[i] = '1';
            carry = 0;
        }
        else
        {
            twosComp[i] = onesComp[i];
        }
    }
    twosComp[SIZE + 1] = '\0';
    strcpy(a, twosComp);
    return a;
}
char *filler(char *a)
{
    int size = SIZE;
    if (strlen(a) != size)
    {
        strrev(a);
        for (int i = strlen(a); i < SIZE; i++)
        {
            a[i] = '0';
        }
        a[SIZE] = '\0';
        a[SIZE + 1] = '\0';
        strrev(a);
    }
    return a;
}
char *filler1(char *a)
{
    int size = SIZE;
    if (strlen(a) != size + 1)
    {
        strrev(a);
        for (int i = strlen(a); i < SIZE + 1; i++)
        {
            a[i] = '0';
        }
        a[SIZE + 1] = '\0';
        a[SIZE + 2] = '\0';
        strrev(a);
    }
    return a;
}
int ndtob(int n)
{
    char binary[SIZE + 2];
    int bin;
    if (n < 0)
    {
        n = n * -1;
        itoa(n, binary, 2);
        filler(binary);
        char onesComp[SIZE + 1], twosComp[SIZE + 1];
        int carry = 1, i;
        for (i = 0; i < SIZE; i++)
        {
            if (binary[i] == '1')
            {
                onesComp[i] = '0';
            }
            else if (binary[i] == '0')
            {
                onesComp[i] = '1';
            }
        }
        onesComp[SIZE] = '\0';
        for (i = SIZE - 1; i >= 0; i--)
        {
            if (onesComp[i] == '1' && carry == 1)
            {
                twosComp[i] = '0';
            }
            else if (onesComp[i] == '0' && carry == 1)
            {
                twosComp[i] = '1';
                carry = 0;
            }
            else
            {
                twosComp[i] = onesComp[i];
            }
        }
        twosComp[SIZE] = '\0';
        bin = atoi(twosComp);
    }
    else
    {
        itoa(n, binary, 2);
        bin = atoi(binary);
    }
    return bin;
}
void ADD()
{
    long int binary1, binary2;
    binary1 = atoi(AC);
    binary2 = atoi(B);
    int i = 0, remainder = 0;
    while (binary1 != 0 || binary2 != 0)
    {
        int temp = (binary1 % 10 + binary2 % 10 + remainder) % 2;
        char temp2 = '0';
        if (temp == 1)
        {
            temp2 = '1';
        }
        else
        {
            temp2 = '0';
        }
        AC[i++] = temp2;
        remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
        binary1 = binary1 / 10;
        binary2 = binary2 / 10;
    }
rem:
    if (i < SIZE + 1)
    {
        if (remainder != 0)
        {
            if (remainder == 1)
            {
                AC[i++] = '1';
            }
            else if (remainder == 2)
            {
                AC[i++] = '0';
                remainder = 1;
                goto rem;
            }
        }
        for (; i < SIZE + 1;)
        {
            AC[i++] = '0';
        }
    }
    else
    {
        if (remainder != 0)
            flg++;
        i--;
    }
    strrev(AC);
}
void SUB()
{
    char onesComp[SIZE + 2], twosComp[SIZE + 2];
    int carry = 1, i;
    for (i = 0; i < SIZE + 1; i++)
    {
        if (B[i] == '1')
        {
            onesComp[i] = '0';
        }
        else if (B[i] == '0')
        {
            onesComp[i] = '1';
        }
    }
    onesComp[SIZE + 1] = '\0';
    for (i = SIZE; i >= 0; i--)
    {
        if (onesComp[i] == '1' && carry == 1)
        {
            twosComp[i] = '0';
        }
        else if (onesComp[i] == '0' && carry == 1)
        {
            twosComp[i] = '1';
            carry = 0;
        }
        else
        {
            twosComp[i] = onesComp[i];
        }
    }
    twosComp[SIZE + 1] = '\0';
    long int binary1, binary2;
    binary1 = atoi(AC);
    binary2 = atoi(twosComp);
    i = 0;
    int remainder = 0;
    while (binary1 != 0 || binary2 != 0)
    {
        int temp = (binary1 % 10 + binary2 % 10 + remainder) % 2;
        char temp2 = '0';
        if (temp == 1)
        {
            temp2 = '1';
        }
        else
        {
            temp2 = '0';
        }
        AC[i++] = temp2;
        remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
        binary1 = binary1 / 10;
        binary2 = binary2 / 10;
    }
rem:
    if (i < SIZE + 1)
    {
        if (remainder != 0)
        {
            if (remainder == 1)
            {
                AC[i++] = '1';
            }
            else if (remainder == 2)
            {
                AC[i++] = '0';
                remainder = 1;
                goto rem;
            }
        }
        for (; i < SIZE + 1;)
        {
            AC[i++] = '0';
        }
    }
    else
    {
        if (remainder != 0)
            flg++;
        i--;
    }
    strrev(AC);
}
void SL()
{
    for (int i = 0; i < SIZE; i++)
    {
        AC[i] = AC[i + 1];
    }
    AC[SIZE] = Q[0];
    for (int i = 0; i < SIZE - 1; i++)
    {
        Q[i] = Q[i + 1];
    }
}
void non_rest()
{
    for (int i = 0; i < SIZE; i++)
    {
        SL();
        if (AC[0] == '1')
        {
            ADD();
        }
        else if (AC[0] == '0')
        {
            SUB();
        }
        if (AC[0] == '1')
        {
            Q[SIZE - 1] = '0';
        }
        else if (AC[0] == '0')
        {
            Q[SIZE - 1] = '1';
        }
    }
    if (AC[0] == '1')
    {
        ADD();
    }
}
void rest()
{
    for (int i = 0; i < SIZE; i++)
    {
        SL();
        SUB();
        if (AC[0] == '1')
        {
            Q[SIZE - 1] = '0';
            ADD();
        }
        else if (AC[0] == '0')
        {
            Q[SIZE - 1] = '1';
        }
    }
}
void main()
{
    while (1)
    {
        int a, b;
        short int sa = 1, sb = 1;
        printf("Enter the number in range of -255 to 255\n");
        printf("Enter the number the Dividend : ");
        scanf("%d", &b);
        printf("Enter the number the Divisor : ");
        scanf("%d", &a);
        if (a < 0)
        {
            sa = -1;
            a = a * -1;
        }
        if (b < 0)
        {
            sb = -1;
            b = b * -1;
        }
        if (a > 255 || b > 255 || a == 0)
        {
            printf("Please Enter in range\n");
            continue;
        }

        filler1(AC);

        itoa(ndtob(a), B, 10);
        filler1(B);

        itoa(ndtob(b), Q, 10);
        filler(Q);

        printf("Options :\n");
        printf("1. Restoring Methood\n");
        printf("2. Non-Restoring Method\n");
        int op = 0;
        printf("Enter the Option : ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            rest();
            break;
        case 2:
            non_rest();
            break;
        default:
            break;
        }

        if (sa != sb)
        {
            op = -1;
        }
        else
        {
            op = 1;
        }

        printf("\nQuotient is %d and Remainder is %d\n", op * btod(atoi(Q)), sb * btod(atoi(AC)));

        if (sa != sb)
        {
            twoComp(Q);
        }
        if (sb == -1)
        {
            twoComp(AC);
        }

        printf("\nQuotient in binary is %s \nRemainder in binary is %s\n", Q, AC);
        exit(0);
    }
}