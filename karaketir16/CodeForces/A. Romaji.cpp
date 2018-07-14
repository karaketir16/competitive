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
    cin>>s;
    int n=s.size();
    set<char> vovels={'a','e','o','u','i'};
    
    for(int i=0;i<n;i++)
    {
        if(s[i]!='n'&&(vovels.find(s[i])==vovels.end()))//n disinda sessiz ise bak
        {
            if(i+1<n&&(vovels.find(s[i+1])!=vovels.end()))//bir sonraki varsa ve sesli ise devam et
            {
                continue;
            }
            else
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}