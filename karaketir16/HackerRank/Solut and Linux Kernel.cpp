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
#define orta ((a+b)/2)
using namespace std;
#define pp pair<int,int>


typedef long long int lint;
struct Node
{
    bool visited=0;
    lint deger=0;
    vector<int> childs;
};
vector<Node> nodes;
map<int,int> whr;
lint dfs(int node)
{
    if(nodes[node].visited) return nodes[node].deger;
    else nodes[node].visited=1;
    lint total=0;
    for(auto x: nodes[node].childs)
    {
        
        int a=whr[x];
        total=max(total,dfs(a));
    }
    nodes[node].deger=total+=nodes[node].deger;
    return total;
}

int main()
{

    int n,m;
    cin>>n>>m;
    vector<Node> nodess(n+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&nodess[i].deger);
    }
    map<int,int> whrr;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        int nd;
        scanf("%d",&nd);
        whrr[nd]=i;
        for(int j=0;j<x;j++)
        {
            int ch;
            scanf("%d",&ch);
            nodess[i].childs.pb(ch);
        }
    }
    nodes=nodess;
    whr=whrr;
    cout<<dfs(m);
    return 0;
}
