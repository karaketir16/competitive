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
int n,h;
vector<int> piles(N);
bool possible(int x)
{
    int result=0;
    for(int i =0 ;i<n;i++)
    {
        if(piles[i]%x!=0) result++;
        result+=piles[i]/x;
    }
    if(result<=h) return true;
    return false;
}
int main()
{
    cin>>n>>h;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&piles[i]);
    }

    int i=1,j=1000000000;
    while(true)
    {
        int mid=(i+j)/2;
        bool check=possible(mid);
        if(i==j-1||i==j)
        {
            if(check)
            {
                cout<<i;
                return 0;
            }
            else
            {
                cout<<j;
                return 0;
            }
        }
        if(check)
        {
            j=mid;
        }
        else
        {
            i=mid;
        }
    }
    return 0;
}
