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
typedef long long int lint;


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<lint> hus(n+1);
        hus.pb(0);
        for(int i=1;i<=n;i++)
        {
            
            scanf("%lld",&hus[i]);
            
        }
        for(int i=3;i<=n;i++)
        {
            hus[i]+=max(hus[i-2],hus[i-3]);
        }
        if(n==0)
        {
            cout<<0<<'\n';
        }
        else if(n==1)
        {
            cout<<hus[1]<<'\n';
        }
        else
        {
            cout<<max(hus[n],hus[n-1])<<'\n';
        }
    }
    return 0;
}

