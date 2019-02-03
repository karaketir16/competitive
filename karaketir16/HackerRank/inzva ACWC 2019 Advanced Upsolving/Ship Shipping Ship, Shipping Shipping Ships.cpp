#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf 1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 5005
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;

int n,d[N],ct;
int mark[N];

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> d[i];
        d[i]--;
    }
    for(int i = 1; i < n; i++)
    {
        if(!mark[i])
        {
            ct++;
            for(int j = i+1; j < n; j++)
            {
                if((d[j] % d[i]) == 0)
                    mark[j] = 1;
            }   
        }
    }
    
    cout << ct << endl;
    
    return 0;
}
//by salihfc