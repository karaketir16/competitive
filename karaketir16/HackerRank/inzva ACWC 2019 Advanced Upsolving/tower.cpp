#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 500005
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long ll;
int n;
vector < pair <ll,ll> > vx;
vector < pair <ll,ll> > vy;

ll dx[N];
ll dy[N];

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) cin >> dx[i];
    for(int i = 0; i < n; i++) cin >> dy[i]; 

    for(int i = 0; i < n; i++)
    {
        vx.pb({dx[i],dy[i]});
        vy.pb({dy[i],dx[i]});
    }
    
    sort(ALL(vx));
    sort(ALL(vy));  

    for(int i = 0; i < vx.size(); i++)
    {
        dbg(vx[i].first);
    }
    

    return 0;


    ll t=0;
    ll ct=0;
 
    while(t < n)
    {
        ll tmp=t;
        while(tmp < n && vx[tmp].first == vx[tmp+1].first) tmp++;

        if(tmp == n) tmp--;
        
        ct += abs(vx[tmp].second - vx[t].second) - (tmp - t);
        t = tmp+1;
    }

    t=0;
    while(t < n)
    {
        ll tmp=t;
        while(tmp < n && vy[tmp].first == vy[tmp+1].first) tmp++;

        if(tmp == n) tmp--;
        ct += abs(vy[tmp].second - vy[t].second) - (tmp - t);
        t = tmp+1;
    }

    cout << ct << endl;
}