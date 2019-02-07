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
	std::ios::sync_with_stdio(false);

	lint m, n, k;
	cin>>n>>m>>k;

	std::vector<lint> v(n);
	INPUT(v);
	lint nw = v[n-1] - v[0] + 1;
	priority_queue<lint> pq; //bas
	for (int i = 1; i < n; ++i)
	{
		pq.push(v[i]-v[i-1]);
	}
	for (int i = 0; i < k-1; ++i)
	{
		lint a = pq.top();
		pq.pop();
		nw-=(a-1);
	}
	cout<<nw;

	return 0;
}