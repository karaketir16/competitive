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

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> drives(n);
    for(int i=0;i<n;i++)
    {
        cin>>drives[i];
        
    }
    sort(drives.begin(),drives.end());
    reverse(drives.begin(),drives.end());

    for(int i=1;i<n;i++)
    {
        drives[i]=drives[i]+drives[i-1];
        //cout<<drives[i-1]<<endl;

    }
    /*
    cout<<endl;
    for(auto x:drives)
    {
        cout<<x<<endl;

    }
    */
    int i=0;
    for(i=0;drives[i]<m;i++)
    {
    }
    cout<<i+1;
    
    

    return 0;
}