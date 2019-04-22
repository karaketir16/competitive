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
#define orta ((a+b)/2)
using namespace std;
typedef long long int lint;



int main() {
    vector<pair<int,int>> ranges;
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        int x;
        int y;
        cin>>x>>y;
        ranges.pb(MP(y,x));
    }
    sort(ranges.begin(),ranges.end());
    //reverse(ranges.begin(),ranges.end());
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        pair <int, int> p;
        p.first = x;
        p.second = 0;
        auto it = upper_bound(ranges.begin(),ranges.end(),p);
        int re=it-ranges.begin();
        
        if(it==ranges.end()) 
        {
            cout<<"No\n";
            continue;
        }
        
        //cout<<re<<endl;
        if(ranges[re].sc<x) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}
