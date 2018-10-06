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


int main()
{
    int g;
    cin>>g;
    while(g--)
    {
        int n;
        int k;
        lint m;
        cin>>n;
        int result=0;
        while(n--)
        {
            cin>>m>>k;
            if(m&1) result^=1;
            else 
            {
                if(m!=2) result^=2;
                else result^=0;
            }
        }
        if(result) cout<<"BOB\n";
        else cout<<"BEN\n";
        
    }
    
    return 0;
}