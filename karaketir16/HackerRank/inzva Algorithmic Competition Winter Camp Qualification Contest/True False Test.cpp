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
//#define MOD 1000000007
#define orta ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
using namespace std;
typedef long long int lint;
lint MOD = 1000000007;
lint poww(lint x, lint y)
{
    if(y==0) return 1;
    lint mid = poww(x, y/2)%MOD;
    if(1&y) return (mid*mid*x)%MOD;
    else return (mid*mid)%MOD;
    return 0;
}
lint calc(lint a, lint t)
{
    return ((2*(t+1-a)*poww(2, t-a))%MOD);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<lint> v(n+1);
    v[n]=2;
    lint x = calc(5,n);
    lint y = 0 ;
    for(int i = n-1;i >=5;i--)
    {
        v[i] = (calc(i, n) - v[i+1])%MOD;
        v[i] = v[i] < 0 ? v[i] + MOD : v[i];
    }

    cout<<v[5]<<endl;
    cout<<calc(2, 5);

    return 0;
}