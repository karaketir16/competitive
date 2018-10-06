#include <bits/stdc++.h>

using namespace std;

int nec(int k, int l){
    k = 2*k + 1;
    if((float)l / (float)k - l / k == 0){
        return l / k;
    }
    return (l / k) + 1;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int lit[n];

    for(int i=0; i<n; i++)
        lit[i] = 0;

    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        x--;
        for(int j=x-k; j<= x+k; j++){
            if(j >= 0 && j < n)
             lit[j] = 1;
        }
    }

    int p1 = 0, res = 0;
    while(p1 < n){
        if(lit[p1]){
            p1++;
            continue;
        }

        int p2 = p1;
        while(p2 < n && !lit[p2])
            p2++;
        
        res += nec(k, p2 - p1);
        p1 = p2;
    }

    cout << res << endl;
    
    return 0;
}