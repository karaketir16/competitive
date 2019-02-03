#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf 1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1000005
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;


int n,b;
int a[25];
int d[105];
vector <lint> k(N,inf);

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> b;

    for(int i = 0; i < b; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> d[i];
        
    for(int i = n-1; i > 0; i--)
        d[i] = d[i] - max(0,(d[i-1]-1));
    
    sort(a,a+b);
    
    k[0] = 0;
    for(int i = 0; i < b; i++)
    {
        for(int j = 0; j < (int)2e5; j++)
        {
            if((k[j] != inf) && (j+a[i] < (int)2e5))
                k[ j + a[i]] = min(  k[j] + 1  ,  k[ j + a[i]]);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(k[d[i]] == inf)
        {
            cout << "-1\n";
            return 0;
        }
        else
        {
            ans += k[d[i]];
        }
        
    }
    
    // for(int i = 0; i < 40; i++)
    // {
    //     cout << i << " : " << k[i] << endl;
    // }
    

    cout << ans << endl;
    
    
    return 0;
}
//by salihfc