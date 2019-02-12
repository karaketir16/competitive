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

	lint n, q;
	cin>>n>>q;

	deque<lint> v(n);
	INPUT(v);

	while(q--) {
		lint a, i, j;
		cin>>a>>i>>j;
		a--;
		j--;
		i--;

		auto temp = deque<lint> (v.begin()+i, v.begin()+j+1);
		v.erase(v.begin()+i, v.begin()+j+1);
		if(a)
			v.insert(v.end(),temp.begin(), temp.end());
		else
			v.insert(v.begin(),temp.begin(), temp.end());
	}
	cout<<abs(v.back()-v.front())<<"\n";
	FORE(v) cout<<a<<' ';
	return 0;
}