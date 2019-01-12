#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector <vector <lli>> ar(n+5, vector <lli>(m+5));
    vector <vector <lli>> distance(n+5, vector <lli>(m+5, LLONG_MAX));
    vector <vector <bool>> visited(n+5, vector <bool>(m+5, false));
    priority_queue <pair <lli, pair <lli, lli>>> pq; // distance, y, x
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%lli", &ar[i][j]);
        }
    }

    // ar[y][x]

    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    pq.push(make_pair(0, make_pair(y2, x2)));
    distance[y2][x2] = 0;

    while(!pq.empty()){
        pair <lli, pair <lli, lli>> p = pq.top(); pq.pop();
        lli d = -p.first; lli y = p.second.first; lli x = p.second.second;
        if(visited[y][x])
            continue;

        visited[y][x] = true;

        // go for the children

        // left children
        if(x > 1){
            lli w = abs(ar[y][x-1] - ar[y][x]);
            if(distance[y][x-1] >= max(d, w)){
                distance[y][x-1] = max(d, w);
                pq.push(make_pair(-distance[y][x-1], make_pair(y, x-1)));
            }
        }

        // right children
        if(x < m){
            lli w = abs(ar[y][x+1] - ar[y][x]);
            if(distance[y][x+1] >= max(d, w)){
                distance[y][x+1] = max(d, w);
                pq.push(make_pair(-distance[y][x+1], make_pair(y, x+1)));
            }
        }

        // up children
        if(y > 1){
            lli w = abs(ar[y-1][x] - ar[y][x]);
            if(distance[y-1][x] >= max(d, w)){
                distance[y-1][x] = max(d, w);
                pq.push(make_pair(-distance[y-1][x], make_pair(y-1, x)));
            }
        }

        // down children
        if(y < n){
            lli w = abs(ar[y+1][x] - ar[y][x]);
            if(distance[y+1][x] >= max(d, w)){
                distance[y+1][x] = max(d, w);
                pq.push(make_pair(-distance[y+1][x], make_pair(y+1, x)));
            }
        }
    }

    printf("%lli", distance[y1][x1]);

    return 0;
}