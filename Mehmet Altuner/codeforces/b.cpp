#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <vector <int>> affects(n+5);
    vector <bool> affected(n+5, false);
    int ar[n+5];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }

    int affected_counter = 0;
    for(int i=1; i<n-1; i++){
        if(!ar[i]){
            if(ar[i-1] && ar[i+1]){// if it is disturbed
                affected[i] = true;
                affected_counter++;
                affects[i-1].push_back(i);
                affects[i+1].push_back(i);
            } 
        }
    }

    priority_queue <pair <int, int>> pq; // number they affect, flat number
    for(int i=0; i<n; i++){
        if(affects[i].size()){
            pq.push(make_pair(affects[i].size(), i));
        }
    }

    int counter = 0;
    while(!pq.empty()){
        pair <int, int> item = pq.top(); pq.pop();
        bool incremented = false;
        for(auto a: affects[item.second]){
            if(affected[a]){
                affected[a] = false;
                if(!incremented){
                    incremented = true;
                    counter++;
                }
                    
            }
        }
        bool go_on = false;
        for(int i=0; i<n; i++){
            if(affected[i])
                go_on = true;
        }
        if(!go_on)
            break;
    }
    cout << counter;
    return 0;
}
