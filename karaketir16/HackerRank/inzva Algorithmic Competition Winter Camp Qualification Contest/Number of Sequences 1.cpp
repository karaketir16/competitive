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
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long int lint;
int main()
{
    std::ios::sync_with_stdio(false);
    lint n,w;
    cin>>n>>w;
    vector<lint> v(n);
    for(auto &x:v) cin>>x;
    
    int bas= 0 ;
    int son = 0 ;
    lint tot=0;
    lint result = 0 ;
    for(auto &x:v)
    {
        tot+=x;
        son++;
        while(tot>w) tot-=v[bas++];
        if(tot==w) result++;
    }
    cout<<result;
    return 0;
}