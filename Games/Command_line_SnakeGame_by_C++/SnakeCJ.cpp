#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <MMsystem.h>


using namespace std;
void setup();
void draw();
void input();
void logic();
int height = 20, width = 40, gameover = 0;
int x, y, fruitx, fruity, score = 0, flag, tailX[100], tailY[100];
int counttail = 0;
int main()
{
	int m, n;  //3:50
    int ch;

	counttail = 0;
    game :
        setup();
        while (!gameover)
        {

            draw();
            input();
            logic();
            cout<<"Score = "<<score<<endl<<"Press x to exit"<<endl;

            for (m = 0; m < 10000; m++)
            {
                for (n = 0; n < 2000; n++)
                {
                }
            }
        }
        cout<<"Press 1 to Play Again"<<endl;
        cin>>ch;
        if (ch==1)
        {
            flag = 0;
            counttail = 0;
            gameover = 0;
            score = 0;
            goto game;
        }
	return 0;
}
void setup()
{
	gameover = 0;
	x = width / 2;
	y = height / 2;
label1:
	fruitx = rand() % 40;

	if (fruitx == 0)
		goto label1;

label2:
	fruity = rand() % 20;

	if (fruity == 0)
		goto label2;
}
void draw()
{

	int i, j;
	system("cls");
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
				printf("#");

			else
			{
				if (i == y && j == x)
					printf("O");

				else if (i == fruity && j == fruitx)
					printf("F");

				else
				{
					int p = 0, k;
					for (k = 0; k < counttail; k++)
					{

						if (i == tailY[k] && j == tailX[k])
						{
							printf("o");
							p = 1;
						}
					}
					if (p == 0)
						printf(" ");
				}
			}
		}
		printf("\n");
	}
}
void input()
{

	if (kbhit())
	{
		switch (getch())
		{
		case 75:
			flag = 1;
			break;

		case 77:
			flag = 2;
			break;
		case 72:
			flag = 3;
			break;

		case 80:
			flag = 4;
			break;

		case 'x':
			gameover = 1;
			break;
		}
	}
}
void logic()
{
	int i;
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2x, prev2y;
	tailX[0] = x;
	tailY[0] = y;

	for (i = 1; i < counttail; i++)
	{
		prev2x = tailX[i];
		prev2y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2x;
		prevY = prev2y;
	}

	switch (flag)
	{

	case 1:
		x--;
		break;

	case 2:
		x++;
		break;
	case 3:
		y--;
		break;

	case 4:
		y++;
		break;

	default:
		break;
	}
	if (x > width || x < 0 || y > height || y < 0)
		gameover = 1;

	for (i = 0; i < counttail; i++)
	{
		if (x == tailX[i] && y == tailY[i])
			gameover = 1;
	}
	if (y == fruity && x == fruitx)
	{
		//PlaySound(TEXT("F:\\C++ Language\\projects\\CHIMES.wav"), NULL, SND_SYNC);

	label3:
		fruitx = rand() % 20;

		if (fruitx == 0)
			goto label3;

	label4:
		fruity = rand() % 20;

		if (fruity == 0)
			goto label4;

		score = score + 10;
		counttail++;
	}
}
