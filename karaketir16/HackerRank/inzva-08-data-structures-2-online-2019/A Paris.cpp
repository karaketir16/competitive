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
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);

    int n; 
    cin>>n;
    std::vector<lint> v(n);
    INPUT(v);


    reverse(ALL(v));

    std::vector<lint> minn;
    std::vector<double> tot;
    std::vector<double> av;
    minn.push_back(v[0]);
    tot.push_back(v[0]);
    av.push_back(0);
    for (int i = 1; i < n; ++i)
    {
        minn.push_back(min(minn[i-1], v[i]));
        tot.push_back(tot[i-1] + v[i]);
        av.push_back((tot[i]-minn[i])/i);
    }
    double maxav= -1;
    std::vector<int> res;
    for (int i = 1; i < n - 1; ++i)
    {
    	maxav = max(maxav, av[i]);
    }
    for (int i = 1; i < n - 1; ++i)
    {
        if (av[i] == maxav)
        {
            res.push_back(n - (i+1));    
        }
    }
    // for (int i : {195, 196, 197, 201, 202})
    // {
    // 	dbg(av[n - i - 1]);
    // }
    sort(ALL(res));

    FORE(res) cout<<a<<"\n";
    return 0;
}