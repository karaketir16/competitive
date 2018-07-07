    https://www.hackerrank.com/contests/inzva-acsc-foundation-upsolving/challenges/kruskalmstrsub
    #include <bits/stdc++.h>
    using namespace std;

    int g_nodes, g_edges;
    int edges[5000000][3];
    int link[30001];
    //int size[3000];

    int find(int index){ // finds the leader
        if(link[index] == index)
            return index;
        link[index] = find(link[index]);
        return link[index];
    }

    bool same(int a, int b){
        return find(a) == find(b);
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(!same(a, b)){
            link[a] = b;
        }
        return;
    }

    int main(){

        cin >> g_nodes >> g_edges;
        priority_queue <pair<int, int> > min_edge; // weight of edge and index of edge
        bool nodes[3001]; // bool inside of my tree

        for(int i=0; i<g_edges; i++){
            int g_from, g_to, g_weight;
            cin >> g_from >> g_to >> g_weight;
            edges[i][0] = g_from;
            edges[i][1] = g_to;
            edges[i][2] = g_weight;
            min_edge.push({-g_weight, i});
        }
        // initialize groups
        for(int i=1; i<=g_nodes; i++){
            link[i] = i;
            nodes[i] = false;
            //size[i] = 1;
        }

        // initially get the smallest edge
        int small = min_edge.top().second; min_edge.pop();
        // create my first group
        unite(edges[small][0], edges[small][1]);
        nodes[edges[small][0]] = true;
        nodes[edges[small][1]] = true;

        int weight = edges[small][2];

        
        while(!min_edge.empty()){
            int new_small = min_edge.top().second; min_edge.pop();
            if(edges[new_small][2] == min_edge.top().first){
                int next_edge = min_edge.top().second;
                if(edges[new_small][0] + edges[new_small][1] + edges[new_small][2] > edges[next_edge][2] + edges[next_edge][1] + edges[next_edge][0]){
                    min_edge.pop();
                    min_edge.push({-edges[new_small][2], new_small});
                    new_small = next_edge;
                }
            }
            
            if(same(edges[new_small][0], edges[new_small][1])){
                continue;
            }else{
                unite(edges[new_small][1], edges[new_small][0]);
            }
            
            weight += edges[new_small][2];

        }
        

        cout << weight << '\n';
        return 0;
    }