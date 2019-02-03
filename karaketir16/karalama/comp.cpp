#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf 1000000000000000LL
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
vector<int> uf(N);
vector<lint> sizes(N);
int parent(int x)
{
    if(x!=uf[x]) uf[x] = parent(uf[x]);
    return uf[x];
}
bool find(int n1, int n2)
{
    return parent(n1)==parent(n2);
}
void connect(int n1, int n2) //get parents
{
    //uf[uf[n1]] = uf[n2];

    uf[n2] = n1;
    sizes[n1] += sizes[n2];
}
lint size(int n)
{
    return sizes[parent(n)];
}
int main()
{
    std::ios::sync_with_stdio(false);


    FOR0(N) uf[i] = i;
    FOR0(N) sizes[i] = 1;

    return 0;
}
