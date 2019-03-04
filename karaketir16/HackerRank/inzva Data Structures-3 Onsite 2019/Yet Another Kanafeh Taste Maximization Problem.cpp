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
    lint number;
    Node* ch[2];
};

void add(Node* &root,  lint number, lint index = 40)
{
    if(root == nullptr)
        root = new Node;


    if(index < 0) 
    {
    root->number = number;
    return;
    }

    add( ((number>>index)&1) ? root->ch[1] : root->ch[0],  number, --index);
}

lint find(Node* &root,  lint number, lint index = 40)
{
    if(index < 0) 
        return root->number;

    return find( root->ch[!((number>>index)&1)] != nullptr ? root->ch[!((number>>index)&1)] : root->ch[((number>>index)&1)],  number, --index);
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<lint> v(n);
    Node* root = new Node;

    INPUT(v);

    lint suff = 0;
    for(int i = n-1; i >=0; i--)
    {
        suff ^= v[i];
        add(root, suff);
    }
    lint result = 0;
    lint pre = 0;
    for(int i = 0; i < n; i++)
    {
        pre ^= v[i];
        result = max(result, pre^find(root, pre));
    }
    cout<<fixed<<result;
    return 0;    
}