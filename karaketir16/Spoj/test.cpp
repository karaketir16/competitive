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
typedef long long int  lint;
bool check(vector<lint> &v, lint d, lint &c)
{
    lint t=1;
    lint pre=v[0];
    lint n=v.size();
    for (lint i=1;i<n;i++)
    {
        lint elem=v[i];
        if(elem-pre>=d)
        {
            t++;
            pre=elem;
            //cout<<elem<<endl;
        }
    }
    return t>=c;
}

int main()
{
    lint t;
    cin>>t;
    while(t--)
    {
        lint n,c;
        scanf("%lld %lld",&n,&c);
        vector<lint> v(n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld", &v[i]);
        }
        sort(v.begin(),v.end());
        //cout<<endl;
        //check(v,3,c);
        //cout<<endl;
        lint low=1;
        lint high=1000000000;
        lint pos=0;
        while(high-low>1)
        {

            lint mid=(high+low)/2;
            if(check(v,mid,c))
            {
                low=mid;

            }
            else
            {
                high=mid;

            }
        }
        if(check(v,high,c))
        {
            printf("%lld",high);
        }
        else
        {
            printf("%lld",low);
        }
        
    }
    return 0;
}