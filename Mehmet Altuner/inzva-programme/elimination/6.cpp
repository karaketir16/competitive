#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long int lli;

struct number{
    lli data;
    lli min;
};

vector <vector <number>> ar;
lli n;

int main() {
    scanf("%lli", &n);
    
    ar.resize(n, vector <number>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            lli x;
            scanf("%lli", &x);
            ar[i][j] = number{x, 0};
        }
    }

    
    cout << " sa " << n << endl;

    for(int j=n-1; j>=0; j--){
        for(int i=n-1; i>=0; i--){
            if(i == n-1 && j == n-1){
                ar[i][j] = number{x, x};
                continue;
            }

            lli down_min = INT_MAX;
            if(j+1 < n)
                down_min = ar[j+1][i].min;

            lli right_min = INT_MAX;
            if(i+1 < n)
                right_min = ar[j][i+1].min;

            ar[i][j].min = min(down_min, right_min) + ar[i][j].data;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%lli,%lli ", ar[i][j].data, ar[i][j].min);
        }
        printf("\n");
    }

    printf("%lli", ar[0][0].min);

    return 0;
}
