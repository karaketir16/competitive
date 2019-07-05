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
std::vector<lint> tree(4*N);
std::vector<lint> v;
lint build(lint t, lint l, lint r)
{
	if(l == r) 
	{
		tree[t] = v[l];
		return tree[t];
	}

	tree[t] = build(2*t, l, mid(l, r)) 
			+ build(2*t + 1, mid(l, r) + 1, r);

	return tree[t]; 
}
lint update(lint t, lint l, lint r, lint value, lint x)
{
	if(l == r && l == x) 
	{
		tree[t] = value;
		return tree[t];
	}

	if(x <= mid(l, r)) update(2*t, l, mid(l, r), value, x);
	else update(2*t + 1, mid(l, r) + 1, r, value, x);
	tree[t] = tree[2*t] + tree[2*t+1];
	return tree[t]; 
}

lint query(lint t, lint l, lint r, lint ls, lint rs)
{
	if(r < ls || l > rs) return 0;
	if(l >= ls && r <= rs) 
	{
		return tree[t];
	}

	return query(2*t, l, mid(l, r), ls, rs) + query(2*t + 1, mid(l, r) + 1, r, ls, rs);  
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	lint n, q;
	cin>>n>>q;
	v = vector<lint> (n+1);

	FOR1(n)
	{
		cin>>v[i];
	}

	build(1, 1, n);

	while(q--) {
		lint a, b, c;
		cin>>a>>b>>c;
		a--;
		if(a)
		{
			update(1, 1, n, c, b);
		}
		else
			cout<<query(1, 1, n, b, c)<<"\n";
	}
	return 0;
}