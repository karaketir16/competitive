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
int fonk(lint x)
{
    lint a=sqrt(x);
    if(a==sqrt(x)) return 1;
    return 2;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        lint top=0;
        cin>>n;
        while(n--)
        {
            lint x;
            cin>>x;
            top+=fonk(x);
        }
        if(top%2==0) cout<<"KEO\n";
        else cout<<"Emre\n";
        
    }
    return 0;
}
