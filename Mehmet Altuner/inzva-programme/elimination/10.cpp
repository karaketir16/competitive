#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long int lli;

struct query{
	int c;
	lli n1;
	lli n2;
};

vector <bool> deleted(N, 0); // deleted edges
vector <pair <lli, lli>> edges;
vector <query> queries;
vector <lli> parent(N);

lli find_parent(lli n){
	if(parent[n] == n)
		return n;

	return parent[n] = find_parent(parent[n]);
}

void unite(lli n1, lli n2){
	lli parent1 = find_parent(n1);
	lli parent2 = find_parent(n2);

	parent[parent1] = parent2;
	return;
}

bool is_sibling(lli n1, lli n2){
	return find_parent(n1) == find_parent(n2);
}

int main(int argc, char const *argv[])
{
	lli n, m, q;
	edges.resize(m+5);

	// init parents
	for(int i=0; i<=n; i++)
		parent[i] = i;
	
	for(int i=1; i<=m; i++){
		lli x, y;
		scanf("%lli %lli", &x, &y);
		edges[i] = make_pair(x, y);
	}

	for(int i=0; i<q; i++){
		int c;
		scanf("%d", &c);
		if(c == 1){
			lli edge;
			scanf("%lli", &edge);
			deleted[edge] = true;
			queries.push_back(query{1, edge, 0});
		}else{
			lli n1, n2;
			scanf("%lli %lli", &n1, &n2);
			queries.push_back(query{2, n1, n2});
		}
	}

	reverse(ALL(queries));

	for(int i=1; i<=m; i++){
		if(deleted[i])
			continue;

		pair <lli, lli> edge = edges[i];
		unite(edge.first, edge.second);
	}

	stack <string> res;

	for(auto q: queries){
		if(q.c == 1){
			pair <lli, lli> edge = edges[q.n1];
			unite(edge.first, edge.second);
		}else{
			if(is_sibling(q.n1, q.n2)){
				stack.push("Connected");
			}else{
				stack.push("Not Connected");
			}
		}
	}

	while(!res.empty()){
		printf("%s\n", res.top()); res.pop();
	}

	return 0;
}