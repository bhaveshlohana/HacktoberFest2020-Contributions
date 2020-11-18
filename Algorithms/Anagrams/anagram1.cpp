#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    cout<<s1<<endl<<s2<<endl;
    for(char c:s1)
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end()); 
    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end()); 
    if(s1==s2)
    {
        cout<<"anagram"<<endl;
    }
    else
    {
        cout<<"not anagram"<<endl;
    }
    
    return 0;
}