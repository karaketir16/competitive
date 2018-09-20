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
struct Compare {
    constexpr bool operator()(pair<lint, lint> const & a,
                              pair<lint, lint> const & b) const noexcept
    { return a.first > b.first || (a.first == b.first && a.second > b.second); }
};

int main()
{
    priority_queue<pair<lint,lint>,
                   std::vector<pair<lint,lint> >,
                   Compare> Q;
    lint n,m;
    cin>>n>>m;
    lint arr[500002];
    for(int i=1;i<=n;i++)
    {
        lint x;
        cin>>x;
        arr[i]=x;
        Q.push(MP(0,i));
    }
    
    while(m--)
    {
        lint x;
        cin>>x;
        lint a=Q.top().fi;
        lint b=Q.top().sc;
        Q.pop();
        a+=(arr[b]*x);
        Q.push(MP(a,b));
    }
    
    lint r=0;
    while(!Q.empty())
    {
        //cout<<Q.top().fi<<" "<<Q.top().sc<<endl;
        r=Q.top().fi;
        Q.pop();
    }
    cout<<r;
    return 0;
}
