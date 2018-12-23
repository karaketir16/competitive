#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i=n-1;i>-1;i--)
    {
        for(int j=n-1;j>-1;j--)
        {
            if(i==n-1&&j==n-1) continue;
            
            if(j==n-1)
            {
                arr[i][j]+=arr[i+1][j];
            }
            
            else if(i==n-1)
            {
                arr[i][j]+=arr[i][j+1];
            }
            else
            {
                arr[i][j]+=min(arr[i][j+1],arr[i+1][j]);
            }
            
        }
    }
    
    cout<<arr[0][0];
    return 0;
}