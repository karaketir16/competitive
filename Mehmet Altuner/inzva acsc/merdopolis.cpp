https://www.hackerrank.com/contests/inzva-acsc-foundation-upsolving/challenges/merdopolis/
#include <bits/stdc++.h>

using namespace std;

pair <int, int> max_distance; // index node, distance
vector <int> adj[100010];
int distances[100010];
bool stations[100010];
bool visited[100010];

void dfs(int starting_point, int n){
    stack <int> stck;
    max_distance.first = starting_point; max_distance.second = 0;
    for(int i=1; i<=n; i++){
        visited[i] = false;
    }
    stck.push(starting_point);
    while(!stck.empty()){
        int node = stck.top(); stck.pop();
        visited[node] = true;

        if(stations[node]){
            if(distances[node] > max_distance.second){
                max_distance.second = distances[node];
                max_distance.first = node;
            }
        }
    
        for(auto adj_node: adj[node]){
            if(visited[adj_node])
                continue;
            distances[adj_node] = distances[node] + 1;
            stck.push(adj_node);
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n-1; i++){
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    for(int i=0; i<k; i++){
        int index;
        cin >> index;
        stations[index] = true;
    }
    
    dfs(1, n);
    distances[max_distance.first] = 0;
    dfs(max_distance.first, n);
    cout << max_distance.second << '\n';
    
    return 0;
}