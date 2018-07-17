#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
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
    vector<int> a,b;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        auto t = upper_bound(a.begin(),a.end(),x);
        int result=t-a.begin();

        cout<<result<<" ";

        /*
        b.pb(x);
        */
    }


    return 0;
}