#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lint;
int main() {
    int n,k;
    cin>>n>>k;
    int min_ind=0;
    int min_tot=0;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d", &x);
        arr.push_back(x);
    }
    for(int i = 0; i<k ;i++)
    {
        int x=arr[i];
        min_tot+=x;
    }
    int tot=min_tot;
    for(int i=k;i<n;i++)
    {
        int x=arr[i];
        tot+=x;
        tot-=arr[i-k];
        if(tot<min_tot)
        {
            min_tot=tot;
            //cout<<tot<<endl;
            min_ind=i-k+1;
        }
    }
    cout<<min_ind+1;
    return 0;
}
