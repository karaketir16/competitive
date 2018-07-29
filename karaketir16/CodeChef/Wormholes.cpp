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

    int n,x,y;
    cin>>n>>x>>y;
    vector<pair<int,int>> contests;
    while(n--)
    {
        int a;
        int b;
        scanf("%d %d",&a,&b);
        contests.pb(MP(a,b));
    }
    vector<int> V;
    vector<int> V_negative;
    while(x--)
    {
        int a;
        scanf("%d",&a);
        V.pb(a);
        V_negative.pb(-1*a);
    }
    vector<int> W;
    vector<int> W_negative;
    while(y--)
    {
        int a;
        scanf("%d",&a);
        W.pb(a);
        W_negative.pb(-1*a);
    }
    sort(V.begin(),V.end());
    sort(W.begin(),W.end());
    sort(V_negative.begin(),V_negative.end());
    sort(W_negative.begin(),W_negative.end());
    int minn=10000000;
    
    for(auto c:contests)
    {
        int first=c.fi;
        int last=c.sc;
        auto a = lower_bound(V_negative.begin(),V_negative.end(),-1*first);
        if(a==V_negative.end()) continue;
        auto b=lower_bound(W.begin(),W.end(),last);
        if(b==W.end()) continue;
        int f,l;
        f=(*a)*-1;
        l=(*b);
        int r=l-f+1;
        minn=min(minn,r);
    }
    
    cout<<minn;
    return 0;
}
