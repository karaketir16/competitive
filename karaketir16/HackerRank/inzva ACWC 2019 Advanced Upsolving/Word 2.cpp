#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)1e5+5)
#define MOD ((int)1e9 + 7) 
#define ll long long
#define _ << " " <<
#define TRACE(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define MP make_pair
#define mid ((l+r)/2)


int n,m,t,k;
int d[MAXN];
vector <int> v;
char c[3] = {'A' , 'B' , 'L'};
int spCount;
int sz;
ll sum;


long long fast_exp(long long a,long long b){long long res=1;
while(b){
	if(b&1LL)
	{	
		res*=a;
	}
	b>>=1LL;
	a*=a;
}
return res;}

char charEv(char c)
{
	if(c == 'A' or c == 'E' or c == 'I' or c == 'O' or c== 'U')
		return 'A';
	else if(c == 'L')
		return 'L';
	else if(c != '_')
		return 'B';
	else
		return '_';
	return 0;
}

int rec(string s,int index,int vCount , int cCount , int lCount)
{
	// TRACE(index);
	if(index == spCount)
	{
		if(lCount == 0)
			return 0;
		int tmpV = 0;
		int tmpC = 0;
		for (int i = 0; i < sz; ++i)
		{
			if(s[i] == 'A')
			{
				tmpV++;
				tmpC = 0;
				if(tmpV == 3)
					return 0;
			}
			else
			{
				tmpC++;
				tmpV = 0;
				if(tmpC == 3)
					return 0;
			}
		}

		ll pw = fast_exp(5,vCount);
		ll pw2 = fast_exp(20,cCount);

		sum += pw*pw2;
		return 0;
	}	
	for (int i = 0; i < 3; ++i)
	{
		string tmp = s;
		tmp[v[index]] = c[i];

		// if(v[index] == 0 || v[index] == sz-1 || (tmp[v[index]-1] == tmp[v[index]+1] && tmp[v[index]] == tmp[v[index] -1]))
			rec(tmp , index+1 , vCount + (i==0) , cCount + (i==1) , lCount + (i==2));
	}

	return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
	
	string s;


	cin >> s;

	// TRACE(s);

	sz = s.size();
	// TRACE(sz);
	int lc;
	for (int i = 0; i < sz; ++i)
	{
		if(s[i] == 'L')
			lc++;
		s[i] = charEv(s[i]);
		
		if(s[i] == '_')
			v.pb(i);
	}
	spCount = v.size();
	// TRACE(s);
	// TRACE(lc);
	// TRACE(spCount);
	rec(s,0,0,0,lc);
	printf("%lld\n", sum);

	return 0;
}
//by salihfc