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
#define LN 20
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;
typedef long long int lint;
typedef pair<int,int> ii;
struct Node
{
    
    set<int> children;
    int parent=0;
    //int parent=0;
    bool in_tree=0;
};
vector<int> resultss;
vector<Node> nodess;
vector<vector<int>> tablee;
int hesap(int node,int xth)
{
    int temp=node;
    //tablee[0][temp]=nodess[temp].parent;
    for(int i=0;i<LN;i++)
    {
        if((1<<i)&xth)
        {
            temp=tablee[i][temp];
        }
    }
    return temp;
}
void table_doldur(int node)
{
    //cout<<"TEST";
    tablee[0][node] = nodess[node].parent;
    //cout<<"parent:: "<<nodess[node].parent<<"::";
    for(int i=1;i<LN; i++)
    {
        tablee[i][node] = tablee[i-1][tablee[i-1][node]];
    }
    
 
    for(auto x: nodess[node].children)

    {
        table_doldur(x);
    }
}

void print_tree(int root)
{
    cout<<root<<"'s childs: ";
    for(auto x:nodess[root].children)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto x:nodess[root].children)
    {
        print_tree(x);
    }
}
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        vector<int> row(N,0);
        vector<vector<int>> table(LN,row);//log_nxn
        vector<Node> nodes(N);
        nodess=nodes;

        tablee=table;
        int p;
        int root;
        
        cin>>p;
                

        for(int i=0;i<p;i++)
        {
            //cout<<"TEST";
            int child;
            int parent;
            cin>>child;
            cin>>parent;
            nodess[parent].children.insert(child);
            nodess[child].parent=parent;
            if(parent==0)
            { 
                root=child;
            }
            nodess[child].in_tree=1;
        }
        table_doldur(root);

        int q;
        cin>>q;
        int quer=0;
        while(q--)
        {
            int x;
            cin>>x;
            int child;
            switch (x)
            {
                case 0:
                    int parent;
                    child;
                    cin>>parent;
                    cin>>child;
                    nodess[child].parent=parent;
                    nodess[parent].children.insert(child);
                    nodess[child].in_tree=1;
                    table_doldur(child);
                    break;
                case 1:
                    cin>>child;
                    nodess[child].in_tree=0;
                    nodess[nodess[child].parent].children.erase(nodess[nodess[child].parent].children.find(child));
                    break;

                case 2:
                    cin>>child;
                    int k;
                    cin>>k;
                    //sorgular.pb(MP(nodess[child].in_tree,MP(child,k)));
                    if(nodess[child].in_tree)
                    {
                        int x = hesap(child,k);
                        cout<<x<<"\n";
                    }
                    else
                    {
                        cout<<0<<"\n";

                    }

                    break;    
                default:
                    break;
            }
            //cout<<"alindi\n";
        }



    }
    //cout<<endl<<endl<<total_girilen_node;

    return 0;
}
