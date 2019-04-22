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
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
int main()
{
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    
    while(q--)
    {
        string s;
        cin>>s;
        stack<char> st;
        bool flag = true; 
        for(auto a: s)
        {
            if(a==')')
            {
                if(st.empty() || st.top() != '(')
                {
                    cout<<"NO\n";
                    flag = false;
                    break;
                }
                st.pop();
            }
            else if(a==']')
            {
                if(st.empty() || st.top() != '[')
                {
                    cout<<"NO\n";
                    flag = false;
                    break;
                }
                st.pop();
            }
            else if(a=='}')
            {
                if(st.empty() || st.top() != '{')
                {
                    cout<<"NO\n";
                    flag = false;
                    break;
                }
                st.pop();
            }
            else
            {
                st.push(a);
            }
        }
        if(flag)cout << (st.empty() ? "YES\n" : "NO\n");
    }
    return 0;
}
