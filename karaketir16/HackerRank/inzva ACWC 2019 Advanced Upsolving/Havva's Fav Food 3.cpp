#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf 1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1005
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
lint calcdst(lint i, lint j, lint a, lint b)
{
    return ((i -a)*(i-a)+(j-b)*(j-b));
}
/* lint calcdst(lint i, lint j, lint a, lint b)
{
    return ((abs(i - a)+abs(j-b))*(abs(i -a)+abs(j-b)));
} */
pair<lint, lint> move(pair<lint, lint> a, char c)
{
    lint i= a.first, j = a.second;
    switch (c)
    {
        case 'E':
            i++;
            break;
        
        case 'W':
            i--;
            break;
        
        case 'N':
            j++;
            break;
        
        case 'S':
            j--;
            break;
    
        default:
            break;
    }
    return {i, j};
}
struct Cell
{
    int i, j, a, b;
    lint dist = inf;
    Cell()
    {

    }
    Cell(int i, int j, int a, int b, lint dist)
    {
        this->i=i;
        this->j=j;
        this->a=a;
        this->b=b;
        this->dist=dist;
    }
};


int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    int ni, nj, mi, mj;
    cin>>ni>>nj>>mi>>mj;
    vector<vector<Cell>> v(n+1, vector<Cell>(m+1));
    string sn, sm;
    cin>>sn>>sm;

    sn = "$" + sn;
    sm = "$" + sm;

  /*   dbg(sn);
    dbg(sm); */
    v[0][0] = Cell(ni, nj, mi, mj, 0);
    for(int j =1; j <=m; j++)
    {
        v[0][j] = v[0][j-1];
        auto mm = move({v[0][j].a, v[0][j].b}, sm[j]);
        v[0][j].a = mm.first;
        v[0][j].b = mm.second;
    } 
    for(int i =1; i <=n; i++)
    {
        for(int j =0; j <=m; j++)
        {
            v[i][j] = v[i-1][j];
            auto nn = move({v[i][j].i, v[i][j].j}, sn[i]);
            v[i][j].i = nn.first;
            v[i][j].j = nn.second;
        }
    }

    for(int i =0; i <=n; i++)
    {
        for(int j =0; j <=m; j++)
        {
            v[i][j].dist = calcdst(v[i][j].i, v[i][j].j, v[i][j].a, v[i][j].b);
        }
    }
/* 
    for(int i =0; i <=n; i++)
    {
        for(int j =0; j <=m; j++)
        {
            
            cerr<<v[i][j].dist<<"        ";
        }
        cerr<<"\n";
    }
    cerr<<"\n";
    cerr<<"\n";
 */
    for(int j =1; j <=m; j++)
    {
        v[0][j].dist += v[0][j-1].dist;
    } 

    for(int i =1; i <=n; i++)
    {
        v[i][0].dist += v[i-1][0].dist;
    }


    for(int i =1; i <=n; i++)
    {
        for(int j =1; j <=m; j++)
        {
            v[i][j].dist += min3(v[i-1][j].dist, v[i][j-1].dist, v[i-1][j-1].dist);
            //cerr<<v[i][j].dist<<"        ";
        }
        //cerr<<"\n";
    }
 
/*     dbg(v[n][m].i);
    dbg(v[n][m].j);
    dbg(v[n][m].a);
    dbg(v[n][m].b);
    cerr<<"\n";
    cerr<<"\n"; */
/*     for(int i =0; i <=n; i++)
    {
        for(int j =0; j <=m; j++)
        {
            
            cerr<<v[i][j].dist<<"        ";
        }
        cerr<<"\n";
    }
    cerr<<"\n";
    cerr<<"\n"; */


    cout<<v[n][m].dist-v[0][0].dist;
    return 0;
}


