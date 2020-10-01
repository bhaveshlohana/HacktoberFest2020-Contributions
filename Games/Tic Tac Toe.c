#include <stdio.h>
#include <conio.h>
void check(char, char);
char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; //Declaring char type array for storing the values (x,0)

void gamename() //User defiened function to display game name (gamename)
{
    printf("\t\t\tTic Tac Toe Game:\n\n");
}

void show() //User defiened function for layout (show)
{
    printf("\n\n\t\t\t---|---|---\n");
    printf("\t\t\t  %c  %c  %c\n", a[0], a[1], a[2]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t  %c  %c  %c\n", a[3], a[4], a[5]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t  %c  %c  %c\n", a[6], a[7], a[8]);
    printf("\t\t\t---|---|---\n");
}

void inputsymbol() //User defiened function for input instructions (inputsymbol)
{
    printf("\n\tPlayer 1 symbol:x:\n\tPlayer 2 symbol:0:\n");
}

int count = 0;

void play()
{
    char p, s;
    printf("Enter position:\n");
    fflush(stdin);
    scanf("%c", &p);
    printf("Enter symbol:\n");
    fflush(stdin);
    scanf("%c", &s);
    count++;
    check(p, s); //passing position and value in check() function
}

void check(char P, char S) //User defiende fun. to check the position and fill the value
{
    int i;
    for (i = 0; i <= 8; i++)
    {
        if (a[i] == P) //checking the position
        {
            a[i] = S; //assigning the value
        }
    }
}

int end() // User defiend function to ckeck the winner (returning argument)
{
    if ((a[0] == 'x' && a[1] == 'x' && a[2] == 'x') || (a[0] == 'x' && a[3] == 'x' && a[6] == 'x') || (a[0] == 'x' && a[4] == 'x' && a[8] == 'x'))
        return 100;
    else if ((a[0] == '0' && a[1] == '0' && a[2] == '0') || (a[0] == '0' && a[3] == '0' && a[6] == '0') || (a[0] == '0' && a[4] == '0' && a[8] == '0'))
        return 200;
    else if (a[1] == 'x' && a[4] == 'x' && a[7] == 'x')
        return 100;
    else if (a[1] == '0' && a[4] == '0' && a[7] == '0')
        return 200;
    else if (a[2] == 'x' && a[5] == 'x' && a[8] == 'x')
        return 100;
    else if (a[2] == '0' && a[5] == '0' && a[8] == '0')
        return 200;
    else if (a[3] == 'x' && a[4] == 'x' && a[5] == 'x')
        return 100;
    else if (a[3] == '0' && a[4] == '0' && a[5] == '0')
        return 200;
    else if (a[2] == 'x' && a[4] == 'x' && a[6] == 'x')
        return 100;
    else if (a[2] == '0' && a[4] == '0' && a[6] == '0')
        return 200;
    else if (a[6] == 'x' && a[7] == 'x' && a[8] == 'x')
        return 100;
    else if (a[6] == '0' && a[7] == '0' && a[8] == '0')
        return 200;
    return 300;
}

//******************************** Main Function *****************************************************
void main()
{
    int k;
    char ch;
labell:
    gamename();    //Display "Tic Tac Toe"
    show();        //Display layout of the game
    inputsymbol(); //Instructions for input
    play();        //calling fun. for start playing

label:
    system("cls"); //clear screen
    show();        //function >> fresh the layout with input character
    play();
    k = end();
    system("cls");
    show();
    if (count < 9)
    {
        if (k == 100) //recieving value from end fun. and saving in k
        {
            printf("\nPlayer 1 won");
            count = 0;
        }
        else if (k == 200)
        {
            printf("\nPlayer 2 won");
            count = 0;
        }
        else
            goto label; //for repeating the turn of players, labled in line 104
    }
    else
    {
        printf("\nGame Draw..!!");
        count = 0;
    }

    printf("\nDo you want to continue [Y/N]:");
    fflush(stdin);
    scanf("%c", &ch);

    if (ch == 'y' || ch == 'Y')
    {
        a[0] = '1';
        a[1] = '2';
        a[2] = '3';
        a[3] = '4';
        a[4] = '5';
        a[5] = '6';
        a[6] = '7';
        a[7] = '8';
        a[8] = '9';
        goto labell;
    }

    printf("\nPress any key to exit");
    getch(); //To stop the program from ending
}