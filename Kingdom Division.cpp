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
using namespace std;
typedef long long int lint;
typedef pair<int,int> ii;
struct Node
{
    //lint value=inf;
    lint value;
    set<int> childs;//node
    bool is_visited=0;
    //bool inTree=0;

};

int main()
{
    int n;
    cin>>n;
    vector<Node> nodes(n+1);
    for(int i=1;i<n;i++)
    {
        int x;
        int y;
        cin>>x;
        cin>>y;
        nodes[x].childs.insert(y);

    }
    int total_leaf=0;
    for(int i=1;i<n+1;i++)
    {
        //cout<<i<< " has "<<nodes[i].childs.size()<<endl;
        if(nodes[i].childs.size()==0) total_leaf++; 

    }
    int l=total_leaf;
    cout<<pow(2,n-1-l)*2;
    return 0;
}