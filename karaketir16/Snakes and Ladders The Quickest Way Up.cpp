#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	100000000
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
    int value=inf;
    vector<pair<int,int>> can_go;//node, weight

};
// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    //cout<<"TEST";
    vector<Node> nodes(101);
    
    for(int i=1;i<101;i++)
    {
        for(int j=1;j<7;j++)
        {
            if(i+j<=100)
            {
                nodes[i].can_go.pb(MP(j+i,1));
            }
        }
    }
    
    vector<pair<int,int>> bos;
    for(auto s: snakes)
    {
        nodes[s[0]].can_go=bos;
        nodes[s[0]].can_go.pb(MP(s[1],0));

    }
    for(auto l:ladders)
    {
        nodes[l[0]].can_go=bos;
        nodes[l[0]].can_go.pb(MP(l[1],0));
    }
    /*
    for(int i=1;i<101;nodes)
    {
        cout<<""
    }
    */
    queue<int> qu;
    nodes[1].value=0;
    qu.push(1);
    while(qu.size()>0)
    {
        Node current = nodes[qu.front()];
        vector<pair<int,int>> temp = current.can_go;
        for(auto a:temp)
        {
            int calc=current.value+a.sc;
            if(calc<nodes[a.fi].value)
            {                   ////guncelle kuyruga ekle
                nodes[a.fi].value=calc;
                qu.push(a.fi);
            }
        }
        qu.pop();
        //cout<<"t";

    }
    if(nodes[100].value==inf) return -1;
    return nodes[100].value;




}

int main()
{
    
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        //cout<<"t";
        int n;
        cin>>n;
        vector<vector<int>> ladders;
        for(int j=0;j<n;j++)
        {
            
            int f;
            int s;
            cin>>f;
            cin>>s;
            vector<int> temp;
            temp.pb(f);
            temp.pb(s);
            ladders.pb(temp);
        }
        int m;
        cin>>m;
        vector<vector<int>> snakes;
        for(int j=0;j<m;j++)
        {
            
            int f;
            int s;
            cin>>f;
            cin>>s;
            vector<int> temp;
            temp.pb(f);
            temp.pb(s);
            snakes.pb(temp);
        }
        //cout<<"t";
        cout<<quickestWayUp(ladders,snakes)<<"\n";
    }

    return 0;
}
