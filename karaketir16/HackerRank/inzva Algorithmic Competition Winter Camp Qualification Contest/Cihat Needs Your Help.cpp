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
#define FOR(x) for(int i = 0;i<x;i++)
using namespace std;
typedef long long int lint;

struct Node
{
    bool visited = false;
    vector<pair<lint,lint>> adj; // path, adj
};
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<Node> nodes(N);
    FOR(m)
    {
        int x,y,z;
        cin>>x>>y>>z;
        nodes[x].adj.pb(MP(z,y));
        nodes[y].adj.pb(MP(z,x));
    }

    priority_queue<pair<pair<lint,lint>, lint>> pq;
    pq.push(MP(MP(0, 1), 0));

    while(!pq.empty())
    {
        auto a = pq.top();
        pq.pop();
        int node = a.fi.sc;
        int path = -1*a.fi.fi;
        lint maxx = a.sc;
        if(node == n)
        {
            cout.setf(ios::fixed);
            cout << setprecision(0) <<path;
            return 0;
        }
        nodes[node].visited = true;
        path +=maxx/2;
        for(auto x:nodes[node].adj)
        {
            int no = x.sc;
            lint pt = x.fi;
            if(!nodes[no].visited)
            {
                pq.push(MP(MP(-1*(pt+path-max(maxx, pt)/2), no), max(maxx, pt)));
            }
        }
    }
    cout<<-1;
    return 0;
}