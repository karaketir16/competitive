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
	int k;
	cin>>k;
	string lst;
	cin>>lst;
	while(lst.size()>1)
	{
		string nw;
		int n=lst.size();
		for(int i=1;i<n;i+=2)
		{
			double ch=lst[i-1]*lst[i-1]*lst[i];
			ch=pow(ch,1.0/3.0);
			int ich=ch;
			if(ich!=ch) ich++;
			char c=ich;
			nw+=c;
		}
		if(n%2==1) nw+=(lst[n-1]);
		lst=nw;
	}
	cout<<lst;
	return 0;
}
