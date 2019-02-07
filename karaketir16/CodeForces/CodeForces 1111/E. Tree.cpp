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
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
std::vector<std::vector<lint>> adj;

int main()
{
    std::ios::sync_with_stdio(false);
    lint n, q;
    cin >>n>>q;

    adj = std::vector<std::vector<lint> > (n+1);
    std::vector<bool> visited(n+1, false);
    FOR0(n)
    {
        lint u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	return 0;
}

