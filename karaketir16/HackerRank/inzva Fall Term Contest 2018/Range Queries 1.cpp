#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 500005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;

vector<int> tree(4*N);

void update(int ind, int l, int r, int x, int val)
{
    if(x<l||x>r) return;
    if(x==l&&x==r)
    {
        tree[ind] = val;
        return;
    }
    int mid =(l+r)/2;
    update(2*ind, l, mid, x, val);
    update(2*ind + 1, mid+1, r, x, val);
    tree[ind] = max(tree[2*ind], tree[2*ind + 1]);
}
int query(int ind, int l, int r, int lq, int rq)
{
    if(lq>r||rq<l) return 0;

    if(lq<=l&&rq>=r) return tree[ind];
    int mid=(l+r)/2;
    return max(query(2*ind, l, mid, lq, rq), query(2*ind +1, mid+1, r, lq, rq));
}

int main()
{
    int n, q;
    cin>>n;
    for(int i = 1; i<=n;i++)
    {
        int x;
        scanf("%d", &x);
        update(1, 1, n, i, x);
    }
    cin>>q;
    while(q--)
    {
        int x;
        scanf("%d", &x);
        x--;
        if(x)
        {
            int i, a;
            scanf("%d %d", &i, &a);
            update(1,1,n,i,a);
        }
        else
        {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query(1,1,n,l,r));
        }
    }
    return 0;
}