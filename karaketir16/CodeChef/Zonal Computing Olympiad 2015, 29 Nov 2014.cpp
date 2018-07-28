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
    lint n,k;
    cin>>n>>k;
    vector<lint> numbers(n);
    for(lint i=0;i<n;i++)
    {
        scanf("%d",&numbers[i]);
    }
    sort(numbers.begin(),numbers.end());
    lint i=0;
    lint j=0;
    lint total=0;
    for(;j<n;j++)
    {
        while(numbers[j]-numbers[i]>=k)
        {
            i++;
        }
        total+=(j-i);
    }
    cout<<(n*(n-1)/2)-total;
    return 0;
}
