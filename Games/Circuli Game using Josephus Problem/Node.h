#include <string>
#include <iostream>
using namespace std;
class Node {
	string name;
	int fingers;
	Node* next;
	Node* prev;
public:
	Node() {
		fingers = 0;
		next = nullptr;
		prev = nullptr;
		name = "Nill";

	}
	~Node() {

	}

	void setfingers(int object)
	{
		this->fingers = object;
	}
	void setnext(Node* next)
	{
		this->next = next;
	}
	void setprev(Node* prev)
	{
		this->prev = prev;
	}
	int getfingers() {
		return fingers;
	}
	Node* getnext() {
		return next;
	}
	Node* getprev() {
		return prev;
	}
	string getname() {
		return name;
	}
	void setname(string name) {
		this->name = name;

	}
};

