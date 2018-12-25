#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long lli;

lli pwr(lli x, lli y){
	if(y == 0)
		return 1;
	if(y == 1)
		return x % mod;

	lli sub_pwr = pwr(x, y/2);
	if( y % 2 == 0)
		return (sub_pwr * sub_pwr) % mod;
	else
		return (x * sub_pwr * sub_pwr) % mod;
}

int main(int argc, char const *argv[])
{
	lli n;
	cin >> n;
	lli res = (3 * pwr(2, n-2)) % mod;
	if(n >=  4)
		res += (pwr(3, n-2) % mod);

	cout << res % mod << endl;
	return 0;
}