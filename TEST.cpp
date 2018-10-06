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
#define pp pair<int,int>

typedef long long int ll;


struct Compare {
    constexpr bool operator()(pair<int, int> const & a,
                              pair<int, int> const & b) const noexcept
    { return a.first > b.first || (a.first == b.first && a.second > b.second); }
};

int main()
{
    priority_queue<pair<int,int>,
                   std::vector<pair<int,int> >,
                   Compare> Q;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        Q.push(make_pair(a,b));
    }

    for(ll i=0;i<n;i++)
    {
        pair<ll,ll> m;
        m=Q.top();
        cout<<m.first<<" "<<m.second<<"\n";
        Q.pop();
    }
}