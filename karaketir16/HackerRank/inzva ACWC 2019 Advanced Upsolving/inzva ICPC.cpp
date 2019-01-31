#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1000005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
int n;
lint fonk(vector<vector<lint>> v)
{
    vector<vector<lint>> mem(4, vector<lint> (n+1, inf));

    mem[0][0] = 0;
    for(int i =1; i<=3; i++)
    {
        for(int j = i; j <= (n-(3-i)); j++)
        {
            mem[i][j] = min(mem[i][j-1], mem[i-1][j-1]) + v[i-1][j-1];
        }
    }
    //cout<<v[0][0]<<" "<<mem[1][1]<<endl;
    return mem[3][n];
}
int main()
{
    std::ios::sync_with_stdio(false);

    cin>>n;
    vector<vector<lint>> v(3, vector<lint> (n));

    FORE(v) INPUT(a);
    sort(ALL(v));
    lint m = inf;
    //cout << v[2][n-1]<<endl;
    do
    {
        //cout<<"test ";
        m = min(m, fonk(v));
    } while (next_permutation(ALL(v)));
    
    cout << m;
    return 0;
}