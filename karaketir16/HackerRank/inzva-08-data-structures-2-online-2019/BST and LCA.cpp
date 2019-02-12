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
struct Node
{
	lint value;
	Node* l = NULL;
	Node* r = NULL;
	lint depth = 0;
	std::vector<Node*> anch;//1 2 4 8
};

void add(Node* &node, Node* ad, Node* parent, lint dp)
{
	if (node == NULL)
	{
		node = ad;
		node->anch[0] = parent;
		node->depth=dp;
	}
	else if(ad->value > node->value)
		add(node->r, ad, node, dp+1);
	else
		add(node->l, ad, node, dp+1);
}


int main(int argc, char const *argv[])
{

	ios::sync_with_stdio(false);
	lint n, q;
	cin>>n>>q;
	Node* root = NULL;
	while(n--) {
		auto a = new Node;
		a->anch = vector<Node*>(15, NULL);
		cin>>a->value;
		add(root, a, NULL, 0);
	}
	queue<Node*> qu;
	map<lint, Node*> mp;
	qu.push(root);
	while(!qu.empty())
	{
		auto a = qu.front();
		qu.pop();
		mp[a->value] = a;
		//dbg(a->value);
		if(a->l)qu.push(a->l);
		if(a->r)qu.push(a->r);
		for (int i = 0; i < 14; ++i)
		{
			if(a->anch[i] != NULL) a->anch[i+1] = a->anch[i]->anch[i];
		}
	}

	while(q--)
	{
		lint a,b;
		cin>>a>>b;
		//dbg(q-10);
		Node *na, *nb;
		na = mp[a];
		nb = mp[b];

		//dbg(na->depth);
		//dbg(nb->depth);
		
		if(na->depth<nb->depth) swap(na, nb), swap(a, b);

		lint fark = na->depth - nb->depth;

		for(int i = 0;fark>0;i++, fark>>=1) 
		{
			if(fark&1) na = na->anch[i];	
		}


		if(na == nb) 
		{
			cout<<b<<"\n";
			continue;
		}
			

		for (int i = 14; i >=0; i--)
		{
			if(na->anch[i] != nb->anch[i])
			{
				na = na->anch[i];
				nb = nb->anch[i];
			} 
		}
		//dbg(na->value);
		//dbg(nb->value);
		cout<<na->anch[0]->value<<"\n";
		
	}
	return 0;
}