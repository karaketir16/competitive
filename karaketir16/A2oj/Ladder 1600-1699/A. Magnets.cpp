#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int last;
    cin>>last;
    n--;
    int res =0;

    for(int i =0; i<n; i++)
    {
        int a;
        cin>>a;
        if(a!=last) res++;
        last = a;
    }
    cout<<res+1;
    return 0;
}