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
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;

char d[105][105];
int dir[4][2] = {{1,0} , {0,1} , {-1,0} , {0,-1}};
int n;
int mark[105][105];
int ct , ans;

void dfs(int x,int y,char c)
{
    dbg(x);
    dbg(y);
    mark[x][y] = 1;

    for(int i = 0; i < 4; i++)
    {
        if( x+dir[i][0] >= 0 && x+dir[i][0] < n && y+dir[i][1] >= 0 && y+dir[i][1] < n
            && !mark[ x+dir[i][0] ][ y+dir[i][1] ]
            && d[ x+dir[i][0] ][ y+dir[i][1] ] == d[x][y])
            dfs(x+dir[i][0] , y+dir[i][1] , c);
    }
    
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> d[i][j];
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            if(!mark[i][j])
            {
                dfs(i,j,d[i][j]);
                ct++;
            }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(d[i][j] == 'G')
                d[i][j] = 'R';

    memset(mark,0,sizeof mark); 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            if(!mark[i][j])
            {
                dfs(i,j,d[i][j]);
                ans++;
            }
    }

    cout << ct << " " << ans << endl;
}
// by salihfc