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

#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;

lint n, s;
vector<vector<char>> mapp;

vector<vector<int>> bees;

//vector<vector<int>> mec;

vector<vector<bool>> visited;


vector<pair<lint, lint>> udlr(lint i, lint j) //i, j
{
    vector<pair<lint, lint>> tmp;
    int a, b;
    a=-1;
    b=0;
    if(((a+i>=0) && (a+i < n)) &&((b+j>=0) && (b+j < n))) tmp.push_back({a+i, b+j});
    a=1;
    b=0;
    if(((a+i>=0) && (a+i < n)) &&((b+j>=0) && (b+j < n))) tmp.push_back({a+i, b+j});
    a=0;
    b=-1;
    if(((a+i>=0) && (a+i < n)) &&((b+j>=0) && (b+j < n))) tmp.push_back({a+i, b+j});
    a=0;
    b=1;
    if(((a+i>=0) && (a+i < n)) &&((b+j>=0) && (b+j < n))) tmp.push_back({a+i, b+j});
    return tmp;
}



bool fonk(lint t)
{
    queue<pair<pair<int, int>, int>> q;//coordinate, depth
    visited = vector<vector<bool>> (n, vector<bool>(n, false));
    //mec = vector<vector<int>> (n, vector<int>(n, INT_MAX));
    int depth = 0;
    for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
        {
            if(mapp[i][j] == 'M' && (bees[i][j] > t + ((depth)/s + ((depth)%s != 0)))) q.push({{i, j}, 0}), visited[i][j] = true;
        }
    }
    while(!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        int i = tmp.first.first, j = tmp.first.second;
        depth = tmp.second;
        if(mapp[i][j] == 'D') return true;
        int now_t = t+(depth/s + (depth%s != 0));
        //mec[i][j] = now_t;
        int last_t = t+((depth-1)/s + ((depth-1)%s != 0));
        int next_t = t+((depth+1)/s + ((depth+1)%s != 0));
        auto ways = udlr(i, j);
        //dbg(ways.size());
        //if(t+(depth/s + (depth%s != 0))  >  )
        if((bees[i][j] == t + ((depth)/s + ((depth)%s != 0))) && next_t > now_t) continue;
        FORE(ways)
        {   

            int i = a.first, j =  a.second;
            //dbg(i), dbg(j) ;
            if((!visited[i][j]) && (mapp[i][j] == 'G'||mapp[i][j] == 'D')) 
            {
                if(bees[i][j] >= t + ((depth+1)/s + ((depth+1)%s != 0))) q.push({{i, j}, depth+1}), visited[i][j] = true;
                //if(bees[i][j] == t + ((depth+1)/s + ((depth+1)%s != 0))   &&  last_t==now_t) q.push({{i, j}, depth+1}), visited[i][j] = true;
            }

        }
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>s;
    mapp = vector<vector<char>> (n, vector<char>(n));

    FORE(mapp) INPUT(a);

    bees = vector<vector<int>> (n, vector<int>(n, INT_MAX));
    
    visited = vector<vector<bool>> (n, vector<bool>(n, false));

    queue<pair<pair<int, int>, int>> q;//coordinate, depth

    for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
        {
            if(mapp[i][j] == 'H') q.push({{i, j}, 0}), visited[i][j] = true;
        }
    }

    while(!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        int i = tmp.first.first, j = tmp.first.second, depth = tmp.second;

        bees[i][j] = depth;

        auto ways = udlr(i, j);

        FORE(ways)
        {   
            //dbg(i), dbg(j);
            int i = a.first, j =  a.second;
            if((!visited[i][j]) && (mapp[i][j] == 'G'|| mapp[i][j] == 'M')) q.push({{i, j}, depth+1}), visited[i][j] = true;
        }
    }

    //cerr<<1<<' '<<fonk(1)<<endl;

 
    lint left = -1, right = 1e8, mid, old_mid = 0;

    while (right - left > 0){
        mid = (left + right) / 2;
        if(mid == old_mid) break;
        old_mid = mid;
        //dbg(mid);
        //dbg(fonk(mid));
        if (fonk(mid))
            left = mid;
        else
            right = mid;
    }
    cout<<(fonk(right) ? right : left);
 
/*     //cerr<<2<<' '<<fonk(2)<<endl;
    cerr<<1<<' '<<fonk(1)<<endl;
    for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
        {
            cerr<<(bees[i][j] == INT_MAX ? 0 : bees[i][j]);
        }
        cerr<<endl;
    }
    cerr<<endl;
    for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
        {
            cerr<<(mec[i][j] == INT_MAX ? 0 : mec[i][j]);
        }
        cerr<<endl;
    } 
      */
    return 0;
}
/* 
5 1
MGGGD
GGGGG
GGGGG
GGGGG
GGGGH
 */