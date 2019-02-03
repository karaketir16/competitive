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

int main()
{
    //std::ios::sync_with_stdio(false);
    lint n,k;
    cin >> n >> k; 
    if((k < (n-1)) or (k > ((n*(n-1))/2)))
        cout << "-1\n";
    else
    {
        printf("%lld %lld\n",n,k);
        // for(int i = 1; i < n; i++)
        //     cout << i+1 << " " << i <<  "\n";

        // k -= (n-1);
        
        lint t = n;
        while(k)
        {
            for(lint i = t-1; k && (i > 0); i--)
            {
                printf("%lld %lld\n",t,i);
                k--;
            }
                           
            t--;
        }
        
        
    }
    return 0;
    
}
// by salihfc