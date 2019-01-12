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
#define orta ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
using namespace std;
typedef long long int lint;
int dfs(int i, vector<vector<int>> &v, int d)
{
    int maxx=0;
    for(auto x:v[i])
    {
        maxx=max(maxx, dfs(x, v, d+1));
    }
    return maxx+1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    vector<vector<int>> v(N);
    int n;
    cin>>n;
    for(int i=0;i+1<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[y].pb(x);
    }
    cout<<dfs(1, v, 1);
    return 0;
}