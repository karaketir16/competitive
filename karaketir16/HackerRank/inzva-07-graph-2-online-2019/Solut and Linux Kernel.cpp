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
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
map<int, int> mapp;
struct File
{
    lint comp = 0;
    lint result = -1;
    vector<int> adj;
};
vector<File> files(N);


lint fonk(lint x)
{
    if(files[x].result!=-1) return files[x].result;

    lint maxx = 0;

    FORE(files[x].adj)
    {
        maxx = max(maxx, fonk(mapp[a]));
    }
    files[x].result = files[x].comp + maxx;
    return files[x].result;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n, tar;
    cin>>n>>tar;


    FOR0(n) cin>>files[i].comp;

    FOR0(n)
    {
        int a,b;
        cin>>a>>b;
        mapp[b] = i;
        files[i].adj = vector<int> (a);
        INPUT(files[i].adj);   
    }
    cout<<fonk(mapp[tar]);
    return 0;
}