#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    INT_MAX
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef int lint;
struct Cell
{
    lint yon=-1;
    lint mal = inf;
    bool visited = false;
};
struct Compare {
    constexpr bool operator()(pair<lint, pair<lint, pair<lint, lint>>> const & a, pair<lint, pair<lint, pair<lint, lint>>> const & b) const noexcept { return a.first>b.first; }
};

template <class T> class priority_queue_less: public priority_queue<T, vector<T>, Compare>{};

int n, m;

bool test(lint i, lint j)
{
    if(i<0||i>=n||j<0||j>=m) return false;
    return true;   
}
int main() {

    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    
    vector<vector<Cell>> mat(N, vector<Cell> (N));
    
    lint si=0, sj=0, ei, ej;
    
    for(int i = 0; i< n; i++)
    {
        for(int j =0; j<m; j++)
        {
            int c;

            cin>>c;
            if(c==1) mat[i][j].visited = true;
            if(c==2) ei = i, ej=j;
        }
    }

    priority_queue_less<pair<lint, pair<lint, pair<lint, lint>>>> p;

    p.push({0,{0, {0,0}}});
    while(!p.empty())
    {
        auto top = p.top();
        p.pop();

        lint mal = top.first, yon = top.second.first, i = top.second.second.first, j = top.second.second.second;

        mat[i][j].visited = true;
        mat[i][j].mal = min(mal, mat[i][j].mal);

        if(yon == 0) //soldan
        {
            if(test(i, j+1)&&!mat[i][j+1].visited) p.push({mal,{0, {i,j+1}}}); //sag
            if(test(i+1, j)&&!mat[i+1][j].visited) p.push({mal+1,{3, {i+1,j}}}); //yukari
            if(test(i-1, j)&&!mat[i-1][j].visited) p.push({mal+1,{2, {i-1,j}}}); //asagi
        }
        if(yon == 1) //sagdan
        {
            if(test(i, j-1)&&!mat[i][j-1].visited) p.push({mal,{1, {i,j-1}}}); //sol
            if(test(i+1, j)&&!mat[i+1][j].visited) p.push({mal+1,{3, {i+1,j}}}); //yukari
            if(test(i-1, j)&&!mat[i-1][j].visited) p.push({mal+1,{2, {i-1,j}}}); //asagi
        }
        if(yon == 2) //yukaridan
        {
            if(test(i-1, j)&&!mat[i-1][j].visited) p.push({mal,{2, {i-1,j}}}); //asagi
            if(test(i, j+1)&&!mat[i][j+1].visited) p.push({mal+1,{0, {i,j+1}}}); //sag 
            if(test(i, j-1)&&!mat[i][j-1].visited) p.push({mal+1,{1, {i,j-1}}}); //sol
        }
        if(yon == 3) //asagidan
        {
            if(test(i+1, j)&&!mat[i+1][j].visited) p.push({mal,{3, {i+1,j}}}); //yukari
            if(test(i, j+1)&&!mat[i][j+1].visited) p.push({mal+1,{0, {i,j+1}}}); //sag 
            if(test(i, j-1)&&!mat[i][j-1].visited) p.push({mal+1,{1, {i,j-1}}}); //sol
        }
    }

    cout << (mat[ei][ej].mal == inf ? -1 : mat[ei][ej].mal);
 
    return 0;
}
