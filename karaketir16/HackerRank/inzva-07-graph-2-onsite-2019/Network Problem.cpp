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

class Node 
{
public:
    bool visited = false;
    vector<pair<lint, lint>> adj;// len, node
};

int main()
{
    std::ios::sync_with_stdio(false);

    int n, m, k;

    cin>> n>>m >>k;
    vector<Node> nodes(n+1); 
    FOR0(m)
    {
        int x, y, z;
        cin >> x>> y>> z;
        nodes[x].adj.pb({z, y});
        nodes[y].adj.pb({z, x});
    }
    priority_queue<pair<lint, lint>, vector<pair<lint, lint>>, greater<pair<lint, lint>>> q;
    q.push({0, 1});
    lint tot = 0;
    while(!q.empty())
    {
        lint len, node;
        len = q.top().fi;

        node = q.top().sc;
        q.pop();
        if(nodes[node].visited) continue;
        if(!(k--)) break;
        tot += len;


        nodes[node].visited = true;

        
        FORE(nodes[node].adj)
        {
            if(nodes[a.sc].visited) continue;

            q.push({a.fi, a.sc});
        }
    }
    
    cout << tot <<"\n";


    return 0;
}