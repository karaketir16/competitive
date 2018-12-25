#include <bits/stdc++.h>
#define N 100000

using namespace std;

typedef long long int lli;

struct edge{
    lli n1;
    lli n2;
    bool deleted;
};

lli m, n, q;
vector <edge> edges;
vector <lli> parent;

lli find_parent(lli node){
    if(parent[node] == node)
        return node;

    return parent[node] = find_parent(parent[node]);
}

void unite(edge e){
    lli parent1 = find_parent(e.n1);
    lli parent2 = find_parent(e.n2);

    parent[parent1] = parent2;
    return;
}

bool sibling(lli n1, lli n2){
    return find_parent(n1) == find_parent(n2);
}

void init(){
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    return;
}

void restart(){
    init();
    for(int i=0; i<m; i++){
        if(edges[i].deleted)
            continue;

        unite(edges[i]);
    }
}

int main(int argc, char const *argv[]){
    scanf("%lli %lli %lli", &m, &n, &q);
    
    edges.resize(m+5);
    parent.resize(n+5);

    init();
    
    for(int i=0; i<m; i++){
        lli x, y;
        scanf("%lli %lli", &x, &y);
        edges[i] = edge{x, y, false};
    }

    while(q--){
        lli c;
        scanf("%lli", &c);
        if(c == 1){
            lli x;
            scanf("%lli", &x);
            edges[x-1].deleted = true;
            restart();
        }else{
            lli x, y;
            scanf("%lli %lli", &x, &y);
            
            if(sibling(x, y))
                printf("Connected\n");
            else
                printf("Not Connected\n");
        }
    }

    return 0;
}