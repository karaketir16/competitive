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
    int n;
    cin>>n;
    vector<lint> v(n);
    for(auto &x:v) cin>>x;

    sort(ALL(v));

    int tot=0;
    for(auto x:v) if(x==v[n/2]) tot++;
    cout<<tot;
    return 0;
}