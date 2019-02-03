#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf 1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1005
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;

int n;
vector <pair <lint,lint>> vx,vy;
map <lint,lint> mpx,mpy;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        vx.pb({a,b});
        mpx[a]++;
        mpy[b]++;
    }
    
    // sort(ALL(vx));  

    lint a=0LL;
    for(int i = 0; i < n; i++)
    {
        a += max(0LL,mpx[vx[i].first]-1) * max(0LL,mpy[vx[i].second]-1);
    }
    printf("%lld\n",a);
    
    return 0;
}