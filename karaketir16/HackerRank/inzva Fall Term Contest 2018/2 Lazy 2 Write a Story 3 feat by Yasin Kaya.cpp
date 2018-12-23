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

struct Ele
{
    int q;
    int x;
    int y;
};
vector<int> uni(N);
void bagla(int x, int y)
{
    while(uni[x]!=x)
    {
        int temp=x;
        x=uni[x];
        uni[temp]=uni[x];
    }
    while(uni[y]!=y)
    {
        int temp=y;
        y=uni[y];
        uni[temp]=uni[y];
    }
    uni[x]=y;
}
bool bagli_mi(int x, int y)
{
    while(uni[x]!=x)
    {
        x=uni[x];
    }
    while(uni[y]!=y)
    {
        y=uni[y];
    }
    return x==y;
}
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<int, int>> edges(m+1);
    vector<bool> will_cut(m+1, false);
    for(int i=1;i<=m;i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[i]=MP(x,y);
    }
    vector<Ele> ques;
    for(int i =0;i<q;i++)
    {
        Ele e;
        int x;
        scanf("%d",&x);
        e.q=x;
        if(x==1)
        {
            scanf("%d", &x);
            e.x=x;
            will_cut[x]=true;
        }
        else
        {
            int y;
            scanf("%d %d", &x,&y);
            e.x=x;
            e.y=y;
        }
        ques.pb(e);
    }
    for(int i =0 ;i<N;i++)
    {
        uni[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(!will_cut[i]) bagla(edges[i].first, edges[i].second);
    }
    vector<bool> results;
    reverse(ques.begin(), ques.end());
    for(auto e: ques)
    {
        /*
        for(int i = 0; i<11;i++)
        {
            cout << i<<' '<<uni[i]<<endl;
        }
        cout<<endl;
        */
        if(e.q==1)
        {
            bagla(edges[e.x].first, edges[e.x].second);
        }
        else
        {
            results.pb(bagli_mi(e.x,e.y));
        }
    }
    reverse(results.begin(), results.end());
    for(auto r:results)
    {
        if(r) printf("Connected\n");
        else printf("Not Connected\n");
    }
    return 0;
}