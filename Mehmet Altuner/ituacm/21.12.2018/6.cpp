#include <bits/stdc++.h>
#define LIM 100005

using namespace std;

typedef long long int lli;

vector <lli> ar;

int main(int argc, char const *argv[])
{
	lli n, d, res = 0;
	cin >> n >> d;
	
	ar.resize(n);

	for(int i=0; i<n; i++)
		cin >> ar[i];

	sort(ar.begin(), ar.end());

	for(int i=0; i<n; i++){
		auto it = upper_bound(ar.begin(), ar.end(), ar[i] + d);
		lli index = it - ar.begin();

		if(index >= n && ar[index-1] > ar[i]+d)
			break;

		lli amount = index - i - 1;
		if(amount >= 2)
			res += (amount * (amount - 1)) / 2;
	}
 	
	cout << res << endl;

	return 0;
}