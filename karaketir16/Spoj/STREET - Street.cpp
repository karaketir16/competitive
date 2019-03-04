#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 505
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
#define bit(number,i) ((number>>i)&1)
using namespace std;
typedef long long int lint;
vector<vector<lint>> dp(N, vector<lint> (N, -1));
vector<lint> v(N);
lint t;
lint f(lint i, lint k, lint a=1)
{
    if(dp[i][k] != -1) return dp[i][k];

    if(a <= t)
    {
        if(v[i] >= v[i-1])
        {
            dp[i][k] = max(f(i-1, k, a+1) + v[i-1], dp[i][k]);
        }
    }
    dp[i][k] = max(f(i-1, k-1, 1) + v[i], dp[i][k]);
    return dp[i][k];
}
int main()
{
    std::ios::sync_with_stdio(false);
    lint n, k;
    cin>>n>>k>>t;
    for(lint i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    for(lint i = 1; i < 500; i++)
    {
        dp[0][i] = v[0];
    }
    cout<<f(n-1, k);
    return 0;    
}
