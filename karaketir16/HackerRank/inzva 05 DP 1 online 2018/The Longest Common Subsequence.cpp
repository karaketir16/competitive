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

int arr[105][105];


int main()
{
    for(int i=0;i<105;i++) arr[0][i]=arr[i][0]=0;
    int n,k;
    cin>>n>>k;
    vector<int> nn(n+1),kk(k+1);
    for(int i=1;i<=n;i++) scanf("%d", &nn[i]);
    for(int i=1;i<=k;i++) scanf("%d", &kk[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++) 
        {
            if(nn[i]==kk[j]) arr[i][j]=arr[i-1][j-1]+1;
            else arr[i][j]=max(arr[i-1][j], arr[i][j-1]);
        }
    vector<int> result;
    int i=n,j=k;
    while(i>0&&j>0)
    {
        if(nn[i]==kk[j])
        {
            result.pb(nn[i]);
            i--;
            j--;
            continue;
        }
        if(arr[i-1][j]>arr[i][j-1])
        {
            i--;
            continue;
        }
        j--;
    }
    reverse(result.begin(), result.end());
    for(int a:result) printf("%d ",a);
    
    return 0;
}