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
	int t;
	cin>>t;
	sorryToUseThat:
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a=0;
		string s;
		cin>>s;
		while(n--)
		{
			char ch=s[n-1];
			if(ch>=0x30&&ch<=0x39)
			{
				a++;
				//cout<<"test";
				if(a>=k)
				{
					cout<<":("<<endl;
					goto sorryToUseThat;
				}
			}
			else
			{
				a=0;
			}
		}
		cout<<":)"<<endl;
	}

	return 0;
}
