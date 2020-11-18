/* 
C++ implementation of Hangman Game
Created By - miraajkadam
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

vector <string> words = {"park", "laptop", "keyboard", "football", "cricket", "internet", "serial", "editor", "tab"};
vector<vector<string>> hangman = {
	{"-----", "| |  "},
	{"-----", "| |  ", "| O  "},
	{"-----", "| |  ", "| O  ", "| |  ", "| |  "},
	{"-----", "| |  ", "| O  ", "|\\|", "| |  "},
	{"-----", "| |  ", "| O  ", "|\\|/", "| |  "},
	{"-----", "| |  ", "| O  ", "|\\|/", "| |  ", "|/   "},
	{"-----", "| |  ", "| O  ", "|\\|/", "| |  ", "|/ \\"},
};

int main () {
	srand(time(0));
	string choosen = words[rand() % words.size()]; // chooses a random word from words
	int length = choosen.size(), chances = 6, countee = 0; // chances are equal to no o
	vector<char> word;
	vector<char>::iterator itr;

	for (int i = 0; i < length; i++) // convert choosen word into vector of characters
		word.push_back(choosen[i]);

	vector<char> guessed;
	bool noGuess = true;

	for (int i = 0; i < 2; i++)
		cout << hangman[0][i] << endl;
	cout << endl;

	cout << "word: ";

	for (auto i : word)
		cout << "_ ";
	cout << endl;

	vector<int> spvec = {length};

	while (chances--) {
		cout << endl;
		int spaces = 0;

		cout << "Enter a character: ";
		char ch; cin >> ch;

		if (find(guessed.begin(), guessed.end(), ch) != guessed.end() && guessed.size() > 0) { // check is ch already guessed
			cout << "You have already guessed that character...!" << endl;
			cout << "Guessed: ";
			for (int i = 0; i < guessed.size(); i++) {
				cout << guessed[i] << " ";
			}
			cout << endl << "Word: ";
			for (int i = 0; i < word.size(); i++) {
				itr = find(guessed.begin(), guessed.end(), word[i]);
				if (itr != guessed.end()) {
					cout << *itr << " ";
				}
				else {
					cout << "_ ";
				}
			}
			chances++; // give extra chance if ch already in guessed
			spaces = 1;
		}
		else {
			guessed.push_back(ch);
			cout << "Word: ";
			for (int i = 0; i < word.size(); i++) {
				itr = find(guessed.begin(), guessed.end(), word[i]);
				if (itr != guessed.end()) {
					cout << *itr << " ";
				}
				else {
					cout << "_ ";
					spaces++;
				}
			}
			cout << endl;

			spvec.push_back(spaces);

			if (spvec[spvec.size() - 1] != spvec[spvec.size() - 2]) { // check if user guessed right character
				chances++;
				for (int i = 0; i < hangman[countee].size(); i++) {
					cout << hangman[countee][i] << endl;
				}
			}
			else {
				countee++;
				for (int i = 0; i < hangman[countee].size(); i++) {
					cout << hangman[countee][i] << endl;
				}
			}
		}

		if (!spaces) { // check if won before chances are over
			cout << endl << "Congratulations! You Won...!";
			noGuess = false;
			break;
		}

		cout << endl;
	}

	if (noGuess) // if user couldn't guess
		cout << "\n\nYou ran out of chances!\nThe word was: " << choosen;

	return 0;
}