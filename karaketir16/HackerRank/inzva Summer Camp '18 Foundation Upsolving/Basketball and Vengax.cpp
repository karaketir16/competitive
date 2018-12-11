#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define MP make_pair
using namespace std;
typedef long long int lint;
typedef pair<int,int> ii;

int main()
{
	vector<ii> baskets;
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		baskets.pb(MP(x,1));
	}
	
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		baskets.pb(MP(x,2));
	}
	sort(baskets.begin(),baskets.end());
	set<ii> basketsSet(baskets.begin(),baskets.end());

	int i=0,j=0;
	int ftotal=n*3;
	int stotal=m*3;
	int aeb=ftotal-stotal;
	int maxxaeb=aeb;
	int ftotalmax=ftotal;
	int stotalmax=stotal;
	for(auto x: basketsSet)
	{
		for(;baskets[i].fi<=x.fi&&i<n+m;i++)
		{
			if(baskets[i].sc==1)
			{
				ftotal--;
			}
			else
			{
				stotal--;
			}
			aeb=ftotal-stotal;
			
			if(aeb>maxxaeb)
			{
				maxxaeb=aeb;
				ftotalmax=ftotal;
				stotalmax=stotal;
			}
		}
	}
	cout<<ftotalmax<<":"<<stotalmax;
	return 0;
}