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

std::vector<lint> v(12);
lint n1, t1, n2, t2, n3, t3, n4, t4, minn = inf;
lint rec(lint d)
{


    if(n1>3||n2>3||n3>3||n4>3) return 0;
    if(d == 12)
    {
        minn = min(minn, max(max3(t1, t2, t3), t4) - min(min3(t1, t2, t3), t4));
        //dbg(minn);
    }
    n1++;
    t1+=v[d];
    (rec(d+1));
    n1--;
    t1-=v[d];
    n2++;
    t2+=v[d];
    (rec(d+1));
    n2--;
    t2-=v[d];
    n3++;
    t3+=v[d];
    (rec(d+1));
    n3--;
    t3-=v[d];
    n4++;
    t4+=v[d];
    (rec(d+1));
    n4--;
    t4-=v[d];
    return 0;
}
int main()
{
    
    std::ios::sync_with_stdio(false);

    INPUT(v);
    rec(0);
    cout<<minn;
    return 0;
}