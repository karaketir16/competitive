#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 200010
using namespace std;

typedef long long int lint;

int a[N];
int n;

lint sad(lint b){
    lint res = 0;
    for(int i=0; i<n; i++){
        res += abs(a[i] - b - i - 1);
    }
    return res;
}

lint ternary(lint left=-1e9, lint right=1e9, double eps=1e-7){
    while(right - left > eps){
        lint mid1 = left + (right - left) / 3;
        lint mid2 = right - (right - left) / 3;
        
        if(sad(mid1) > sad(mid2))
            left = mid1;
        else
            right = mid2;

        if(right - left == 2){
            int min_i = 0;
            for(int i=0; i<3; i++){
                if(sad(left + i) < sad(left + min_i))
                    min_i = i;
            }
            return sad(left + min_i);
        }
    }
    return sad(left);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    cout << ternary() << endl;
    return 0;
}
