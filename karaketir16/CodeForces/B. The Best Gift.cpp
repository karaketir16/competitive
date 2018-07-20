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
using namespace std;
typedef long long int lint;
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> genres(m,0);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        genres[x-1]++;
    }
    
    lint total=0;
    for(auto x:genres)
    {
        //cout<<x<<endl;
        total+=x*(n-x);
    }
    cout<<total/2;
    return 0;
}