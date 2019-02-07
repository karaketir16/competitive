#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
void fonk()
{
	lint a;
	cin>>a;
	lint z = 0, o = 0;
	while(a>0) {
		if(a%2 == 0) z++;
		else o++;
		a/=2;
	}
	if(z == 0)
	{
		if(o%2==0)
		{
			lint e = 0;
			for (int i = 0; i < o; ++i)
			{
				if(i%2 == 0)
				{
					e<<=1;
					e++;
				}
				else
				{
					e<<=1;
				}
			}
			lint d = pow(2, o/2);
			cout<<max(e/2, d/2)<<"\n";
		}
		else cout<<1<<'\n';
	}
	else
	{
		lint e = pow(2, z+o);
		e--;
		cout<<e<<"\n";
	}
}
int main(int argc, char const *argv[]) {
	std::ios::sync_with_stdio(false);

	lint n;
	cin>>n;
	while(n--) fonk();
	return 0;
}