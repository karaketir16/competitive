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
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
using namespace std;
typedef long long int lint;
int wanted;
bool dfs(vector<int> &v, int i, int total)
{
    if(i==v.size()) return false;
    if(total>wanted) return false;
    if(total+v[i]==wanted) return true;
    return dfs(v,i+1,total+v[i])||dfs(v,i+1,total);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    wanted=m;
    vector<int> v(n);
    INPUT(v);
    cout<< (dfs(v,0,0) ? "YES" : "NO");
    return 0;
}