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
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
int n,c;
int d[N];

bool check(int k)
{
    int ct=1;
    int val = d[0];
    for(int i = 1; i < n; i++)  
    {
        if(d[i]-val >= k)
        {
            val = d[i];
            ct++;
        }
    }

    if(ct >= c)
        return 1;
    return 0;
    

}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> d[i];
    sort(d,d+n);

    int l = 1 , r = (d[n-1]-d[0]) / (c-1);    
    
    // for(int i = 0; i < 10; i++)
    // {
    //     dbg(i);
    //     dbg(check(i));
    // }
    


    while(r-l > 1)
    {
        // cout << "(l,r) : " << l << " " << r << endl;
        int mid = (l+r)/2;

        if(check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid-1;
        }
    }

    if(check(r))
        cout << r << endl;
    else if(check(l))
        cout << l << endl;
    else
        cout << "1\n";
    return 0;
}