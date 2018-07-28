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
    int n;
    cin>>n;
    stack<int> brackets;
    int max_deep=0;
    int deep_i=0;
    int max_long=0;
    int long_i=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        //if(brackets.size()==0) 
        if(x==1)
        {
            brackets.push(i);
        }
        else
        {
            int dp=brackets.size();
            if(dp>max_deep)
            {
                deep_i=brackets.top();
                max_deep=dp;
            }
            int gap=i-brackets.top()+1;
            if(gap>max_long)
            {
                long_i=brackets.top();
                max_long=gap;
            }
            brackets.pop();
        }

    }
    printf("%d %d %d %d",max_deep,deep_i+1,max_long,long_i+1);
    return 0;
}
