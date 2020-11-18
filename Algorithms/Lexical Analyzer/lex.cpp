#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> keywords = {"int", "main", "cout"};
vector<string> operators = {"+", "-", "/", "*", "="};
vector<string> ignore = {"()", "{", ",", ";", "<<", "}"};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("in.txt", "r", stdin);

	string s;
	while (cin >> s && s != "\0") {
		if (find(keywords.begin(), keywords.end(), s) != keywords.end())
			cout << s << " is a keyword" << endl;

		else if (find(operators.begin(), operators.end(), s) != operators.end())
			cout << s << " is a operator" << endl;

		else if (find(ignore.begin(), ignore.end(), s) != ignore.end())
			continue;

		else
			cout << s << " is a identifier" << endl;
	}
}