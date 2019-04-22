#include <bits/stdc++.h>

#define N 100005
#define mid(x,y) (x+y)/2
using namespace std;

vector<int> tree(4*N), arr(N);

// void build(int t, int l, int r)
// {
// 	if(l==r)
// 	{
// 		tree[t]=arr[l];
// 		return;
// 	}
// 	build(2*t, l, mid(l, r));
// 	build(2*t, mid(l, r)+1, r );
// 	tree[t]=max(tree[2*t],tree[2*t+1]);
// }
void update(int t, int l, int r, int i, int value)
{
	// cout<<t<<" "<<l<<" "<<r<<endl;

	if(l==r&&i==l)
	{
		tree[t]=value;
		return;
	}
	if(i<=mid(l,r)) update(2*t, l, mid(l,r), i, value);
	else update(2*t+1, mid(l,r)+1, r, i, value);
	tree[t]=max(tree[2*t],tree[2*t+1]);
}
int query(int t, int l, int r, int ls, int rs)
{
	if(l>rs||r<ls) return 0;

	if(l>=ls&&r<=rs)
	{
		return tree[t];
	}
	return max(query(2*t, l, mid(l, r), ls, rs),
	    query(2*t+1, mid(l, r)+1, r, ls, rs));

}

int main(){
   // cout<<++x<<p.first;
   int res=0;
   int n=0;
   cin>>n;
   while(n--)
   {
	   int x;
	   cin>>x;
	   int local =//0;
		  query(1, 1, N, 1, x-1);
		// cout<<local<<endl;
	   update(1, 1, N, x, local+1);
		// cout<<"q "<<query(1, 1, N, x, x)<<endl;
	   res = max(res, local+1);
   }
   cout<<res;
   return 0;
}

/*
10
1 9 8 10 2 3 4 6 5 7
*/
