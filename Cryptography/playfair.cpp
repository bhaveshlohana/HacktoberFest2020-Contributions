#include <bits/stdc++.h>
using namespace std;
void constructMatrix(vector<vector<char> > &mx, map<int, pair<int, int> > &mp, string key)
{
    int itr = 0;
    int l = key.length();
    int i, j;
    map<int, pair<int, int> >::iterator ptr;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5;)
        {
            if (itr == l)
                break;

            if (key[itr] - 65 == 8)
            {
                ptr = mp.find(9);
                if (ptr == mp.end())
                {
                    mp.insert(make_pair(9, make_pair(i, j)));
                    char c = 65 + 9;
                    mx[i][j] = c;
                    j++;
                }
                itr++;
            }
            else
            {
                int a = key[itr] - 65;
                ptr = mp.find(a);
                if (ptr == mp.end())
                {
                    mp.insert(make_pair(a, make_pair(i, j)));
                    mx[i][j] = key[itr];
                    j++;
                }
                itr++;
            }
        }
        if (itr == l)
        {
            if (j == 5)
            {
                j = 0;
                i++;
            }
            break;
        }
    }
    itr = 0;
    for (; i < 5; i++)
    {
        for (; j < 5;)
        {
            if (itr == 8)
            {
                ptr = mp.find(9);
                if (ptr == mp.end())
                {
                    mp.insert(make_pair(9, make_pair(i, j)));
                    char c = 65 + 9;
                    mx[i][j] = c;
                    j++;
                }
                itr++;
            }
            else
            {
                ptr = mp.find(itr);
                if (ptr == mp.end())
                {
                    mp.insert(make_pair(itr, make_pair(i, j)));
                    char c = 65 + itr;
                    mx[i][j] = c;
                    j++;
                }
                itr++;
            }
        }
        j = 0;
    }
}
string encrypt(string text, string key)
{
    vector<vector<char> > mx(5, vector<char>(5, 'a'));
    map<int, pair<int, int> > mp;
    constructMatrix(mx, mp, key);
    string output = "";
    int l = text.length();
    int j;
    map<int, pair<int, int> >::iterator ptr, itr;
    for (int i = 0; i < l - 1;)
    {
        j = i + 1;
        int x = i;
        if (text[i] == ' ')
        {
            i++;
            continue;
        }
        if (text[j] == ' ')
        {
            j++;
            x++;
        }
        int a = text[i] - 65 == 8 ? 9 : text[i] - 65;
        int b = text[j] - 65 == 8 ? 9 : text[j] - 65;
        itr = mp.find(a);
        ptr = mp.find(b);
        if (itr->second.first == ptr->second.first)
        {
            char c = mx[itr->second.first][(itr->second.second + 1) % 5];
            char d = mx[ptr->second.first][(ptr->second.second + 1) % 5];
            output = output + c + d;
        }
        else if (itr->second.second == ptr->second.second)
        {
            output = output + mx[(itr->second.first + 1) % 5][itr->second.second];
            output = output + mx[(ptr->second.first + 1) % 5][ptr->second.second];
        }
        else
        {
            char c = mx[itr->second.first][ptr->second.second];
            char d = mx[ptr->second.first][itr->second.second];
            output = output + c + d;
        }
        i = x + 2;
    }
    return output;
}

string decrypt(string text, string key)
{
    vector<vector<char> > mx(5, vector<char>(5, 'a'));
    map<int, pair<int, int> > mp;
    constructMatrix(mx, mp, key);
    string output = "";
    int l = text.length();
    int j;
    map<int, pair<int, int> >::iterator ptr, itr;
    for (int i = 0; i < l - 1; i = i + 2)
    {
        j = i + 1;
        int a = text[i] - 65 == 8 ? 9 : text[i] - 65;
        int b = text[j] - 65 == 8 ? 9 : text[j] - 65;
        itr = mp.find(a);
        ptr = mp.find(b);
        if (itr->second.first == ptr->second.first)
        {
            char c = mx[itr->second.first][(itr->second.second + 4) % 5];
            char d = mx[ptr->second.first][(ptr->second.second + 4) % 5];
            output = output + c + d;
        }
        else if (itr->second.second == ptr->second.second)
        {
            output = output + mx[(itr->second.first + 4) % 5][itr->second.second];
            output = output + mx[(ptr->second.first + 4) % 5][ptr->second.second];
        }
        else
        {
            char c = mx[itr->second.first][ptr->second.second];
            char d = mx[ptr->second.first][itr->second.second];
            output = output + c + d;
        }
    }
    return output;
}
int main()
{
    int t;
    cout << "Enter 1 for encryption 2 for decryption";
    cin >> t;
    if (t == 1)
    {
        string text, output = "", k;
        getline(cin >> ws, text);
        transform(text.begin(), text.end(), text.begin(), ::toupper);
        cout << "enter Key";
        cin >> k;
        transform(k.begin(), k.end(), k.begin(), ::toupper);
        int l = text.length();
        for (int i = 1; i < l; i++)
        {
            if (text[i] == ' ')
            {
                string ini = text.substr(0, i);
                string fi = text.substr(i + 1);
                text = ini + fi;
            }
        }
        for (int i = 1; i < text.length();)
        {
            if (text[i] == text[i - 1])
            {
                string ini = text.substr(0, i);
                string fi = text.substr(i);
                text = ini + "X" + fi;
                i++;
            }
            else
            {
                i += 2;
            }
        }
        if (text.length() % 2)
        {
            text = text + "X";
        }
        cout << encrypt(text, k);
    }
    else if (t == 2)
    {
        string text, output = "", k;
        getline(cin >> ws, text);
        transform(text.begin(), text.end(), text.begin(), ::toupper);
        cout << "enter Key";
        cin >> k;
        transform(k.begin(), k.end(), k.begin(), ::toupper);
        cout << decrypt(text, k);
    }
    else
    {
        cout << "Enter only 1 or 2" << endl;
    }
    return 0;
}