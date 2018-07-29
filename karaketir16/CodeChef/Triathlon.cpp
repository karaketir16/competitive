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
    int n;
    cin>>n;
    vector<pair<int,int>> citizens;
    while(n--)
    {
        int x;
        int y;
        int z;
        scanf("%d %d %d",&x,&y,&z);
        y+=z;
        citizens.pb(MP(y,x));
    }
    sort(citizens.begin(),citizens.end());
    reverse(citizens.begin(),citizens.end());
    int maxx=0;
    int tm=0;
    for(auto c:citizens)
    {
        tm+=c.sc;
        maxx=max(maxx,tm+c.fi);
    }
    cout<<maxx;

    return 0;
}
