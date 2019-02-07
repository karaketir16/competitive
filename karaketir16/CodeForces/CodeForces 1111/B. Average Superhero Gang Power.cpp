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
    std::ios::sync_with_stdio(false);
    lint n, k, m;
    cin >>n>>k>>m;

    std::vector<lint> v(n);
    INPUT(v);

    double total = 0;
    FORE(v) total+=a;
    double ave = total/n;
    double ave1 = ave;
    lint ntemp = n;
    double tottemp = total;
    lint mtemp = m;
    sort(ALL(v));
    FORE(v)
    {
        if(mtemp <= 0) break;
        if(a < ave1)
        {
            tottemp-=a;
            ntemp--;
            ave1 = tottemp / ntemp;
            mtemp--;
        }
        else if(k<=mtemp)
        {
            tottemp+=k;
            ave1 = tottemp/ntemp;
            mtemp-=k;
        }
        else
        {

            tottemp+=mtemp;
            ave1 = tottemp/ntemp;
            mtemp-=mtemp;
        }
    }

    reverse(ALL(v));
    FORE(v)
    {
        if(m <= 0) break;
        if(a < ave)
        {
            total-=a;
            n--;
            ave = total / n;
            m--;
        }
        else if(k<=m)
        {
            a+=k;
            total+=k;
            ave = total/n;
            m-=k;
        }
        else
        {
            a+=m;
            total+=m;
            ave = total/n;
            m-=m;
        }
    }
    printf("%.15lf", max(ave, ave1));
    return 0;
}