#include <bits/stdc++.h>

using namespace std;

void bfs(vector <int> adj[], int s, int n, int m){
    queue <int> q;
    int dist[n+1];
    bool visited[n+1];
    for(int i=0; i<n+1; i++) dist[i] = 0;
    dist[s] = 0;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto child: adj[node]){
            if(visited[child]) continue;
            dist[child] = dist[node] + 1;
            q.push(child);
            visited[child] = true;
        }
    }
    for(int i=1; i<=n; i++){
        if(dist[i] == 0) dist[i] = -1;
        else dist[i] *= 6;
        if(i != s) cout << dist[i] << ' ';
        
    }
    cout << '\n';
}

int main(){
    int q;
    cin >> q;
    while(q--){
        int n, m, s;
        cin >> n >> m;
        vector <int> adj[n+1];
        for(int i=0; i<m; i++){
            int s, e;
            cin >> s >> e;
            adj[s].push_back(e);
        }
        cin >> s;
        bfs(adj, s, n, m);
    }
    return 0;
}