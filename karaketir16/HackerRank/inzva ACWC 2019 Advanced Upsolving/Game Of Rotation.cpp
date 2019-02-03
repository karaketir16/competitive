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
int main()
{
    std::ios::sync_with_stdio(false);
    lint n;
    cin>>n;
    vector<lint> v(n);
    INPUT(v);
    lint tot = 0;
    FORE(v) tot+=a;

    lint res = 0;
    FOR0(n) res+=(v[i]*(i+1));

    lint maxx = res;

    FORE(v)
    {
        res-=tot;
        res+=(a*n);
        maxx= max(maxx, res);
    }
    printf("%lld", maxx);

    return 0;
}