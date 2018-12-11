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
    int arr[101]={0};
    for(int i=2;i<=6;i++) arr[i]=1;
    for(int i=7;i<=100;i++)
    {
        if(arr[i-2]==0||arr[i-3]==0||arr[i-5]==0) arr[i]=1;
    }
    int x;
    cin>>x;
    while(x--)
    {
        int y;
        cin>>y;
        if(arr[y]) cout<<"First\n";
        else cout<<"Second\n";
    }
    return 0;
}
