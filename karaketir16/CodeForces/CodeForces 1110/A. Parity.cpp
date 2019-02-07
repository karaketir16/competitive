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
bool is_odd(lint a, lint p)
{
	if(a%2 == 0 && p!=0) return false;

	return true;
}
int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	lint b, k;
	cin>>b>>k;
	lint result = 0;
	while(k-->0) {
		lint a;
		cin>>a;
		result+=(a*is_odd(b, k))%2;
	}
	if(result%2 == 0) cout<<"even";
	else cout<<"odd";

	return 0;
}