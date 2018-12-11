#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;


typedef long long int lint;
int main()
{
    lint result=0;
    lint onceki=0;
    lint carpan=1;
    string s;
    cin>>s;
    reverse(s.begin(), s.end());
    for(auto c: s)
    {
        int i = c-'0';
        onceki += (carpan*i)%mod;
        onceki%=mod;
        result+=onceki;
        result%=mod;
        carpan*=10;
        carpan++;
        carpan%=mod;
    }
    cout<<result;
    return 0;
}
