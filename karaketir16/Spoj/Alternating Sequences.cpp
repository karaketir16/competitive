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
typedef long long int lint;
vector<lint> arr(5005);
vector<lint> lgs(5005,1);
int fonk(lint x)
{
  if(x>0) return 1;
  if(x<0) return -1;
  else return 0;
  return 0;
}
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    scanf("%lld", &arr[i]);
  }
  for(int i=0;i<n;i++)
  {
    for(int j=i-1;j>=0;j--)
    {
      if(abs(arr[i])>abs(arr[j])&&fonk(arr[i])*fonk(arr[j])==-1)
      {
        if(lgs[j]+1>lgs[i]) lgs[i]=lgs[j]+1;
      }
    }
  }
  lint maxx=0;
  for(int i=0;i<n;i++)
  {
    maxx=max(maxx,lgs[i]);
  }
  cout<<maxx;
  return 0;
}
