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
typedef long long int lint;

bool arr[2005];

void fonk()
{
    for(int i=0;i<2005;i++) arr[i]=false;
    arr[0]=true;
    int n, k;
    scanf("%d %d", &n, &k);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        for(int i=0;i<2005;i++)
        {
            if(arr[i])
            {   
                if(i+x>2001) break;
                arr[i+x]=true;
            }
        }
    }
    while(k>-1)
    {
        if(arr[k])
        {
            printf("%d\n", k);
            break;
        }
        k--;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--) fonk();
    return 0;
}