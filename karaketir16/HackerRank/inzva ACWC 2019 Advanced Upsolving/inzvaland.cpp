#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
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
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
vector<vector<pair<lint, lint>>>  cities(N);  //len, node
vector<bool> visited(N, false);
vector<lint> dist(N, inf);
void dfs(int start, lint di)
{
    visited[start] = true;
    dist[start] = di;
    FORE(cities[start])
    {
        lint len = a.first, node = a.second;
        if(!visited[node]) dfs(node, di+len);
    }
    
}
int main()
{
    std::ios::sync_with_stdio(false);

    lint n, z;
    cin>> n>> z;


    FOR0(n-1)
    {
        lint a, b, c;
        cin>>a>>b>>c;
        cities[a].pb({c,b});
        cities[b].pb({c,a});
    }
    dfs(1, 0);
    lint maxi = 1;
    FOR1(n)
    {
        if(dist[i]>dist[maxi]) maxi = i;
    }
    visited = vector<bool> (N, false);
    dist = vector<lint> (N, inf);
    dfs(maxi, 0);
    lint maxd = 0;
    FOR1(n)
    {
        if(dist[i]>maxd) maxd = dist[i];
    }
    printf("%lld", maxd*z);
    return 0;
}