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
#define FOR(x) for(int i = 0;i<x;i++)
using namespace std;
typedef long long int lint;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int halfhalf= n/4;
    string s;
    cin>>s;
    int ws=0, cs=0;
    vector<int> v;
    for(auto c:s)
    {
        if(c=='W')
        {
            ws++;
            if(ws>halfhalf) v.pb(2);
            else v.pb(1);
        }
        else
        {
            cs++;
            if(cs>halfhalf) v.pb(2);
            else v.pb(1);
        }
    }
    bool test = true;
    for(int i =0;i<n/2;i++)
    {
        if(v[i] == 2) test = false;
    }
    cout<<(test ? 1 : 2);
    return 0;
}