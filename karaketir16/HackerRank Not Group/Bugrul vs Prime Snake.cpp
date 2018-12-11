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
vector<bool> primes(500003,true);
vector<int> sgmnt(1<<21,0);
int n=1<<20;
void add(int x)
{
	x+=n;
	while(x)
	{
		//cout<<"add";
		sgmnt[x]++;
		x>>=1;
	}
}
void dec(int x)
{
	x+=n;
	while(x)
	{
		//cout<<"dec";
		sgmnt[x]--;
		x>>=1;
	}
}
int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += sgmnt[l++];
    if (r&1) res += sgmnt[--r];
  }
  return res;
}
struct Node
{
	vector<int> baglar;
	int value;
	bool visited=0;
};
vector<Node> nodes(500002);
int total =0;

void gezi(int x,int live)
{
	//cout<<"gezi:"<<x<<" ";
	nodes[x].visited=1;
	if(primes[x])
	{
		live--;
		if(live<=0)
		{
			return;
		}
	}
	else total++;
	live+=query(0,x);
	add(x);
	for(auto c:nodes[x].baglar)
	{
		if(nodes[c].visited==true) continue;
		gezi(c,live);
	}
	dec(x);
	
	 	
}
int main()
{
	lint calculated=0;
	for(int i=2;i<250003;i++)
	{
		calculated=0;
		for(int j=2;;j++)
		{
			calculated=i*j;
			if(calculated>500003) break;
			primes[calculated]=false;
		}
	}
	primes[0]=false;
	primes[1]=false;

	int m,d;
	cin>>m>>d;
	for(int i=0;i<m-1;i++)
	{
		int x,y;
		cin>>x>>y;
		nodes[x].baglar.pb(y);
		nodes[y].baglar.pb(x);
	}
	int live = 1;
	gezi(d,live);
	cout<<total;
	return 0;
}
