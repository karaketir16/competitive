#include <bits/stdc++.h>
using namespace std;
#define BN 100005

int main()
{
    ios::sync_with_stdio(0);

    map<string, int> mp;
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        int x;
        cin>>s>>x;
        mp[s] = max(mp[s], x);
    }
    int res = 0;
    for(auto p: mp)
    {
        res+=p.second;
    }
    cout <<res;
    
    return 0;
}
