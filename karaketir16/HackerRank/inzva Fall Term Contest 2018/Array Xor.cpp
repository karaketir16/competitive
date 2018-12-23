#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 500005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;



int main()
{
    int n,q;
    cin>>n;
    vector<int> arr(n+1);
    for(int i =1;i<=n;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=2;i<=n;i++)
    {
        arr[i]^=arr[i-1];
    }
    cin>>q;
    while(q--)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        printf("%d\n", arr[y]^arr[x-1]);
    }
    return 0;
}