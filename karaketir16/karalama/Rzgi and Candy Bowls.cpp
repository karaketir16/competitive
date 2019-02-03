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
    lint n;
    cin>>n;
    vector<lint> v(n);
    INPUT(v);

    lint mini = 0;

    for(int i = 0; i < n; i++)
    {
        if(v[i]<v[mini]) mini = i;
    }
    // dbg(mini);
    lint res = 0;
    lint m = 0;
    for(int i = mini - 1; i > 0; i--)
    {
        if(v[mini]==v[i]) 
        {
            m++;
            continue;
        }
        res+=(v[mini]*v[i]*v[i-1]);
        // dbg(v[mini]);
        // dbg(v[i]);
        // dbg(v[i-1]);
    }

    for(int i = mini + 1; i < n-1; i++)
    {
        if(v[mini]==v[i]) 
        {
            m++;
            continue;
        }
        res+=(v[mini]*v[i]*v[i+1]);
        //cout<<"hello";
    }

/*     if(mini > 0 && mini < n-1)
    {
        res+= (v[0]*v[n-1]*v[mini]);
    } */

    lint minn = v[mini];
    res+=(((m-2)*minn*minn*minn)+(minn*minn*(v[0]+v[n-1]))+minn*v[0]*v[n-1]);
    
    cout << res;
    return 0;
}

