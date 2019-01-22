#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1000005
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
    int depends=-1; //benden once yapilmasi gereken sayisi
    vector<int> adj; // benden sonra yapilmasi gerekenler
};
vector<Node> nodes(N);
bool fonk(int a)
{
    if (--nodes[a].depends==0) return 1;
    return 0;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int m;
    cin>>m;
    FOR0(m)
    {
        int a,o;
        cin>>a>>o;
        if(nodes[o].depends == -1) nodes[o].depends = 0; 
        for(int i = 0; i < a - 1;i++)
        {
            int x;
            cin >> x;
            nodes[o].adj.pb(x);
            if(nodes[x].depends == -1) nodes[x].depends = 0; 
            nodes[x].depends++;
            o = x;
        }
    }
    //cout << nodes[2].depends << endl;
    int total=0;
    priority_queue<int, vector<int>, greater<int>> q;
    FOR1(N-1) if(nodes[i].depends==0) 
    {
        q.push(i);
        total++;
    }
    vector<int> result;
    while(!q.empty())
    {
        int a = q.top();
        q.pop();
        result.pb(a);
        for(auto b: nodes[a].adj)
        {
            if(fonk(b))
            {
                q.push(b);
                total++;
            }
        }
    }
    
    for(auto a: result)
    {
        cout<<a<<" ";
    }
    return 0;
}