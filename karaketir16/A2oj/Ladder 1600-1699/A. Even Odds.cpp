#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin>>n>>k;
    long long up = n - n/2;
    if(k>up)
    {
        cout << (k-up)*2;
    }
    else cout << k*2-1;
    return 0;
}