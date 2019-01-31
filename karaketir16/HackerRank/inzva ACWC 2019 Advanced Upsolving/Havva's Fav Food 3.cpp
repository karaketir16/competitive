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
double calcdst(lint i, lint j, lint a, lint b)
{
    return sqrt((i -a)*(i-a)+(j-b)*(j-b));
}

pair<lint, lint> move(pair<lint, lint> a, char c)
{
    lint i= a.first, j = a.second;
    switch (c)
    {
        case 'N':
            i--;
            break;
        
        case 'S':
            i++;
            break;
        
        case 'E':
            j++;
            break;
        
        case 'W':
            j--;
            break;
    
        default:
            break;
    }
    return {i, j};
}
struct Cell
{
    int i, j, a, b, dist = inf;
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
    vector<vector<Cell>> v(n+1, vector<Cell>(n+1));
    string sn, sm;
    cin>>sn>>sm;

    sn = "$" + sn;
    sm = "$" + sm;


    v[0][0] = Cell(ni, nj, mi, mj, 0);



    return 0;
}