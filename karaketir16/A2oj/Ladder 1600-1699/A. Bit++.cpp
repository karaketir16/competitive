#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin>>a;
    int res = 0;

    while(a--)
    {
        string s;
        cin>>s;
        if(s[1] == '+') res++;
        else res--;
    }
    cout<<res;
    return 0;
}