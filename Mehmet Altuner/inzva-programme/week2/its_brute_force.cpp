#include <bits/stdc++.h>

using namespace std;

int best = 99999999999;
int ar[30];

int abs(int x){
    return x < 0 ? -x : x;
}

void cal(int index, int sum, bool empty){
    if(index < 0 && abs(sum) <= best && !empty){
        best = abs(sum);
        return;
    }

    if(index < 0)
        return;

    cal(index-1, sum, empty);
    cal(index-1, sum + ar[index], false);
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }

    cal(n-1, 0, true);
    cout << best << endl;
    return 0;
}