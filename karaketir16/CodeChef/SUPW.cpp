#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define all(x) x.begin(),x.end()
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;
typedef long long int lint;
int main()
{
    int n;
    cin>>n;
    vector<lint> day(n+3,0);
    for(int i=0;i<n;i++)
    {

        scanf("%lld", &day[i]);

    }

    for(int i=3;i<n;i++)
    {
        day[i]+=min3(day[i-3],day[i-2],day[i-1]);
    }
    
    cout<<min3(day[n-3],day[n-2],day[n-1]);
    return 0;
}
