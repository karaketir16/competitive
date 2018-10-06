#include <bits/stdc++.h>
#include <iostream>

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
#define orta ((a+b)/2)
using namespace std;
#define pp pair<int,int>

typedef long long int lint;
// limit for array size
const int N = 100000; 
 
int n; // array size
 
// Max size of tree
int tree[2 * N];
 
// function to build the tree
void build( int arr[]) 
{ 
    // insert leaf nodes in tree
    for (int i=0; i<n; i++)    
        tree[n+i] = arr[i];
     
    // build the tree by calculating parents
    for (int i = n - 1; i > 0; --i)     
        tree[i] = tree[i<<1] + tree[i<<1 | 1];    
}
 
// function to update a tree node
void updateTreeNode(int p, int value) 
{ 
    // set value at position p
    tree[p+n] = value;
    p = p+n;
     
    // move upward and update parents
    for (int i=p; i > 1; i >>= 1)
        tree[i>>1] = tree[i] + tree[i^1];
}
 
// function to get sum on interval [l, r)
int query(vector<int> &tree,
        vector<int> &indexes,
        vector<pair<int,int>> &fls, 
        int l, int r) 
{
    
}
 
// driver program to test the above function 
int main() 
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double k=log(n)/log(2);
        int ik=k;
        if(ik!=k)
        {
            ik++;
        }
        ik=1<<ik;
        sz=ik*2;
        
        vector<int> tree(sz,0);
        vector<int> indexes(sz);
        vector<pair<int,int>> fls(sz);

        for(int i=ik;i<sz;i++)
        {
            indexes[i]=i;
            fls.pb(MP(ik-i,ik-i));
        }
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            tree[i+ik]=x;
        }
        for (int i = ik - 1; i > 0; i--)
        {
            fls.pb(MP(fls[2*i].fi,fls[2*i+1].sc));
            if(tree[2*i]>tree[2*i+1])
            {
                tree[i] =tree[i*2];
                indexes[i]=indexes[2*i];  
            }
            else
            {
                tree[i] = tree[i*2+1];
                indexes[i] = indexes[2*i+1];  
            }
        }

            


    }
 
    return 0;
}
