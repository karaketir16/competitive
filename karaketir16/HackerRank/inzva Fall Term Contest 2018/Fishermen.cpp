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

int main()
{
    int n,m,l;
    cin>>n>>m>>l;
    map<lint,lint> koords;
    priority_queue<pair<lint, lint>> fishers;//koord, ind
    vector<lint> results(m); 
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        if(y<=l)
        {
            koords[(x-(l-y))]++;
            koords[(x+(l-y)+1)]--;//end dahil degil
        }

    }

    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        fishers.push(MP(-1*x, i));
    }
    lint fish=0;

    lint koord=0;
    //cout<<"str size "<<starts.size()<<endl;
    for(auto p:koords)
    {

        lint k=p.fi;
        while((!fishers.empty())&&k>fishers.top().first*-1)
        {
            results[fishers.top().second]=fish;
            fishers.pop();
        }
        lint fsh=p.sc;
        fish+=fsh;
    }

    while((!fishers.empty()))
    {
        results[fishers.top().second]=fish;
        fishers.pop();
    }

    for(int i=0;i<m;i++)
    {
        printf("%lld\n", results[i]);

    }
    
    return 0;
}