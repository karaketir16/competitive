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
using namespace std;

struct Node
{
    int value=0;
    bool is_visited=0;
};
vector<vector<int>> map;
vector<vector<int>> visited;
queue<pair<int,int>> qu;
int hedefx;
int hedefy;
int maxx;
int maxy;
void move(int numb)
{
    pair<int,int> current;
    current=qu.top();
    qu.pop();
    if(map[current.fi][current.sc]==2)
    {
        cout<<numb;
        exit(0);
    }
    if(map[current.fc][current.sc]) return;
    if(current.fi<1||current.fi>maxx||current.fi<1||current.sc>maxy)
    {
        return;
    }
    map[current.fi][current.sc]
    qu.push(MP(current.fi-1,current.sc));
    qu.push(MP(current.fi+1,current.sc));
    qu.push(MP(current.fi,current.sc+1));
    qu.push(MP(current.fi,current.sc-1));




}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> c(m+1,0)
    vector<vector<int>> matrix(n+1,c)
    map=matrix;
    visited=matrix;
    maxx=m;
    maxy=n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j].value;
        }
    }
    qu.push(MP(1,1));
    visited[1][1]=1;
    move(1);

}