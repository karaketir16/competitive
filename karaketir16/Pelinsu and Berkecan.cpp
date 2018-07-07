#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
using namespace std;
typedef long long int lint;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> candies(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>candies[i];
    }
    sort(candies.begin(),candies.end());
    /*
    for(auto c:candies)
    {
        cout<<c<<" ";
    }
    */
    int minn=inf;
    for(int i=0;i<=n-k;i++)
    {
        int j=i+k-1;
        minn=min(minn,candies[j]-candies[i]);
    }
    cout<<minn;
    return 0;
}