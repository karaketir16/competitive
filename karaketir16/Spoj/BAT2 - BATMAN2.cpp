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
const int MAX=101;

/*
void fill()
{
    for(auto &a:lgnt)
    {
        for(auto &b:a)
        {
            b=1;
        }
    }
}
*/
int main()
{
    int f;
    cin>>f;
    here:
    f--;

    int n;
    cin>>n;
    vector<int> arr(MAX,0);
    vector<int> lgnt(MAX,1);
    vector<int> whr(MAX,-1);
    vector<bool> flag(MAX,0);
    //fill();
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j]&&lgnt[i]+1>lgnt[j])
            {
                lgnt[j]=lgnt[i]+1;
                whr[j]=i;
            }
        }
    }
    int maxx_i=0;
    for(int i=1;i<n;i++)
    {
        if(lgnt[i]>lgnt[maxx_i])
        {
            maxx_i=i;
        }
    }
    //cout<<maxx_i<<endl;
    for(int i=maxx_i;i!=-1;i=whr[i])
    {
        flag[i]=1;
    }
    //cout<<lgnt[maxx_i]<<endl;
    vector<int> lgnt2(MAX,1);
    vector<int> whr2(MAX,-1);

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j]&&lgnt2[i]+1>lgnt2[j])
            {
                lgnt2[j]=lgnt2[i]+1;
                whr2[j]=i;
            }
        }
    }
    maxx_i=0;
    for(int i=1;i<n;i++)
    {
        if(lgnt2[i]>lgnt2[maxx_i])
        {
            maxx_i=i;
        }
    }
    //cout<<lgnt2[maxx_i]<<endl;
    for(int i=maxx_i;i!=-1;i=whr2[i])
    {
        flag[i]=1;
    }
    int t=0;
    for(int i=0;i<n;i++)
    {
        if(flag[i]) t++;
    }
    cout<<t<<"\n";
    if(f) goto here;
    return 0;
}