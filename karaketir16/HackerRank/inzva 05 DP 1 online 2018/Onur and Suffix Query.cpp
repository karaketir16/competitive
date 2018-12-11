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

int arr[N];

set<int> ss;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> numbers(n+1);
    for(int i=1; i<=n ; i++)
    {
        cin>>numbers[i];
    }
    for(int i=n;i>0;i--)
    {
        ss.insert(numbers[i]);
        arr[i]=ss.size();
    }
    while(m--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n",arr[x]);
    }
    return 0;
}