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

void prt(vector<lint> &a)
{
    cout<<endl;
    for(auto x:a)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main()
{
    int n,k;
    lint zero=0;
    cin>>n>>k;
    lint total1=0,total2=0,total3=0;
    vector<lint> nmbrs(n+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&nmbrs[i]);
    }
    vector<lint> cpy;
    lint max_result=-1*inf;
    if(k<n)
    {
       
        //FORWARD->BACKWARD
        cpy=nmbrs;
        //prt(cpy);
        cpy[k]=0;
        lint maxx=cpy[k+1];
        lint maxx_i=k+1;
        for(int i=k+2;i<=n;i++)
        {
            cpy[i]+=max(cpy[i-1],cpy[i-2]);
            //prt(cpy);
            if(cpy[i]>maxx)
            {
                maxx=cpy[i];
                maxx_i=i;
            }
        }
        max_result=max(maxx,max_result);
        //cout<<max_result<<endl;
        if(k==1)
        {
            cout<<max(zero,max_result);
            return 0;
        }
        cpy=nmbrs;
        cpy[maxx_i]=0;
        lint maxx2=cpy[maxx_i-1];
        lint maxx2_i=maxx_i-1;
        for(int i=maxx_i-2;i>0;i--)
        {
            cpy[i]+=max(cpy[i+1],cpy[i+2]);
            if(cpy[i]>maxx2)
            {
                maxx2=cpy[i];
                maxx2_i=i;
            }
        }
        maxx2+=maxx;
        max_result=max(max_result,maxx2);
    }
    cpy=nmbrs;
    cpy[k]=0;
    if(k==1)
    {
        if(n==1)
        {
            cout<<0;
        }
        else
        {
            cout<<max(zero,max_result);
        }
    }
    lint maxx=cpy[k-1];
    lint maxx_i=k-1;
    for(int i=k-2;i>0;i--)
    {
        cpy[i]+=max(cpy[i+1],cpy[i+2]);
        if(cpy[i]>maxx)
        {
            maxx=cpy[i];
            maxx_i=i;
        }
    }
    max_result=max(maxx,max_result);
    cout<<max(zero,max_result);
    
    return 0;
}
