#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 200005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;
typedef long long int lint;

vector<lint> numbers(N,0);
vector<lint> arr(N,0);
int main()
{
    std::ios::sync_with_stdio(false);

    lint n,q;
    cin>>n>>q;
    for(int i = 1; i<=n;i++)
    {
        cin>>numbers[i];
    }

    for(int i =0;i<q;i++)
    {
        lint x,y;
        cin>>x>>y;
        arr[x]++;
        arr[++y]--;
    }
    for(int i = 1; i<N;i++)
    {
        arr[i]+=arr[i-1];
    }
    sort(arr.rbegin(), arr.rend());
    sort(numbers.rbegin(), numbers.rend());
    lint result=0;
    for(int i=0;i<n;i++) result+=(arr[i]*numbers[i]);
    cout<<result;
    return 0;
}