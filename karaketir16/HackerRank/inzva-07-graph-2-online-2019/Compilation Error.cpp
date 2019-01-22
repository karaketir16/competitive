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
struct Node
{
    int depends=0;
    vector<int> adj;
};
vector<Node> nodes;
bool fonk(int a)
{
    if (--nodes[a].depends==0) return 1;
    return 0;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    nodes = vector<Node> (n+1);
    FOR0(m)
    {
        int a,o;
        cin>>a>>o;
        nodes[o].adj.pb(a);
        nodes[a].depends++;
    }
    //cout << nodes[2].depends << endl;
    int total=0;
    queue<int> q;
    FOR1(n) if(nodes[i].depends==0) 
    {
        q.push(i);
        total++;
    }

    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        for(auto b: nodes[a].adj)
        {
            if(fonk(b))
            {
                q.push(b);
                total++;
            }
        }
    }
    //cout << total << endl;
    if(total == n) cout<<"YES";
    else cout<<"NO";
    return 0;
}