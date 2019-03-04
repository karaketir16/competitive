#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1901
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
std::vector<lint> maxx(N);
std::vector<vector<lint>> dp(N, vector<lint>(N));

int main()
{
    ios::sync_with_stdio(false);
    lint n, h, k;
    cin>>n>>h>>k;

    FOR1(n)
    {
        lint per = 0;
        cin>>per;
        for(int j = 0; j < per; j++)
        {
            lint a;
            cin>>a;
            dp[a][i] += 1;
            maxx[a] = max(dp[a][i], maxx[a]);
            //update(Sgt[a], 1, 1, N, 1, i);
        }
    }
    for(int i = 2; i < N; i++) // kat
    {
        for(int j = 1; j <= n ; j++)// bina
        {
            if(i-k > 0)
            {
                lint val = max(maxx[i-k], dp[i-1][j]);
                dp[i][j] += val;
                maxx[i] = max(dp[i][j], maxx[i]);
                //update(Sgt[i],1, 1, N, val, j);
            }
            else
            {
                lint val = dp[i-1][j];
                dp[i][j] += val;
                maxx[i] = max(dp[i][j], maxx[i]);
            }
        }
    }

    //build(tree, 1, 1, n);


    cout<<fixed<<maxx[N-1]<<"\n";
//     FOR1(15)
//     {
//         dbg(i);
//         dbg(maxx[i]);
        
//     }
    
    return 0;
}