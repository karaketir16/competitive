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
int main()
{
    std::ios::sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    vector<lint> A;
    A.push_back(0);

    for(int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        A.push_back(x);
    }
    
    vector<lint> pre(n+1);
    vector<lint> zeroPre(n+1);
    lint old = 0;
    lint zeroOld = 0;
    for(int i = 0; i <= n; i++)
    {
        pre[i] = old ^ A[i];
        old = pre[i];
        if (old == 0) {
            zeroOld++;
        }
        zeroPre[i] = zeroOld;
    }

    while(q--){
        int x, y, k;
        cin>>x>>y>>k;
        x++;
        y++;
        lint tot = y - x + 2;
        lint zero = zeroPre[y] - (x > 1 ? zeroPre[x-2]:0);
        lint one = tot - zero;
        lint res =   ((k == 0) ? (one * zero) : (tot/2)*(tot&1 ? (tot/2+1) : (tot/2)));
        cout << res<<"\n";
    }
    
    


    return 0;
}