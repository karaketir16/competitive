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
lint arr[]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,
    3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976,
    7778742049,12586269025,20365011074,32951280099,53316291173,86267571272,139583862445,225851433717,365435296162,591286729879,956722026041,1548008755920};
int main()
{
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        lint minn=inf;
        for(int i=0;i<m;i++)
        {
            lint x;
            scanf("%lld",&x);
            minn=min(minn,x);
        }
        lint nbr=arr[59];
        lint dist=abs(nbr-minn);
        for(int i=58;i>=0;i--)
        {
            if(abs(arr[i]-minn)<dist)
            {
                dist=abs(arr[i]-minn);
                nbr=arr[i];
            }
        }
        for(int i=0;i<m;i++)
        {
            printf("%lld ", nbr);
        }
        printf("\n");
    }

    return 0;
}
