#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli counter;
int n;
vector <vector <int>> ar;

void open(lli r, lli c){
    stack <pair <int, int> > s;
    s.push(make_pair(r, c));

    while(!s.empty()){
        pair <int, int> i = s.top(); s.pop();
        int row = i.first, column = i.second;

        if(row < 0 || row >= n || 
            column < 0 || column >= n)
                continue;
        
        if(ar[row][column]){
            counter++;
            ar[row][column] = 0;
            s.push(make_pair(row+1, column));
            s.push(make_pair(row-1, column));
            s.push(make_pair(row, column+1));
            s.push(make_pair(row, column-1));
        }
    }
}

int main(int argc, char const *argv[]){
     scanf("%d ", &n); 
     ar.resize(n, vector <int>(n, 0));   
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            scanf("%d", &ar[i][j]);
    }

    int r, c;
    scanf("%d %d", &r, &c);
    
    counter = 0;
    open(r, c);

    printf("%lli", counter);
    return 0;
 }