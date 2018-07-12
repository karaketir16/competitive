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
int n,a,total=0;
set<pair<int,int>> results;
void fonk(vector<int> &arr,int g, int l, int b, int s)
{
    total++;
    results.insert(MP(b,s));
    if(g==l)
    {
        if(s+1<n&&arr[s+1]>a)
        {
            fonk(arr,g+1,l,b,s+1);
        }
        if(b-1>=0&&arr[b-1]>a)
        {
            fonk(arr,g+1,l,b-1,s);
        }
    }
    else if(g>l)
    {
        if(s+1<n&&arr[s+1]<a)
        {
            fonk(arr,g,l+1,b,s+1);
        }
        if(b-1>=0&&arr[b-1]<a)
        {
            fonk(arr,g,l+1,b-1,s);
        }
    }
}
int main()
{
    cin>>n>>a;
    vector<int> arr(n);
    int a_ind;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==a)
        {
            a_ind=i;
        }
    }
    fonk(arr,0,0,a_ind,a_ind);
    cout<<"test: "<<a_ind<<endl;
    cout<<results.size();
    
    return 0;
}