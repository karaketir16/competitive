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
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> pairs;
    vector<pair<int,int>> result;
    for(int i=0;i<n;i++)
    {
        int x;
        int y;
        scanf("%d %d",&x,&y);
        pairs.pb(MP(x,-1));
        pairs.pb(MP(y,1));
    }
    int total=0;
    int eski_total=0;
    int bas=0;
    int son=0;
    sort(pairs.begin(),pairs.end());
    for(int i=0;i<2*n;i++)
    {
        int x_temp=pairs[i].fi;
        int yon=pairs[i].sc;
        total+=-1*yon;
        //if(i<2*n-1&&pairs[i+1].fi==x_temp) continue;
        //cout<<x_temp<<" "<<yon<<" "<<eski_total<<" "<<total<<endl;
        if(eski_total<k&&total>=k)
        {
            bas=x_temp;
        }
        if(eski_total>=k&&total<k)
        {
            son=x_temp-1;
            result.pb(MP(bas,son));
        }
        eski_total=total;

    }
    cout<<result.size()<<'\n';
    for(auto x:result)
    {
        printf("%d %d\n", x.fi, x.sc+1);
    }

    return 0;
}