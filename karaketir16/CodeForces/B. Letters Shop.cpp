#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    unordered_map<char, priority_queue<int, vector<int>, greater<int>>> mp;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i =1; i<=s.length();i++)
    {
        char c = s[i-1];
        mp[c].push(i);
    }
    int m;
    cin>>m;
    while(m--)
    {
        map<char, vector<int>> tmp;

        string f;
        cin>>f;

        int mx = 0;
        for(auto& c:f)
        {
            int x = mp[c].top();
            mp[c].pop();
            tmp[c].push_back(x);
            mx = max(mx, x);
        }

        cout << mx <<"\n";
        for(auto [k, q]: tmp) for(auto v:q) mp[k].push(v);
    }
    return 0;
}