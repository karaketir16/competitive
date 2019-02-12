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

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);

	bool color = 0;

	lint q;

	cin>>q;

	while(q--) {
		string s;
		cin>>s;

		if(s[1] == 'i') color=!color;
		else
		{
			lint a, b;
			cin>>a>>b;
			lint da = (log(a)/log(2));
			lint db = (log(b)/log(2));

			if(db > da) swap(da, db), swap(a, b);

			//lint old_da = da, old_db = db;
			lint r = 0, bl= 0;

			while(da > db)
			{
				a /= 2;
				if(color^(da%2==0)) bl++;
				else r++;
				da--;
			}

			if(a == b) 
			{
				if(color^(da%2==0)) bl++;
				else r++;
				if(s[1] == 'r') cout<<r<<"\n";
				if(s[1] == 'b') cout<<bl<<"\n";
				// lint num = (old_da - da)/2;
				// if((old_da - da)%2 == 1)
				// {
				// 	cout<<num<<"\n";
				// }
				// else
				// {
				// 	if(color^(da%2==0)&&(s[1] == 'b')) num++;
				// 	if((!(color^(da%2==0)))&&(s[1] == 'r')) num++;
				// 	cout<<num<<"\n";	
				// }
			}
			while(a!=b)
			{
				if(color^(da%2==0)) bl++;
				else r++;	
				if(color^(db%2==0)) bl++;
				else r++;
				a/=2;
				da--;
				b/=2;
				db--;
			}
			if(color^(da%2==0)) bl++;
			else r++;			
			if(s[1] == 'r') cout<<r<<"\n";
			if(s[1] == 'b') cout<<bl<<"\n";	

		}
	}
	return 0;
}