#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 50005
#define MOD 1000000007LL
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &e:v)
#define bit(number,i) ((number>>i)&1)
using namespace std;
typedef long long int lint;

std::vector<vector<lint>> Sgt(128, vector<lint> (4*N));
std::vector<lint> v;
lint pow2[] = {1, 2 , 4, 8, 16, 32, 64, 128};

void addTree(lint, lint, lint);
lint getTree(lint, lint);


// Returns sum of arr[0..index]. This function assumes 
// that the array is preprocessed and partial sums of 
// array elements are stored in BITree[]. 
lint getSum(vector<lint> &BITree, lint index) 
{ 
    lint sum = 0; // Iniialize result 

    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 

    // Traverse ancestors of BITree[index] 
    while (index>0) 
    { 
        // Add current element of BITree to sum 
        sum = (sum + BITree[index]) %MOD; 

        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 

// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree. The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree. 
void updateBIT(vector<lint> &BITree, lint n, lint index, lint val) 
{ 
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 

    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
    // Add 'val' to current node of BI Tree 
    BITree[index] = (BITree[index] + val)%MOD; 

    // Update index to that of parent in update View 
    index += index & (-index); 
    } 
} 



void addTree(vector<lint> &tree, lint x, lint val)
{
    //update(tree, 1, 1, N, val, x);
    updateBIT(tree, N, x, val);
}

lint getTree(vector<lint> &tree, lint a)
{
    //return query(tree, 1, 1, N, 1, a );
    return getSum(tree, a);
}

void calcNum(lint a, lint b, lint k)
{
    for(lint i = pow2[k]-1; i >= 0; i--)
    {
        if(bit(i, b))
        {
            addTree( Sgt[i], a, getTree(Sgt[i], a - 1) );
        }
        else
        {
            addTree(Sgt[i + pow2[b]], a, getTree(Sgt[i], a - 1));    
        }   
    }
    addTree(Sgt[pow2[b]], a, 1);
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
        lint b;
        cin>>b;
        b--;
        //cerr<<n<<<<endl;
        calcNum(a, b, k);

    }


    cout<< getTree(Sgt[pow2[k]-1], N)%MOD;

    return 0;    
}
/*
4 3
1 1
3 2
2 2
4 3
*/