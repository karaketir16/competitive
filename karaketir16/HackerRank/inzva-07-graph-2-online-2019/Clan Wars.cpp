#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
using namespace std;
typedef long long int lint;
vector<vector<int>> v(N);
vector<int> color(N);
bool dfs(int a)
{
    int own = color[a];
    int ch = own == 1 ? 2 : 1;
    for(auto x : v[a])
    {
        if(color[x]==own) return false;
        else if(color[x]==0)
        {
            color[x] = ch;
            if(!dfs(x)) return false;
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    lint n,m;
    cin>>n>>m;

    
    FOR0(m)
    {
        int x, y;
        cin >> x>> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    bool tst = true;
    FOR0(N)
    {
        int x = color[i];
        if(x==0)
        {
            color[i] = 1;
            tst = dfs(i) ? tst : false;
        }
    }
    cout << (tst ? "Fight will be awesome" : "Boring");
    return 0;
}