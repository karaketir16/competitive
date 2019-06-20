#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
int main()
{
    int n;
    cin>>n;
    vector<int> q, v;
    vector<pair<int, int>> big;
    for(int i = 1;i<=n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    q.push_back(1);
    for(int i = 2;i<=n;i++)
    {
        int x;
        x = v[i-1];
        // cout<<x<<' '<< v[q.back()-1] << ' '<< i<<endl;
        if(x>v[q.back()-1]) big.push_back({x, i});
        else q.push_back(i);
    }
    sort(big.begin(), big.end());
    // for(auto a: q) cout<<a<<' '; cout<<endl;
    for(auto p : big) q.push_back(p.second);
    for(auto a: q) cout<<a<<' ';
    return 0;
}