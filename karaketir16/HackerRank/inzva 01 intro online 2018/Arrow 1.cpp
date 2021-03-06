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
#define pp pair<int,int>

typedef long long int lint;

int main()
{
    int arrows[1000002];
    for(int i=0;i<1000002;i++) arrows[i]=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        if(arrows[x]>0)
        {
            arrows[x-1]++;
            arrows[x]--;
        }
        else
        {
            arrows[x-1]++;
        }
    }
    int total=0;
    for(int i=0;i<1000002;i++)
    {
        total+=arrows[i];
    }
    cout<<total;
    return 0;
}