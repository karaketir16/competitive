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
    lint number;
    Node* ch[2];
    lint child =0;
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
lint last = 0;
lint nax = inf;
void find(Node* &root, vector<lint> &vec, lint index = 40)
{
    if(root == nullptr) return;
    if(index < 0) 
    {
        vec.push_back(root->number);
        return;
    }
    find(root->ch[1], vec, index-1);
    find(root->ch[0], vec, index-1);
}

void ara(Node* &root, lint index = 40)
{
    if(root == nullptr) return;
    if(index < 0) 
    {
        return;
    }
    if(!root->ch[0])
    {
        ara(root->ch[1], index-1); 
    }
    else if(!root->ch[1])
    {
        ara(root->ch[0], index-1); 
    }
    else
    {
        vector<lint> ones;
        vector<lint> zeros;
        find(root->ch[0], zeros, index-1);
        find(root->ch[1], ones, index-1);
        for(auto o:ones)
        {
            for(auto z:zeros)
            {
                nax = min(nax, o^z);
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<lint> v(n);
    Node* root = new Node;

    INPUT(v);
    /// calc all number same

    
    bool flag = 1;
    for(int i = 1; i <n; i++ )
    {
        if(v[i]!=v[i-1])
        {
            flag = 0;
            break;
        }
    }

    if(flag) 
    {
        cout<<0;
        return 0;
    }
    lint suff = 0;
    for(int i = n-1; i >=0; i--)
    {
        add(root, v[i]);
    }
    ara(root);
    cout<<fixed<<nax;
    return 0;    
}