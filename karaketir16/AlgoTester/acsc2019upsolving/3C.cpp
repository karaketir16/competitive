#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    vector<int> adj;
    bool visited = false;
};
vector<Node> nodes(1e5 + 5);
int dfs(int node)
{
    if(nodes[node].visited) return 0;
    nodes[node].visited = true;
    int count = 1;
    for(auto& a: nodes[node].adj)
    {
        count += dfs(a);
    }
    return count;
}
int main()
{

    int n, m;
    cin>>n>>m;

    int x, y;
    for(int i = 0; i< m; i++)
    {
        cin>>x>>y;
        nodes[x].adj.push_back(y);
        nodes[y].adj.push_back(x);
    }
    vector<int> sizeCounts;
    for(int i =1; i<=n; i++)
    {
        if(nodes[i].visited) continue;

        sizeCounts.push_back(dfs(i));
    }
    bitset<(int)1e5 + 5> bs;
    bs[0] = 1;
    for(auto &a: sizeCounts)
    {
        bs = (bs | (bs << a));
    }
    cout << (bs.count());
    return 0;
}