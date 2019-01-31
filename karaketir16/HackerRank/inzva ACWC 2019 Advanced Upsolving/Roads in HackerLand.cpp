#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 2000005
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;

vector<int> uf(N);

int find(int x)
{
    if(x!=uf[x]) uf[x] = find(uf[x]);
    return uf[x];
}

vector<vector<pair<int, int>>> adj;

vector<bool> visited;

vector<lint> result(N);
int n;


lint dfs(lint node)
{
    visited[node] = true;

    lint tot = 0;
    FORE(adj[node])
    {
        int len = a.first;
        int no = a.second;
        if(visited[no]) continue;

        lint x = dfs(no);
        tot += x;
        result[len] = x*(n-x);
    }
    //dbg(tot);
    return tot+1;
}
int main()
{
    std::ios::sync_with_stdio(false);


    FOR0(N) uf[i] = i;

    int m;

    cin >> n >> m;
    
    adj = vector<vector<pair<int, int>>> (n+1);

    visited = vector<bool> (n+1, false);

    priority_queue<
                    pair<int, pair<int, int>>,
                    vector<pair<int, pair<int, int>>>,
                    greater<pair<int, pair<int, int>>>
                    > pq;
    
    FOR0(m)
    {
        int x, y, z;
        cin >> x >> y >> z;

        pq.push({z, {x, y}});
        
    }
    lint test = 0;
    while(!pq.empty())
    {
        int len = pq.top().first;
        int n1 = pq.top().second.first;
        int n2 = pq.top().second.second;
        pq.pop();

        if(find(n1)!=find(n2))
        {
            uf[uf[n1]] = uf[n2];
            adj[n1].push_back({len, n2});
            adj[n2].push_back({len, n1});
            test += len;
        }
    }
    dfs(1);


    for(int i = 0; i+1 <N; i++)
    {
        lint a = result[i];
        result[i] = a%2;
        result[i+1] += a/2;
    }
    bool f = false;
    for(int i = N - 1; i>=0; i--)
    {
        if(result[i]!=0) f = true;

        if(f) cout<<result[i];
    }
    return 0;
}

