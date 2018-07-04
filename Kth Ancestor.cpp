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
    vector<ii> sorgular;
    set<int> children;
    int parent=-1;
};
vector<int> resultss;
vector<Node> nodess;
int total_girilen_node=0;
void dfs(vector<int> way, int node)
{
    total_girilen_node++;
    way.pb(node);
    int last=way.size()-1;
    for(auto x:nodess[node].sorgular)
    {
        if(last-x.sc<0)
        {
            resultss[x.fi]=0;
            //cout<<x.fi<<". result: "<<0<<endl;
        }
        
        else
        {
            resultss[x.fi]=way[last-x.sc];
            //cout<<x.fi<<". result: "<<way[last-x.sc]<<endl;
        }
        
        
    }
    for(auto c:nodess[node].children)
    {
        dfs(way,c);
    }
}
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        
        int p;
        int root;
        vector<Node> nodes(N);
        cin>>p;
        for(int i=0;i<p;i++)
        {
            int child;
            int parent;
            cin>>child;
            cin>>parent;
            nodes[parent].children.insert(child);
            nodes[child].parent=parent;
            if(parent==0) root=child;
            //cout<<"alindi\n";
        }
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
                    nodes[child].parent=parent;
                    nodes[parent].children.insert(child);

                    break;
                case 1:
                    cin>>child;
                    nodes[nodes[child].parent].children.erase(nodes[nodes[child].parent].children.find(child));
                    nodes[child].parent=-1;
                    
                    break;

                case 2:
                    cin>>child;
                    int k;
                    cin>>k;
                    nodes[child].sorgular.pb(MP(quer,k));
                    quer++;

                    break;    
                default:
                    break;
            }
            //cout<<"alindi\n";
        }
        vector<int> results(quer,0);

        vector<int> parents_way;
        nodess=nodes;
        resultss=results;
        dfs(parents_way,root);
        //sort(resultss.begin(),resultss.end());
        for(auto x:resultss)
        {
            cout<<x<<"\n";
        }


    }
    cout<<endl<<endl<<total_girilen_node;

    return 0;
}