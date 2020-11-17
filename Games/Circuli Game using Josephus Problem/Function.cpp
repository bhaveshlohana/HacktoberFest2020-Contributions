#include "list.h"
void list::start() {
		cout << "\n\t\t    -------->"; Sleep(300); cout << "  `` WELCOME TO GAME "; Sleep(200); cout << "`` <---------"; Sleep(200); cout << endl;
		cout << "\t\t\t\t|  Yas'su - Panju |"; Sleep(300); cout << "\n\t\t\t\t|    GOOD LUCK    |" << endl << endl;
		Sleep(600);
}
//////////////////////////////////
void list::totalPlayers() {
	int numberOfPlayers;
	do {
		cout << "\nEnter Total No of Players | : ";

		cin >> numberOfPlayers;
			if (numberOfPlayers < 2) {
			cout << "\n\t\t\t| Enter Atleast Two Players !|";
			}
	} while (numberOfPlayers < 2);
	size = numberOfPlayers;
	cout << "\n\t\t\t|Successfully !!! Registered <" << size << "> Players !| ";
};
/////////////////////////////////
void list::addPlayers() {
	if (size > 0) {
		string name;
		for (int a = 1; a <= size; a++)
		{
			newnode = new Node();
			cout << "\n\t\t\t | Player : " << a << " |";
			/////////
			cout << " Enter Name | : ";
			cin >> ws;
			getline(cin, name);
			newnode->setname(name);
			//////
			int finger;
			do {
				cout << "\n\t\t\t\t\t\tEnter Fingers | : ";
				cin >> finger;
				if (finger < 1 || finger>5) {
					cout << "\n\t\t\t| * Enter Fingers within Limit {1-5} * |";
				}
			} while (finger < 1 || finger>5);
			newnode->setfingers(finger);

			if (headnode == nullptr)
			{
				headnode = newnode;
				cn = headnode;

			}

			newnode->setnext(headnode);
			newnode->setprev(cn);
			cn->setnext(newnode);
			cn = newnode;
			headnode->setprev(newnode);
		}
		inputsize = size;
		displayPlayers();
	}else
		cout << "\n\t\t\t| Alert!!! Input Total no of Players First |";
}
void list::displayPlayers() {
	int player = 1;
	Node* temp = headnode;
	cout << "\n\t\t****_-MEMBERS LIST_-****\n";
	while (player <=size)
	{
		cout << "\t  |Fingers = " << temp->getfingers() << "\t\t\t" << temp->getname() << "|" << endl;
		temp = temp->getnext();
		player++;	
	}
	cout << " \t   _____________________________________\n";
	cout << "\t\t\t Total Fingers = "<<totalFingers();
	cout << " \n\t   _____________________________________\n";
}

int list::totalFingers()
{
	Node* temp = headnode;
	int player = 1;
	int totalFingers = 0;
	while (player <= size)
	{
		totalFingers = totalFingers + temp->getfingers();
		player++;
		temp = temp->getnext();
	}
	return totalFingers;
}
void list::josephProblem() {
	playersArray = new string[size+1];
	Node* temp = headnode;
	cn = headnode;
	int totalfingerssize = totalFingers();
	for(int times=1;times<=size;times++)
	{
		for (int player = 1; player <totalfingerssize; player++) {
			temp = temp->getnext();
			cn = temp->getprev();
		}
			cn = temp->getprev();
			cn->setnext(temp->getnext());
			(temp->getnext())->setprev(cn);
			playersArray[times] = temp->getname();//array storing winners
			cout << "\n\t| Alert!!! "<<temp->getname()<<" Elimnated and got <"<<times<<"> Position |";
			delete temp;
			temp = cn->getnext();
	}
	cout << "\n\t\t\t| Josephous Problem Applied Successfully |";
	headnode = nullptr;
}
void list::result() {
	if (headnode == nullptr) {

		cout << "\n\t\t    ****_-Result LIST_-****\n";
		for (int a = 1; a <= size; a++)
		{
			cout << "\t\t<" << a << ">\t\t\t" << playersArray[a]<<endl;
		}
		cout << " \t\t   _____________________________________\n";
		cout << "\t\t\t Total Players = " << size;
		cout << " \n\t\t   _____________________________________\n";
	}
	else {
		cout << "\n\t\t\t| Alert!!! First Apply Josephous Problem |";
	}

}
bool list::isEmpty() {
	if (inputsize == 0)
	{
		cout << "\n\t\t\t| Alert!!! Input Data of Players First |";
		return true;
	}
	else
		return false;
}