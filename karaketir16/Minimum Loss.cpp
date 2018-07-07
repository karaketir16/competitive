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
    lint value;
    vector<lint> childs;

};
vector<Node> tree;
lint fonk(lint x,lint current)
{
    if(x>=tree[current].value)
    {
        return 0;
    }
    lint total=0;
    for(auto a:tree[current].childs)
    {
        lint t=0;
        t= fonk(x,a);
        total+=t;

        
    }
    if(total==0)
    {
        Node new_node;
        new_node.value=x;
        tree.pb(new_node);
        tree[current].childs.pb(tree.size()-1);
        total++;
    }

    return total;

}
lint minn=inf;
void calculate(lint current)
{
    for(auto c:tree[current].childs)
    {
        minn=min(minn,tree[current].value-tree[c].value);
        calculate(c);
    }

}
int main()
{
    int n;
    cin>>n;
    //vector<Node> temp(1);
    Node q;
    q.value=inf;
    tree.pb(q);
    //trees.pb(temp);

    for(int i=0;i<n;i++)
    {
        lint x;
        cin>>x;
        lint t=fonk(x,0);


    }
    calculate(0);
    cout<<minn;
    /*
    for(auto b:tree)
    {
        cout<<"value: "<<b.value<<" childs: ";

        for(auto a: b.childs)
        {
            cout<<tree[a].value<<" ";
        }
        cout<<endl;

    }
    */
    

}
/*
7
20 7 8 2 5 3 4

*/
