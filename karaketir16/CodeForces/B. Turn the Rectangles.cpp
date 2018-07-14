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
using namespace std;
typedef long long int lint;
int main()
{
    int n;
    cin>>n;
    lint son=inf;
    lint x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(x>y) swap(x,y);

        if(y<=son) son=y;
        else if(x<=son) son=x;
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}