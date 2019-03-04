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
#define MOD 1000000007LL
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &e:v)
using namespace std;
typedef long long int lint;

std::vector<vector<lint>> Sgt(11, vector<lint> (4*N));
std::vector<lint> v;


void addTree(lint, lint, lint);
lint getTree(lint, lint);

void update(vector<lint> &tree, lint t, lint l, lint r, lint value, lint x)
{
    if(l == r && l == x) 
    {
        tree[t] = (value%MOD + tree[t]%MOD)%MOD;
        return;
    }

    if(x <= mid(l, r)) update(tree, 2*t, l, mid(l, r), value, x);
    else update(tree, 2*t + 1, mid(l, r) + 1, r, value, x);
    tree[t] = (tree[2*t]%MOD + tree[2*t+1]%MOD)%MOD;
    return; 
}

lint query(vector<lint> &tree, lint t, lint l, lint r, lint ls, lint rs)
{
    if(r < ls || l > rs) return 0;
    if(l >= ls && r <= rs) 
    {
        return tree[t]%MOD;
    }

    return (query(tree, 2*t, l, mid(l, r), ls, rs)%MOD + query(tree, 2*t + 1, mid(l, r) + 1, r, ls, rs)%MOD)%MOD;  
}


void addTree(vector<lint> &tree, lint x, lint val)
{
    update(tree, 1, 1, N, val, x);
}

lint getTree(vector<lint> &tree, lint a)
{
    return query(tree, 1, 1, N, 1, a)%MOD;
}

void calcNum(lint a, lint k)
{
    for(lint i = k; i > 1; i--)
    {
        addTree( Sgt[i], a, getTree(Sgt[i-1], a) );
        // for(int t = 1; t <= 10; t++)
        // {
        //     if(Sgt[t][1] < 0) abort();
        // }
    }
    //getTree(Sgt[1], a);
    addTree(Sgt[1], a, 1);
    //update(Sgt[1], 1, 1, N, 1, a);
    return;
}


int main()
{
    std::ios::sync_with_stdio(false);
    lint n, k;
    cin >>n>>k;

    while(n--){
        lint a;
        cin>>a;
        //cerr<<n<<<<endl;
        calcNum(a, k);

    }



    cout<<fixed<<Sgt[k][1]%1000000007;



    return 0;    
}

// 7 2
// 3 4 6 2 1 4 1