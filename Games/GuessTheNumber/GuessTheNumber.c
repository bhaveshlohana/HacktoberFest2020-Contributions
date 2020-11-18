#ifdef _WIN32
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#endif

#ifdef linux
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#endif

int menu();

int main()
{
    int num, menu_state1=0, menu_state2=0, loop=1;
    char* state1_options[2];
    char* state2_options[3];    

    // menu screen one
    state1_options[0] = "start";
    state1_options[1] = "select mode";

    // menu screen two
    state2_options[0] = "easy";
    state2_options[1] = "medium";
    state2_options[2] = "hard";

    // Seed value for random number
    srand((unsigned) time(0));

    printf("Welcome to the Game!\n");
    printf("To quit press q\n");
    while(loop) 
    {
        menu_state1 = menu(2, state1_options);
        switch (menu_state1)
        {
        case 0:
            loop = 0;
            break;
        case 1:
            menu_state2 = menu(3, state2_options);
            break;
        }
    }

    // Set the dificulty level based on the menu_state2
    int tries = menu_state2 == 1 ? 100 : (menu_state2 == 2 ? 50 : 10);
    // generate the random number
    int random = rand() % (tries*10);

    printf("\nEnter a number between %d\n", tries*10-1);
    printf("Enter a number to start the game:- ");
    for (size_t i = 0; i < tries; i++)
    {
        scanf(" %d", &num);
        printf("You entered %d\n", num);

        if (num > random)
            printf("Lower!\n");
        else if (num < random)
            printf("Higher!\n");
        else {
            printf("\nCongratulations You WON!!!!!\n");
            exit(EXIT_SUCCESS);
        }
    }
    
    return 0;
}

int menu(int no_of_options, char* options[]) 
{
    // two charachers to read arrow keys
    char menu_ch1, menu_ch2;

    // "a H" for KEY_UP
    // "a P" for KEY_DOWN
    // "a K" for KEY_LEFT
    // "a M" for KEY_RIGHT
    // lookup on Grey codes for more info
    int option=1;
    system("clear");
    while(1)
    {
        for (int i=0; i<no_of_options; i++)
        {
            if (i == option)
                printf("* ");
            else printf("  ");
            printf("%s\n", options[i]);
        }

        menu_ch1 = getch();
        if (menu_ch1 == -32) 
        {
            menu_ch2 = getch();
            switch(menu_ch2)
            {
                case 'H': // UP
                    option--;
                    break;
                case 'P': // DOWN
                    option++;
                    break;
                case 'K': // LEFT
                    option--;
                    break;
                case 'M': // RIGHT
                    option++;
                    break;
            }
            option%=no_of_options;
        }

        if (menu_ch1 == 'q')
            exit(EXIT_SUCCESS);
        else if (menu_ch1 == 13)
            return option;

        //printf("\e[1;1H\e[2J");
        system("clear");
    }
}
