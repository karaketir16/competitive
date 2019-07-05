#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)2e5+5)
#define MOD ((int)1e9 + 7) 
#define lint int
#define _ << " " <<
#define TRACE(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);

	lint n, a, b;
	cin >> n >>a>>b;

    vector<vector<lint>> groups;
    set<lint> s;
    for(int i = 0; i < n; i++)
    {
        lint x;
        cin>>x;
        if(x >= a && x<=b)
        {
            s.insert(x);
        }
        else
        {
            if(s.size() > 0)
            {
                // cout<<"x: "<<x<<endl;
                groups.push_back(vector<lint> (s.begin(), s.end()));
                // for(auto xx: s) cout<<xx<<' ';
                // cout<<endl;
                s = set<lint> ();
            }
            else continue;
        }
    }
    if(s.size() > 0)
    {
        // cout<<"x: "<<x<<endl;
        groups.push_back(vector<lint> (s.begin(), s.end()));
        // for(auto xx: s) cout<<xx<<' ';
        // cout<<endl;
        s = set<lint> ();
    }
    lint k = b - a + 1;

    lint sz = groups.size();
    // cout<<"sz: "<<sz<<endl;
    // for(auto g: groups)
    // {
    //     for(auto c: g) cout<< c<<" ";
    //     cout<<endl;
    // }
    lint minGr = 1e9;
    for(lint i = 0; i < (1<<sz); i++)
    {
        lint gr = __builtin_popcount(i);
        if(gr > minGr) continue;
        vector<lint> tmp(1e5);
        int ss=0;
        for(lint j = 0; j < sz; j++)
        {
            if(i & (1<<j))
            {
                for(auto xxx:groups[j]) 
                {
                    assert(xxx<=(int)1e5);
                    if(tmp[xxx] == 0) ss++;
                    tmp[xxx]++;
                }
            }
        }

        if((int)ss >= k) minGr = min(minGr, gr);
    } 
    cout << (minGr == (lint)1e9 ? -1: minGr);
	return 0;
}

//	g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a a.cpp
//	g++ -std=c++17 -Wshadow -Wall -o a.out 4F2.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

