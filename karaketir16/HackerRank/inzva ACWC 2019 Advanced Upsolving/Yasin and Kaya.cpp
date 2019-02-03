#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf 1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1005
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;

int n;
vector <pair <int,int>> v;
set <int> s;
int sz;
map <int,int> mp;
int diff;
int ans = MOD;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        v.pb({a,b});
        s.insert(b);
    }
    sz = s.size();
    sort(ALL(v));

    int p=0,q=0;


    while(p < n)
    {
        if(mp[v[p].second]==0)
            diff++;
        mp[v[p].second]++;

        while(diff == sz)
        {
            if((v[p].first - v[q].first) < ans)
                ans = (v[p].first - v[q].first);
            if(mp[v[q].second]==1)
                diff--;
            mp[v[q].second]--;
            q++;
        }

        p++;
    }
    
    cout << ans << endl;
    return 0;
}
//by salihfc