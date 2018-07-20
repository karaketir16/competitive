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
    vector<int> servers(n);
    int total=0;
    for(int i=0;i<n;i++)
    {
        cin>>servers[i];
        total+=servers[i];
    }
    int ort1= total/n;
    int ort2=ort1+1;
    int hamle=0;

    int seconds=0;
    for(int i=0;i<n;i++)
    {
        if(servers[i]<ort1)
        {
            int x=ort1-servers[i];
            hamle-=(x);
            seconds+=x;
            servers[i]=ort1;
        }
        else if(servers[i]>ort2)
        {
            int x=servers[i]-ort2;
            hamle+=(x);
            seconds+=x;
            servers[i]=ort2;
        }
    }
    for(int i=0;i<n&&hamle!=0;i++)
    {
        if(hamle>0&&servers[i]==ort1)
        {
            servers[i]++;
            seconds++;
            hamle--;
        }
        else if(hamle<0&&servers[i]==ort2)
        {
            servers[i]--;
            seconds++;
            hamle++;
        }
    }
    cout<<seconds/2;
    return 0;
}