#include <bits/stdc++.h>
#define LIM 2005
using namespace std;

typedef long long lli;

lli length;
lli n;
vector <vector <lli>> ar; 
vector <lli> parents;
vector <bool> visited;

lli dfs(lli index, lli sum){
	bool leaf = true;
	lli len = LLONG_MIN;

	for(lli c: ar[index]){
		leaf = false;
		len = max(len, dfs(c, sum+1));
	}

	if(leaf)
		return sum;

	return len;

}

int main(int argc, char const *argv[])
{
	cin >> n;
	ar.resize(n+1, vector <lli>());
	visited.resize(n+1, false);

	for(int i=1; i<=n; i++){
		lli x;
		cin >> x;
		if(x == -1){
			parents.push_back(i);
			continue;
		}
		ar[x].push_back(i);
	}

	for(lli p: parents){
		length = max(length, dfs(p, 1));
	}

	cout << length << endl;

	return 0;
}