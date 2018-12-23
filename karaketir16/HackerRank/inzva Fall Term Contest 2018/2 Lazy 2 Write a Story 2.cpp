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

struct Cell
{
    int value;
    bool opened = false;
};

int main()
{
    int n;
    int result = 0;
    cin>>n;
    vector<vector<Cell>> mat(n, vector<Cell> (n));

    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            scanf("%d", &mat[i][j].value);
        }
    }
    int x,y;
    scanf("%d %d", &x, &y);
    stack<int> xx;
    stack<int> yy;
    xx.push(x);yy.push(y);
    while(!xx.empty())
    {
        x=xx.top();xx.pop();
        y=yy.top();yy.pop();
        if(x>=0&&x<n&&y>=0&&y<n) 
        {
            if(mat[x][y].opened) continue;
            if(mat[x][y].value==1)
            {
                mat[x][y].opened=1;
                result++;
                xx.push(x+1);yy.push(y);
                xx.push(x-1);yy.push(y);
                xx.push(x);yy.push(y+1);
                xx.push(x);yy.push(y-1);
            }
        }
    }
    cout<<result;
    return 0;
}