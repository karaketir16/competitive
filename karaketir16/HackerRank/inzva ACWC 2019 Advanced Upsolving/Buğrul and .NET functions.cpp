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
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;

lint gcd_calc(lint f, lint s)
{
    if(!s) return f;
    return gcd_calc(s, f%s);
}


int main()
{
    lint m, n, a, b;
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n>>a>>b;
        lint gcd = gcd_calc(a, b);
        // a/=gcd;
        // b/=gcd;

        if((m > 0 && a == 0)||(m != n && a==b)) cout<<-1<<"\n";
        else
        {
            n-=m;
            b-=a;
            lint um = a >= m ? 1 : (m/a + (m%a!=0));
            lint dm = b >= n ? 1 : (n/b + (n%b!=0));
            a*=max(um, dm);
            b*=max(um, dm);
            lint res = a - m + b - n;
            cout<<res<<"\n";
        }
    }
    return 0;
}