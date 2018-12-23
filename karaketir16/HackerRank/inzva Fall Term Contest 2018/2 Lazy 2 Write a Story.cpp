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
#define MOD 1000000009   //10^9 + 9
#define orta ((a+b)/2)
using namespace std;


typedef long long int lint;


lint fastExp(lint x, lint y)
{
    if(y==0)  return 1;
    if(y==1) return x;
    lint a = y/2;
    lint res= fastExp(x, a);
    if(y&1) return (res*res*x)%MOD;
    else return (res*res)%MOD;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d", &n);
        vector<lint> arr(n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld", &arr[i]);
        }
        for(auto &a : arr)
        {
            a=(fastExp(3,fastExp(2,a)))%MOD;
        }
        sort(arr.begin(),arr.end());
        for(auto a : arr)
        {
            printf("%lld ", a);
        }
        if(t>0) printf("\n--\n");
    }
    return 0;
}