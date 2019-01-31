#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
struct Node
{
    int nu;
    Node* l;
    Node* r;
};
void build(int a, Node* &node)
{
    if(node == 0)
    {
        node = new Node();
        node -> nu = a;
    }
    else
    {
        build(a, a > node->nu ? node->r : node->l );
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    Node* root = NULL;

    int n;
    cin >> n;
    while(n--)
    {
        int a;
        cin>> a;
        build(a, root);
    }
    vector<int> left;
    vector<int> right;
    vector<int> result;

    Node* tmp = root;
    while(tmp)
    {
        left.pb(tmp->nu);
        tmp = tmp->l;
        //cout<<"test";
    }
    tmp = root;
    while(tmp)
    {
        right.pb(tmp->nu);
        tmp = tmp->r;
    }
    reverse(ALL(left));
    for(int i = 0; i<left.size()-1; i++) cout<<left[i]<<" ";
    //cout << endl;
    for(int i = 0; i<right.size(); i++) cout<<right[i]<<" ";

    return 0;
}