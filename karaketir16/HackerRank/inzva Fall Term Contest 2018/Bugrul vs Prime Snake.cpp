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
int total=0;
vector<int> tree(4*N);
vector<bool> primes(N, true);
vector<bool> visited(N, false);
vector<vector<int>> nodes(N);
vector<int> yalcin(N);
void add(int ind, int l, int r, int x, int val)
{
    //cout<<"ttes";
    if(x<l||x>r) return;
    if(l==x&&r==x) 
    {
        tree[ind]++;
        return;
    }
    int mid = (l+r)/2;
    add(2*ind, l, mid, x, val);
    add(2*ind+1, mid+1, r, x, val);
    tree[ind]=tree[2*ind]+tree[2*ind+1];
}

int query(int ind, int l, int r, int lq, int rq)
{
    if(lq>r||rq<l) return 0;

    if(l>=lq&&rq>=r) return tree[ind];
    int mid = (l+r)/2;
    return query(2*ind, l, mid, lq, mid)+query(2*ind+1, mid+1, r, mid+1, rq); 
}
void calc_primes()
{
    primes[0]=primes[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        if(!primes[i]) continue;
        for(int j = i*i; j<N;j+=i)
        {
            primes[j] = false;
        } 
    }
}

void find_yalcin(int now)
{
    yalcin[now] = query(1, 1, N, 1, now-1);
    add(1, 1, N, now, 1);
    visited[now]= true;
    for(auto a: nodes[now])
    {
        if(!visited[a]) find_yalcin(a);
    }
    add(1, 1, N, now, -1);
}
void dfs(int now, int health)
{
    if(primes[now]) health--;
    if(!health) return;
    if(!primes[now]) total++;
    health+=yalcin[now];
    visited[now]= true;
    //cout<<"test";
    for(auto a: nodes[now])
    {
        if(!visited[a]) dfs(a, health);
    }
}
int main()
{
    calc_primes();
    int n, d;
    cin>>n>>d;
    for(int i =0 ;i<n-1;i++)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        nodes[x].pb(y);
        nodes[y].pb(x);
    }
    find_yalcin(d);
    visited = vector<bool> (N, false);
    dfs(d, 1);
    cout<<total;
    return 0;
}