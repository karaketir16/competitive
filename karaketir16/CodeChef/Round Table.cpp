#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define all(x) x.begin(),x.end()
#define inf	1000000000000000LL
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
    vector<int> kns(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&kns[i]);
    }
    vector<int> kns0=kns,kns1=kns;
    if(n<3)
    {
        cout<<min(kns[0],kns[1]);
        
        return 0;
    }
    kns0[0]+=kns0[n-1];
    kns0[1]+=kns0[n-1];
    for(int i=2;i<n;i++)
    {
        kns0[i]+=min(kns0[i-1],kns0[i-2]);
    }
    kns1[1]+=kns1[0];
    kns1[2]+=kns1[0];
    for(int i=3;i<n;i++)
    {
        kns1[i]+=min(kns1[i-1],kns1[i-2]);
    }
    int r=min3(kns0[n-1]-kns[n-1],kns1[n-1],kns1[n-2]);
    cout<<r;
    return 0;
}
