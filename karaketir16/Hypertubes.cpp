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
using namespace std;
typedef long long int lint;
struct Node
{
    bool is_visited=0;
    lint value=inf;
    set<pair<int,int>> can_go;//node, weight

};

int main()
{
    int n,k,m;

    cin>>n>>k>>m;
    vector<Node> stations(n+1);
    for(int i=0;i<m;i++)
    {
        vector<int> hyptup;
        for(int j=0;j<k;j++)
        {
            int x;
            cin>>x;
            hyptup.pb(x);

        }
        for(int j=0;j<k-1;j++)
        {
            for(int l=j+1;l<k;l++)
            {

                stations[hyptup[j]].can_go.insert(MP(hyptup[l],1));
                stations[hyptup[l]].can_go.insert(MP(hyptup[j],1));
            }
        }
    }
    /*
    for(int i=1;i<n+1;i++)
    {
        cout<<i<<": ";
        for(auto a: stations[i].can_go)
        {
            cout<<a.fi<<" ";
        }
        cout<<endl;
    }
    */
    //return 0;
    
    //cout<<"test";
    /*
    int adim =0;
    queue<int> siradakiler;
    siradakiler.push(1);
    stations[1].is_visited=1;
    */

    priority_queue<int> qu;
    stations[1].value=0;
    qu.push(-1);
    while(qu.size()>0)
    {
        //cout<<"test"<<-1*qu.top()<<endl;
        if(-1*qu.top()==n) break;
        //cout<<"asd";
        Node current = stations[-1*qu.top()];
        stations[-1*qu.top()].is_visited=1;
        qu.pop();
        set<pair<int,int>> temp = current.can_go;
        for(auto a:temp)
        {
            if(current.is_visited) continue;
            int calc=current.value+a.sc;
            //if(calc<nodes[a.fi].value)
            //{                   ////guncelle kuyruga ekle
            stations[a.fi].value=calc;
            if(a.fi==n)
            {
                cout<<stations[a.fi].value;

                return 0;
            }
            qu.push(-1*a.fi);
            //}
        }
       
        //cout<<"t";

    }
    if(stations[n].value==inf) cout<<-1;
    cout<<stations[n].value;

    return 0;
    

    


}
/*


struct Node
{
    //lint uzaklik=0;
    lint value=0;
    bool is_visited =0;
    vector<pair<lint, lint>> can_go;//weight, node_no

};


int main()
{
    stack<lint> stckk;
    int n,m;
    cin>>n>>m;
    vector<Node> nodes(n+1);
    for(int i=0;i<n-1;i++)
    {
        int f;
        int s;
        int d;

        cin>>f;
        cin>>s;

        nodes[f].can_go.pb(MP(1,s));
        nodes[s].can_go.pb(MP(1,f));
*/