#include <bits/stdc++.h>
#define pb push_back
#define mod 1000000007
#define N 300005
#define MP make_pair
#define inf	1000000000000000LL
using namespace std;
typedef long long int lint;

struct Node 
{
    lint gas;
    lint maxx=0;
    vector<pair<int, lint>> adj; // adj, road
    bool visited =0;
};
vector<Node> cities(N);
lint dfs(int node)//return max1
{
    //if(cities[node].visited) return -1*inf;
    cities[node].visited=1;
    lint max1=0,max2=0, temp=0;
    for(auto p:cities[node].adj)
    {
        int child = p.first;
        int road = p.second;
        if(cities[child].visited) continue;
        lint x = dfs(child);
        
        
        lint mal = x+cities[child].gas-road;
        if(max2<mal) swap(max2, mal);
        if(max2>max1) swap(max2, max1);
    }
    cities[node].maxx = cities[node].gas+max1+max2;
    return max1; 
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i =1 ;i<=n ;i++)
    {
        cin>>cities[i].gas;
    }
    for(int i =0 ;i<n-1;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        cities[x].adj.pb(MP(y, z));
        cities[y].adj.pb(MP(x, z));
    }
    dfs(1);
    lint maxx = -1*inf; 
    for(auto x: cities)
    {
        maxx=max(x.maxx,maxx);
    }
    cout<<maxx;
    return 0;
}