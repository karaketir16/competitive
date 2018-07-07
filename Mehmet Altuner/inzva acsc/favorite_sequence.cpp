//https://www.hackerrank.com/contests/inzva-acsc-foundation-upsolving/challenges/favourite-sequence
#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1000001];
set <int> nodes;
int parent_number[1000001];
priority_queue <int> q;

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=1000000; i++)
        parent_number[i] = 0;
    
    while(n--){
        int k, last, in;
        cin >> k;
        k--;
        cin >> last;
        nodes.insert(last);
        while(k--){
            cin >> in;
            parent_number[in]++;
            nodes.insert(in);
            adj[last].push_back(in);
            last = in;
        }
    }

    for(auto n: nodes){
        if(parent_number[n] == 0){
            q.push(-n);
        }
    }
    
    while(!q.empty()){
        int index = -q.top(); q.pop();
        for(auto c: adj[index]){
            if(--parent_number[c]==0){
                q.push(-c);
            }
        }
        cout << index << ' ';
    }

    return 0;
}