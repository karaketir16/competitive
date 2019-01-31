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
#define mid(a, b) ((a+b)/2)
#define midy(a, b) ((a+b)/2 + (a%b!=0))
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
vector<lint> v;
lint n, p, q;
lint f(lint c)
{
    lint dst = inf;

    FORE(v)
    {
        dst = min(dst, abs(a - c));
    }
    return dst;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    v = vector<lint> (n);

    INPUT(v);

    cin >> p >> q;

    lint pdenkucenb = -1*inf;
    lint qdanbenk  = inf;
    
    auto ne = vector<lint>();



    sort(ALL(v));

    lint maxx = -1*inf;
    lint maxxi;
    for(lint i = 0; i < v.size() - 1; i++)
    {
        lint a =  (v[i+1] - v[i])/2;
        if(a > maxx      &&      ((mid(v[i], v[i+1]) >=p && mid(v[i], v[i+1]) <= q) ))
        {
            cerr<<"aeouid";
            maxx = a;
            maxxi = (v[i+1] + v[i])/2;
        }
    }
    
    lint minn = inf;
    FORE(v)
    {
        minn = min(minn, abs(a - q));
    }
    if(minn > maxx)
    {
        maxx = minn;
        maxxi = q;
    }
    minn = inf;
    FORE(v)
    {
        minn = min(minn, abs(a - p));
    }
    dbg(minn);
    if(minn >= maxx)
    {
        maxx = minn;
        maxxi = p;
    }



    dbg(maxx);
    dbg(maxxi);
    
    cout<<maxxi;
    
    return 0;
}