#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 8

char Q1 = '0';
char AC[SIZE + 1];
int flg = 0;
char M[SIZE + 1], Q[SIZE + 1];

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
int ndtob(int n)
{
    char binary[SIZE + 1];
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
int btod(int a, int b)
{
    char binary1[SIZE + 1], binary2[SIZE + 1];
    int x = 0;
    int bin1 = 0, bin2 = 0;
    int ans1 = 0, ans2 = 0;
    int ab;
    itoa(a, binary1, 10);
    itoa(b, binary2, 10);
    int size = SIZE;
    if (strlen(binary1) == size)
    {
        filler(binary1);
        char onesComp[SIZE + 1], twosComp[SIZE + 1];
        int carry = 1, i;
        for (i = 0; i < SIZE; i++)
        {
            if (binary1[i] == '1')
            {
                onesComp[i] = '0';
            }
            else if (binary1[i] == '0')
            {
                onesComp[i] = '1';
            }
        }
        onesComp[SIZE] = '\0';
        bin1 = atoi(onesComp);

        for (int i = SIZE; bin1 != 0; i++)
        {
            ab = bin1 % 10;
            ans1 = (ab) * (pow(2, i)) + ans1;
            bin1 = bin1 / 10;
        }
        filler(binary2);
        for (i = 0; i < SIZE; i++)
        {
            if (binary2[i] == '1')
            {
                onesComp[i] = '0';
            }
            else if (binary2[i] == '0')
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
        bin2 = atoi(twosComp);
        for (int i = 0; bin2 != 0; i++)
        {
            ab = bin2 % 10;
            ans2 = (ab) * (pow(2, i)) + ans2;
            bin2 = bin2 / 10;
        }
        x = ans1 + ans2;
        x = x * -1;
    }
    else
    {
        bin1 = atoi(binary1);
        for (int i = SIZE; bin1 != 0; i++)
        {
            ab = bin1 % 10;
            ans1 = (ab) * (pow(2, i)) + ans1;
            bin1 = bin1 / 10;
        }
        bin2 = atoi(binary2);
        for (int i = 0; bin2 != 0; i++)
        {
            ab = bin2 % 10;
            ans2 = (ab) * (pow(2, i)) + ans2;
            bin2 = bin2 / 10;
        }
        x = ans1 + ans2;
    }
    return x;
}
void ASR()
{
    Q1 = Q[SIZE - 1];
    for (int i = SIZE - 1; i > 0; i--)
    {
        Q[i] = Q[i - 1];
    }
    Q[0] = AC[SIZE - 1];
    for (int i = SIZE - 1; i > 0; i--)
    {
        AC[i] = AC[i - 1];
    }
}
void ADD()
{
    long int binary1, binary2;
    binary1 = atoi(AC);
    binary2 = atoi(M);
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
    if (i < SIZE)
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
        for (; i < SIZE;)
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
    char onesComp[SIZE + 1], twosComp[SIZE + 1];
    int carry = 1, i;
    for (i = 0; i < SIZE; i++)
    {
        if (M[i] == '1')
        {
            onesComp[i] = '0';
        }
        else if (M[i] == '0')
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
    if (i < SIZE)
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
        for (; i < SIZE;)
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
int main()
{
    int a, b;
    printf("Enter the number in range of -127 to 127\n");
    printf("Enter the number the First number: ");
    scanf("%d", &a);
    printf("Enter the number the Second number: ");
    scanf("%d", &b);

    filler(AC);

    itoa(ndtob(a), M, 10);
    filler(M);

    itoa(ndtob(b), Q, 10);
    filler(Q);
    /*printf("%c\n", Q1);
    printf("%s\n", M);
    printf("%s\n", Q);
    printf("%s\n", AC);*/
    for (int i = 0; i < SIZE; i++)
    {
        if (Q[7] == '0' && Q1 == '1')
        {
            ADD();
        }
        else if (Q[7] == '1' && Q1 == '0')
        {
            SUB();
        }
        ASR();
    }
    printf("\nThe Answer in binary is : %s %s\n", AC, Q);
    int ans1 = atoi(AC);
    int ans2 = atoi(Q);
    int fans = btod(ans1, ans2);
    printf("The answer in decimal is : %ld", fans);
    return 0;
}