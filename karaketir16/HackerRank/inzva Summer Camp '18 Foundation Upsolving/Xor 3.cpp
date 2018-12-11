#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1000005
#define MOD 1000000007
using namespace std;
vector<int> global_totals;
int calc_sum(int a,int b)
{
    return global_totals[b]^global_totals[a-1];
}
int main()
{


    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    for(int i=1;i<n+1;i++)
    {
        cin>>arr[i];
    }
    int total=0;
    vector<int> totals(n+1,0);
    for(int i=1;i<n+1;i++)
    {
        total^=arr[i];
        totals[i]=total;
    }
    global_totals=totals;
    int q;
    cin>>q;
    while(q--)
    {
        int a;
        int b;
        cin>>a>>b;
        cout<<calc_sum(a,b)<<"\n";
    }

    
    return 0;
}