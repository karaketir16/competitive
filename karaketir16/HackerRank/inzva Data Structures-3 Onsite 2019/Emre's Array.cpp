#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 200005
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
vector<lint> tree(4*N);
vector<lint> lazy1(4*N); //all
vector<lint> lazy2(4*N); //birer
vector<lint> v(N);


void update(lint node, lint start, lint end, lint l, lint r, lint val = 1) {
    if(lazy1[node] != 0) 
    {
        tree[node] += (end - start + 1) * lazy1[node];
        if(start != end) {

            lazy1[2 * node] += lazy1[node];
            lazy1[2 * node + 1] += lazy1[node];
        }
        lazy1[node] = 0;
    }
    if(lazy2[node] != 0) 
    {
        tree[node] += 1.0 * (end - start + 1) * (end - start + 2) * (1.0/2) * lazy2[node];
        if(start != end) {
            lazy2[2 * node] += lazy2[node];
            lazy2[2 * node + 1] += lazy2[node];

            lazy1[2 * node + 1] += lazy2[node] * (mid(end, start) - start + 1);
        }
        lazy2[node] = 0;
    }

    if(start > r || end < l)
        return;
    if(l <= start && end <= r) {
        tree[node] += (end - start + 1) * (end - start + 2) / 2.0; // n*n+1 /2
        tree[node] += (end - start + 1) * (start - l);
        
        if(start != end) {
        lazy1[2 * node] += (start - l);
        lazy1[2 * node + 1] += (start - l);

        lazy1[2 * node + 1] += (mid(end, start) - start + 1);
            
        lazy2[2 * node] += val;
        lazy2[2 * node + 1] += val;
        }
        return;
    }
    lint mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

lint query(lint node, lint start, lint end, lint l, lint r) {
    if(start > r || end < l)
        return 0;

    if(lazy1[node] != 0) {
        tree[node] += (end - start + 1) * lazy1[node];
        if(start != end) {
            lazy1[2 * node] += lazy1[node];
            lazy1[2 * node + 1] += lazy1[node];
        }
        lazy1[node] = 0;
    }

    if(lazy2[node] != 0) 
    {

        tree[node] += ((end - start + 1) * (end - start + 2) * (1.0/2) * lazy2[node]);
        if(start != end) {
            lazy2[2 * node] += lazy2[node];
            lazy2[2 * node + 1] += lazy2[node];

            lazy1[2 * node + 1] += lazy2[node] * (mid(end, start) - start + 1);
        }
        lazy2[node] = 0;
    }

    if(l <= start && end <= r)
        return tree[node];
    lint mid = (start + end) / 2;
    lint p1 = query(2 * node, start, mid, l, r);
    lint p2 = query(2 * node + 1, mid + 1, end, l, r);
    return (p1 + p2);
}


int main()
{
    std::ios::sync_with_stdio(false);
    int n, q;
    cin >> n >>q;

    while(q--){
        lint a, b, c;
        cin>>a>>b>>c;
        if(a == 1)
        {
            update(1, 1, n, b, c, 1);
        }
        else
        {
            cout<<fixed<<query(1, 1, n, b, c)<<'\n';
        }
    }

    return 0;    
}