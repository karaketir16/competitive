#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR(x) for(int i = 0;i<x;i++)

using namespace std;
typedef long long int lint;
vector<lint> tree(4*N);
vector<lint> v;
void build(int ind, int l, int r)
{
    if(l==r) tree[ind] = v[l];
    else
    {
        int mid = (l+r)/2;
        build(ind * 2, l, mid);
        build(ind * 2+1,mid+1, r);
        tree[ind]= tree[ind * 2] ^ tree[ind * 2 + 1];
    }
}
void update(int ind, int l, int r, int x, int val)
{
    if(x<l||x>r) return;
    if(l==x && r==x) tree[ind] = val;
    else
    {
        int mid = (l+r)/2;
        update(ind * 2, l, mid, x, val);
        update(ind * 2+1,mid+1, r, x, val);
        tree[ind] = tree[ind * 2] ^ tree[ind * 2 + 1];
    }
}
lint query(int ind, int l, int r, int lw, int rw)
{
    if(l>rw || r<lw) return 0;

    if(l>=lw && r<=rw) return tree[ind];
    else
    {
        int mid = (l+r)/2;
        return query(ind * 2, l, mid, lw, rw) ^ query(ind * 2 + 1, mid + 1, r, lw, rw);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    v = vector<lint>(n+1);
    for(int i=1;i<n+1;i++)
    {
        cin>>v[i];
    }
    build(1, 1, n);
    FOR(m)
    {
        int q, l, r;
        cin>>q>>l>>r;
        if(q-1)
        {
            update(1,1,n,l,r);
        }
        else
        {
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
    return 0;
}