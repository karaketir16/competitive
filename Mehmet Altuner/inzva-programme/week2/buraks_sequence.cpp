#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int ar[n];
    int a[n];
    
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    
    for(int i=n-1; i>0; i--){
        a[i] = ar[i] * (i + 1) - ar[i - 1] * i;
        //cout << a[n] << " ";
    }
    
    a[0] = ar[0];
    
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    
    return 0;
}
