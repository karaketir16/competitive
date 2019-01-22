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
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;

typedef pair<int,pair<int,int>> edge;
typedef vector<edge> weigthed_graph;
bool BellmanFord(weigthed_graph &g, int V, int src) 
{ 
    int E = g.size(); 
    lint dist[V]; 
    //this implemantation is just for negative cycle check
    // init distance array
    for (int i = 0; i < V; i++) 
        dist[i]   = inf; 

    dist[src] = 0; 
    for (int i = 1; i <= V-1; i++) 
    { 
        for (int j = 0; j < E; j++) 
        { 
            lint u = g[j].second.first, v = g[j].second.second; 
            lint weight = g[j].first; 
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                dist[v] = dist[u] + weight; 
        } 
    }
    bool res = 0;
    for (int i = 0; i < E; i++) 
    { 
        lint u = g[i].second.first, v = g[i].second.second; 
        lint weight = g[i].first;  
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
            res = 1; 
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        weigthed_graph a;
        int n, m;
        cin >> n >> m;
        FOR0(m)
        {
            int u, b, c;
            cin >> u>> b>> c;
            a.pb({c, {u, b}});
        }

        cout << (BellmanFord(a, n, 0) ? "possible\n" : "not possible\n");
    }
    return 0;
}