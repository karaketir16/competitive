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

lint k;
lint sz;
vector<vector<lint>> groups;
//lintler int aslinda 
    bitset<32> has;
    bitset<32> maybe;
// bool check(lint x)
// {

//     for(unsigned long i = 0; i < (1<<sz); i++)
//     {
//         lint gr = __builtin_popcount(i);

//         if(gr != x) continue;
//         if((i & has.to_ulong()) ^ has.to_ulong()) continue;
//         // if(gr > minGr) continue;
//         set<lint> tmp;
//         for(unsigned long j = 0; j < sz; j++)
//         {
//             if(i & (1<<j)) tmp.insert(groups[j].begin(), groups[j].end());
//         }

//         if((int)tmp.size() == k) return true;
//     } 
//     return false;
// }
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);

	lint n, a, b;
	cin >> n >>a>>b;

    
    set<lint> s;
    set<lint> sss;
    map<lint, lint> mp;
    for(int i = 0; i < n; i++)
    {
        lint x;
        cin>>x;
        if(x >= a && x<=b)
        {
            sss.insert(x);
            s.insert(x);
        }
        else
        {
            if(s.size() > 0)
            {
                // cout<<"x: "<<x<<endl;
                groups.push_back(vector<lint> (s.begin(), s.end()));
                for(auto d:groups.back())
                {
                    mp[d]++;
                    // cout<<d<<" ";
                }
                // cout<<endl;
                // for(auto xx: s) cout<<xx<<' ';
                // cout<<endl;
                s = set<lint> ();
            }
            else continue;
        }
    }

    if((int)s.size() > 0)
    {
        // cout<<"x: "<<x<<endl;
        groups.push_back(vector<lint> (s.begin(), s.end()));
        for(auto d:groups.back())
        {
            mp[d]++;
            // cout<<d<<" ";
        }
        // for(auto xx: s) cout<<xx<<' ';
        // cout<<endl;
        s = set<lint> ();
    }

    sz = groups.size();
    k = b - a + 1;
    
    if((int)sss.size() < k) 
    {
        cout<<-1;
        return 0;
    }

    lint res = 0;
    // vector<lint> has;

    for(auto p:mp)
    {
        if(p.second == 1)
        {
            // cout<<p.first<<endl;
            for(auto it = groups.begin(); it != groups.end(); it++)
            {
                bool flag = false;
                auto g = *it;
                for(auto aa: g)
                {
                    if(aa == p.first)
                    {
                        // groups.erase(it);
                        // sz--;
                        // k--;
                        // res++;
                        has[(it - groups.begin())] = true;
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
        }
        if(p.second == 2)
        {
            // cout<<p.first<<endl;
            for(auto it = groups.begin(); it != groups.end(); it++)
            {
                // bool flag = false;
                auto g = *it;
                for(auto aa: g)
                {
                    if(aa == p.first)
                    {
                        // groups.erase(it);
                        // sz--;
                        // k--;
                        // res++;
                        maybe[(it - groups.begin())] = true;
                        // flag = true;
                        // break;
                    }
                }
                // if(flag) break;
            }
        }
    }


    // cout<<"sz: "<<sz<<endl;
    // for(auto g: groups)
    // {
    //     for(auto c: g) cout<< c<<" ";
    //     cout<<endl;
    // }
    // if(sz == 0)
    // {
    //     cout<<res;
    //     return 0;
    // }
    // lint l = 1, r = sz; 
    // while(r>l)
    // {
    //     lint mid = (l + r) / 2;
    //     if(check(mid))
    //     {
    //         r = mid;
    //     }
    //     else
    //     {
    //         l = mid +1;
    //     }
        
    // }
    // cout<<has.to_string();
    // for(int i = 1; i <= sz; i++) cout<< i <<": "<<check(i)<<endl;
    // cout<<endl;
    lint mingr = 1e9;
    for(unsigned int i = 0; i < (1<<sz); i++)
    {
        lint gr = __builtin_popcount(i);

        if(gr > mingr) continue;
        if((i & has.to_ulong()) ^ has.to_ulong()) continue;
        // if(!(i & maybe.to_ulong())) continue;
        // if(gr > minGr) continue;
        set<lint> tmp;
        for(unsigned int j = 0; j < sz; j++)
        {
            if(i & (1<<j)) tmp.insert(groups[j].begin(), groups[j].end());
        }

        if((int)tmp.size() == k) mingr = min(mingr, gr);
        if(mingr == 1) break;
    } 
    // return false;

    cout << mingr;
	return 0;
}

//	g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a a.cpp
//	g++ -std=c++17 -Wshadow -Wall -o a.out F.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

