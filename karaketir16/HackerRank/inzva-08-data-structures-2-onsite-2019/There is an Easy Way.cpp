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

	lint n, l, r, q;
	cin>>n>>l>>r;
	l--;
	r--;
	string s;
	cin>>s;
	cin>>q;
	while(q--)
	{
		string c;
		cin>>c;
		if(c[0] == 'S')
		{
			string a, b;
			cin>>a>>b;
			lint *ref = &r; 
			if(a[0] == 'L') ref = &l;
			if(b[0] == 'L') (*ref)--;
			else (*ref)++;
		}
		else if(c[0] == 'R') reverse(s.begin() + l,s.begin() + r +1);
		else
		{
			string a;
			cin>>a;
			lint *ref = &r; 
			if(a[0] == 'L') ref = &l;
			cout<<(*ref);
		}
	}

	return 0;
}