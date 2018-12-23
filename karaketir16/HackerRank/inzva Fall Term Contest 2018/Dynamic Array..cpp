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
#define orta ((a+b)/2)
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<vector<int>> s(n);
    int last=0;
    while(q--)
    {
        int a;
        scanf("%d", &a);
        a--;
        int x,y;
        scanf("%d %d", &x,&y);
        x=(x^last)%n;
        if(!a)
        {
            s[x].pb(y);
        }
        else
        {
            last=s[x][y%s[x].size()];
            printf("%d\n",last);
        }
    }
    return 0;
}