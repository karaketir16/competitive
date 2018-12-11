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
typedef pair<int,int> ii;
struct Node
{
    lint value=inf;
    vector<pair<int,int>> can_go;//node, weight

};


int main()
{
    
    int n,m;
    cin>>n>>m;
    vector<Node> nodess(n+1);
    for(int i=0;i<m;i++)
    {
        int f;
        int s;
        int d;

        cin>>f;
        cin>>s;
        cin>>d;
        nodess[f].can_go.pb(MP(s,d));

    }
    vector<lint> row(n+1,inf);
    vector<vector<lint>> matrix(n+1,row);
    for(int i=1;i<n+1;i++)
    {
        matrix[i][i]=0;
        for(auto a: nodess[i].can_go)
        {
            matrix[i][a.fi]=a.sc;
        }
    }
    for(int k=1; k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

    int o;
    cin>>o;
    for(int i=0;i<o;i++)
    {
        int f;
        int s;
        cin>>f>>s;
        lint result=matrix[f][s];
        if(result==inf) cout<<-1<<"\n";
        else cout<<result<<"\n";
    }

    return 0;
}
