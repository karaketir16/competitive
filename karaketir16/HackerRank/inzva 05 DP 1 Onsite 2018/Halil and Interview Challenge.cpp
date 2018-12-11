#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 100005
using namespace std;

int arr[N];
int main() {
    for(int i=0;i<N;i++)
    {
        arr[i]=0;
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d", &x);
        arr[x]++;
    }
    for(int i=0;i<N;i++)
    {
        arr[i]*=i;
    }
    for(int i=2;i<N;i++)
    {
        arr[i]=max(arr[i-1], arr[i-2]+arr[i]);
    }
    cout<<arr[N-1];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
