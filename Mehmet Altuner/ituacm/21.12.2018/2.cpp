#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
	lli n, res = 0;
	scanf("%lli", &n);

	int ar[5] = {100, 20, 10, 5, 1};

	for(int i=0; i<5; i++){
		res += n / ar[i];
		n = n % ar[i];
	}

	printf("%lli", res);

	return 0;
}