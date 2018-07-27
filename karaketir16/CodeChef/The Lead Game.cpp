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

int main()
{
    int n;
    cin>>n;
    int maxx=0;
    int winner=1;
    int f=0;
    int s=0;
    while(n--)
    {
        int x;
        int y;
        cin>>x;
        cin>>y;
        f+=x;
        s+=y;
        if(abs(f-s)>maxx)
        {
            maxx=abs(f-s);
            if(f>=s) winner =1;
            else winner = 2; 
        }
    }
    printf("%d %d",winner,maxx);
    return 0;
}