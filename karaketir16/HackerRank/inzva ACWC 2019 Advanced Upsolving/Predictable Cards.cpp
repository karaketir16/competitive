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
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
int main()
{
    std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<bool> is_yasin(2*n+1);
	deque<int> yasin;

	for(int i =0;i<n;i++)
	{
		int a;
		cin>>a;
		is_yasin[a]=true;
		yasin.pb(a);
	}


	deque<int> elif;

	for(int i =1;i<=2*n;i++)
	{
		if(!is_yasin[i]) elif.pb(i);
	}

	sort(ALL(elif));
	sort(ALL(yasin));
	int point =0;
	for(int i =0;i<n;i++)
	{
		if(elif.back()>yasin.back()) // elif get point
		{
			elif.pop_back();
			yasin.pop_back();
			point++;
		}
		else
		{
			elif.pop_front();
			yasin.pop_back();
		}
	}
	cout<<point;
	return 0;
}