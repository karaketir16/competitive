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
    int n1, n2, n3;
    cin>>n1>>n2>>n3;
    vector<int> v1(n1+1), v2(n2+1), v3(n3+1);

    lint tot =0;
    for(int i = 0; i<n1; i++)
    {
        lint x;
        cin>>x;
        tot += x;
        v1[i] = x;
    }
    tot =0;
    for(int i = 0; i<n2; i++)
    {
        lint x;
        cin>>x;
        v2[i] = x;
    }
    tot =0;
    for(int i = 0; i<n3; i++)
    {
        lint x;
        cin>>x;
        tot += x;
        v3[i] = x;
    }
    reverse(ALL(v1));
    reverse(ALL(v2));
    reverse(ALL(v3));
    for(int i = 1; i<=n1; i++)
    {
        v1[i] += v1[i-1];
    }
    tot =0;
    for(int i = 1; i<=n2; i++)
    {
        v2[i] += v2[i-1];
    }
    tot =0;
    for(int i = 1; i<=n3; i++)
    {
        v3[i] += v3[i-1];
    }
    int a = n1, b = n2, c = n3;
    while(!(v1[a]==v2[b]&&v1[a]==v3[c]))
    {
        // dbg(v1[a]);
        // dbg(v2[b]);
        // dbg(v3[c]);
        if(v1[a]>=v2[b]&&v1[a]>=v3[c])
        {
            a--;
        }
        else if(v2[b]>=v3[c])
        {
            b--;
        }
        else c--;
    }
    cout<<v1[a];
    
    return 0;
}
