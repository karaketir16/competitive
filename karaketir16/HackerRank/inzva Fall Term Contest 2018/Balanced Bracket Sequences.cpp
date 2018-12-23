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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        stack<char> stc;
        string s;
        cin>>s;
        bool flag=true;
        for(auto c:s)
        {
            if(c=='('||c=='{'||c=='[')
            {
                stc.push(c);
            }
            else
            {  
                if(stc.empty())
                {
                    printf("NO\n");
                    flag=false;
                    break;
                }
                char a = stc.top();
                stc.pop();
                if((a=='('&&c==')')||(a=='['&&c==']')||(a=='{'&&c=='}'))
                {
                }
                else
                {
                    printf("NO\n");
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
        {

    
            if(stc.empty())
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}