#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    for(char &a:s1)
    {
        a = tolower(a);
    }
    for(char &a:s2)
    {
        a = tolower(a);
    }
    if(s1>s2) cout<<1;
    else if(s1 == s2) cout<<0;
    else cout<<-1;
    return 0;
}