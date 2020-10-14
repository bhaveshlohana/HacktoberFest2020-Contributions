#include "Node.h"
#include <windows.h>
class list {
	int size;
	int inputsize;
	Node* headnode;
	Node* cn;
	Node* newnode;
	string* playersArray;
public:
	void start();
	void totalPlayers();
	void addPlayers();
	void displayPlayers();
	int totalFingers();
	void josephProblem();
	void deletePlayer(Node* cn);
	void result();
	bool isEmpty();
///////////////////////////
	list() {
		size = 0;
		inputsize = 0;
		headnode = nullptr;
		cn = nullptr;
		playersArray = nullptr;
		newnode = nullptr;
	}
	~list(){

	}
};
