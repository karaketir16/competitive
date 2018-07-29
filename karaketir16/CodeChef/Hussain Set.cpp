#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define all(x) x.begin(),x.end()
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
int main()
{
    int n,q;
    cin>>n>>q;
    vector<lint> v(n);
    queue<lint> q1;
    queue<lint> q2;
    
    for(int i=0;i<n;i++)
    {
        
        scanf("%lld", &v[i]);
  
    }
    
    sort(v.begin(),v.end());
    for(int i=n-1;i>=0;i--)
    {
        q1.push(v[i]);
    }
    lint c=0;
    while(q--)
    {
        lint t=0;
        scanf("%lld", &t);
        lint a;
        for(;c<t;c++)
        {
            if(q1.front()>=q2.front())
            {
                a=q1.front();
                q1.pop();
            } 
            else
            {
                a=q2.front();
                q2.pop();
            }
            q2.push(a/2);
        }
        printf("%lld\n",a);
    }
    return 0;
}
