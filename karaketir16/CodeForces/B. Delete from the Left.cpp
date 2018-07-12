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
    string s;
    string t;
    cin>>s;
    cin>>t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    int ssize=s.size();
    int tsize=t.size();
    int i=0;
    for(i=0;i<ssize&&i<tsize;i++)
    {
        if(s[i]!=t[i]) break;
    }
    ssize-=i;
    tsize-=i;
    cout<<ssize+tsize;


    return 0;
}