#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	10000000
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;

int minn=inf;
string s;
int arr[6101][6101];
int fonk(int f,int l)
{
  //cout<<f<<" "<<l<<endl;
  if(arr[f][l]!=-1) return arr[f][l];
  if(f>=l)
  {
    //cout<<"f: "<<f<<" l: "<<l<<endl;
    arr[f][l]=0;
    return 0;
  }
  else
  {
    if(s[l]==s[f])
    {
      int x=fonk(f+1,l-1);
      arr[f][l]=x;
      return x;
    }
    else
    {
      //cout<<"f: "<<f<<" l: "<<l<<endl;
      int x=min(fonk(f+1,l), fonk(f,l-1))+1;
      arr[f][l]=x;
      return x;
    }
  }
}

/*
string s;
int fonk(int f,int l)
{

  if(s[l]==s[f])
  {
    return (f+1,l-1);
  }
  else
  {
    return min(fonk(f+1,l,s), fonk(f,l-1,s))+1;
  }

}
*/
int main()
{
  int test;
  cin>>test;
  while(test--)
  {
    for(int i=0;i<6101;i++)
    {
      for(int j=0;j<6101;j++)
      {
        arr[i][j]=-1;
      }
    }
    string str;

    vector<vector<int>> matrix;
    cin>>str;
    s=str;
    for(int i=0;i<str.size();i++)
    {
      for(int j=0;j<str.size();j++)
      {
        if(arr[i][j]==-1)
        {
          fonk(i,j);
        }
      }
    }
/*
    for(int i=0;i<7;i++)
    {
      for(int j=0;j<7;j++)
      {
        cout<<arr[i][j]<<" ";
      }
      cout<<endl;
    }
*/
    int x = arr[0][str.size()-1];
    printf("%d\n",x);
  }

  return 0;
}
