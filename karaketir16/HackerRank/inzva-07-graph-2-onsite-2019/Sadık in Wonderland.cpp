#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 10005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
lint n, t;
vector<pair<lint, pair<lint, lint>>> edges;
vector<lint> dist(N, inf);
void ford()
{
    dist[1] = 0;

    for(int i = 0; i < t; i++)
    {
        auto temp = dist;
        FORE(edges)
        {
            lint len = a.first, u = a.second.first, v = a.second.second;
            if(temp[u] + len < temp[v]) dist[v] = temp[u] + len;
        }

    }

}
int main()
{
    std::ios::sync_with_stdio(false);
    int m;

    cin>> n>>m >>t;
    FOR0(m)
    {
        int x, y, z;
        cin >> x>> y>> z;
        edges.pb({z, {x, y}});
    }
    ford();

    FOR1(n) cout << (dist[i]==inf ? -1 : dist[i]) << ' ';
    return 0;
}