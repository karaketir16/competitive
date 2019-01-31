#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
int main()
{
    std::ios::sync_with_stdio(false);
    vector<lint> v(N);
    int n;
    cin>>n;
    while(n--){
        int a, o , e;
        cin>>a>>o>>e;
        v[a]+=e;
        v[o]-=e;
        /* code */
    }
    lint maxx = 0;
    lint now = 0;
    FORE(v)
    {
        now += a;
        maxx = max(maxx, now);
    }
    cout<<maxx;
    return 0;
}