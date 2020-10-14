#include <iostream>
#include"list.h"

using namespace std;

int main() 
{
    list l; l.start();
   string choice;
   string ch;
   do {
       
        cout << "\n\n\n\t********************Main Menu**********************\n\n";
        cout << "\n\t|\t1 : Total no of Players. \t\t  |";
        cout << "\n\t|\t2 : Input Data (Name/Fingers). \t\t  |";
        cout << "\n\t|\t3 : Display Record. \t\t\t  |";
        cout << "\n\t|\t4 : Apply Josephous Problem. \t\t  |";
        cout << "\n\t|\t5 : Result.\t\t\t\t  |";
        cout << "\n\t|\t6 : Exit. \t\t\t\t  |";
        cout << "\n\n Enter your choice : \t->";
        cin >> ws;
        getline(cin, choice);
        switch (choice[0]) {
        case '1':
            l.totalPlayers();
            break;
        case '2':

            l.addPlayers();
            break;
        case '3':
            if (!l.isEmpty())
            l.displayPlayers();
            break;
        case '4':
            if (!l.isEmpty())
            l.josephProblem();
            break;
        case '5':
            if(!l.isEmpty())
            l.result();
            break;
        case '6': {
            cout << "\n Are you sure to Exit : Y/N : -> ";
            getline(cin, ch);
            if (ch[0] == 'Y' || ch[0] == 'y')
                choice = "6";
            else
                choice = "0";
        }
            break;
        default:
            cout << "\n Alert!!! Invalid Option";
        }
    } while (choice != "6");


}