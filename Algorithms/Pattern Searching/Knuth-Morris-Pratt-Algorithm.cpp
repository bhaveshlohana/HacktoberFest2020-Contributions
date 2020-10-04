#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void kmpUtil(string pattern, int arr[])
{
    int m = pattern.length(), k;
    arr[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = arr[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = arr[k];
        }
        arr[i] = k + 1;
    }
}

bool KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int arr[m];
    kmpUtil(pattern, arr);
    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = arr[k];
    }
    return 0;
}


int main()
{

    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string tar = "san and linux training";
    string pat = "lin";
    if (KMP(pat, tar))
        cout << "'" << pat << "' found in string '" << tar << "'" << endl;
    else
        cout << "'" << pat << "' not found in string '" << tar << "'" << endl;
    pat = "sanfoundry";
    if (KMP(pat, tar))
        cout << "'" << pat << "' found in string '" << tar << "'" << endl;
    else
        cout << "'" << pat << "' not found in string '" << tar << "'" << endl;
    return 0;
}