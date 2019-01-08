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
    std::ios::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    vector<int> arr(b);
    for(int i=0;i<b;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int minn = *(arr.end()-1) - *arr.begin(); 
    for(int i =0;i+a-1<b;i++)
    {
        minn=min(minn, arr[i+a-1] - arr[i]);
    }
    cout<<minn;
    return 0;
}