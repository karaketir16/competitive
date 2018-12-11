#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 50005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;
typedef long long int lint;

int main()
{
    vector<int> arr1(N, 0);
    vector<int> arr2(N, 1);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr1[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr1[j]<arr1[i])
            {
                arr2[i]=(arr2[j]+1)>arr2[i] ? arr2[j]+1 : arr2[i];
            }
        }
    }
    int maxx=0;
    for(auto x : arr2) maxx=max(maxx, x);
    cout<<maxx;
    return 0;
}