#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    set<pair<int, int>> mp;
    int n;
    cin>>n;
    for(int i =0; i < n;i++)
    {
        int x, y;
        cin>>x>>y;
        mp.insert({x,y});
    }
    int mini = 0;
    for(auto [f,s]:mp)
    {
        if(mini <= s) mini = s;
        else mini = f;
    }
    cout << mini;
    return 0;
}