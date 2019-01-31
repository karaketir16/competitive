#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1000005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
vector<bool> prime(N, true);
int main()
{
    prime[0] = prime[1] = 0;

    for(int i = 2; i * i <= N; i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j <= N; j+=i)
            {
                prime[j] = false;
            }
        }
    }
    std::ios::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int tot = 0;
        while(k--)
        {
            int a;
            cin>>a;
            if(prime[a]) tot ++;
        }
        cout << tot;
        if(t != 0 ) cout<<"\n--\n";
    }
    return 0;
}