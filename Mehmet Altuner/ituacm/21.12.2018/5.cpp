#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
	vector <lli> ar;
	lli n, res = 0;
	cin >> n;

	ar.resize(n);
	for(int i=0; i<n; i++)
		cin >> ar[i];

	sort(ar.begin(), ar.end());

	for(int i=1; i<=n; i++)
		res += abs(i - ar[i-1]);

	cout << res << endl;

	return 0;
}