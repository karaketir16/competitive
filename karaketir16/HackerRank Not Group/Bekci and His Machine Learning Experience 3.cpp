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

int main()
{
	int m,n;
	cin>>m>>n;
	int arr[10][10];
	set<int> ii;
	set<int> jj;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			arr[i][j]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			arr[i][j]=x;
			if(x==0)
			{
				ii.insert(i);
				jj.insert(j);
			}

		}
	}
	for(auto x:ii)
	{
		for(int j=0;j<n;j++)
		{
			arr[x][j]=0;
		}
	}
	for(auto x:jj)
	{
		for(int i=0;i<m;i++)
		{
			arr[i][x]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
	

