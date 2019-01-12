#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector <int> ar(m);
	
	for(int i=0; i<m; i++)
		scanf("%d", &ar[i]);
	
	sort(ar.begin(), ar.end());

	int min_val = INT_MAX;

	for(int i=0; i<=m-n; i++){
		int j = i+n-1;
		min_val = min(min_val, ar[j]-ar[i]);
	}

	printf("%d", min_val);

	return 0;
}