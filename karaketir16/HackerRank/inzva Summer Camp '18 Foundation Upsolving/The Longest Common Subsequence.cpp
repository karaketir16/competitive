#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define all(x) x.begin(),x.end()
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

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> nn(n+1,0);
    vector<int> mm(m+1,0);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&nn[i]);
    }
    for(int i=1; i<=m;i++)
    {
        scanf("%d",&mm[i]);
    }
    vector<int> s(m+1,0);
    vector<vector<int>> mat(n+1,s);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(nn[i]==mm[j])
            {
                mat[i][j]=1+mat[i-1][j-1];
            }
            else
            {
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    vector<int> result;
    int i=n;
    int j=m;
    while(i>0&&j>0)
    {
        //cout<<"test";
        if(nn[i]==mm[j])
        {
            result.pb(nn[i]);
            i--;
            j--;
        }
        else
        {
            if(mat[i][j-1]>mat[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
        
    }
    
    reverse(all(result));
    for(auto x:result)
    {
        printf("%d ",x);
        
    }
    
    return 0;
    
}