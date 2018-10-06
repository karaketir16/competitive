#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n){
    if(n == 2 || n == 3)
        return true;
    
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    
    int i=5;
    int w=2;
    
    while(i*i <= n){
        if(n % i == 0){
            return false;
        }
        i += w;
        w = 6 - w;
    }
    
    return true;
}

int main() {
    int n, x;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;
        if(isPrime(x)){
            cout << "Prime" << endl;
        }else{
            cout << "Not Prime" << endl;
        }
    }
    return 0;
}
