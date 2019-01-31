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
struct Triple
{
    lint first;
    lint second;
    lint third;
};
struct Node
{
    lint value=inf;
    bool is_visited =0;
    vector<pair<lint, lint>> can_go;//weight, node_no

};


int main()
{
    
    int n,m;
    cin>>n>>m;
    vector<Node> nodess(n+1);
    for(int i=0;i<m;i++)
    {
        int f;
        int s;
        int d;

        cin>>f;
        cin>>s;
        cin>>d;
        nodess[f].can_go.pb(MP(-d,s));
        nodess[s].can_go.pb(MP(-d,f));

    }

    priority_queue<pair<lint, lint>> pq;
    nodess[1].value=0;
    lint minn;
    pq.push(MP(0,1));
    while(pq.size()>0)
    {
        
        minn=min(minn,pq.top().fi);
            //cout<<" 1: "<<pq.top().fi<<" 2: "<<pq.top().sc<<"\n";
        lint current = pq.top().sc;
        if(current==n)
        {
            
            cout<<-1*(minn);
            return 0;

        }
        Node temp=nodess[current];
        pq.pop();
        if(temp.is_visited) continue;
        else nodess[current].is_visited=1;
        //cout<<"current value: "<<temp.value<<" ";
        for(auto a: temp.can_go)
        {
            if(nodess[a.sc].is_visited) continue;
            pq.push(MP(a.fi,a.sc));
        }
    }
    cout<<"NO PATH EXISTS";

    return 0;
}
