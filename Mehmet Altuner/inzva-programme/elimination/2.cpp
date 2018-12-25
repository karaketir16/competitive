#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector <lli> ar;
vector <lli> gcds;

lli GCD(lli n, lli m){
	lli temp = 0;

	while(n != 0){
		temp = n;
		n = m%n;
		m = temp;
	}

	return m;
}

void sub(lli gcd, lli index, lli n){
	for(int i=index+1; i<n; i++){
		gcd = GCD(gcd, ar[i]);
		
		sub(gcd, i, n);

		gcds.push_back(gcd);
	}

	return;
}

int main(int argc, char const *argv[])
{
	lli t;
	scanf("%lli", &t);
	while(t--){
		lli n;
		scanf("%lli", &n);
		ar.resize(n, -1);
		gcds.resize(0);

		for(int i=0; i<n; i++)
			scanf("%lli ", &ar[i]);

		for(int i=0; i<n; i++){
			sub(ar[i], n);
		}

		sort(gcds.begin(), gcds.end());
		for(auto x: gcds){
			printf("%lli ", x);
		}
		printf("\n");
	}	
	return 0;
}