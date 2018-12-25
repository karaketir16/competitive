#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

queue <lli> ar;

struct group{
	vector <lli> data;
	lli size;
};

struct number{
	lli data;
	bool grouped;
};

// max that a group can have, j the current group, n the current number
lli perform(max, j, n){ 
	// base case
	
}

int main(int argc, char const *argv[])
{
	lli n, k, max, sum = 0;
	vector <group> groups;
	vector <number> ar;

	scanf("%lli %lli", &n, &k);

	groups.resize(k, group{vector <lli>(), size});
	ar.resize(n, number{0, 0});

	for(int i=0; i<n; i++){
		scanf("%lli", &ar[i]);
		sum += ar[i];
	}

	sort(ar.begin(), ar.end());

	max = sum / k; 

	return 0;
}