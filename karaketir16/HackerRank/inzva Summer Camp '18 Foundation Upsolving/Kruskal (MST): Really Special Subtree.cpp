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
    lint value=inf;
    vector<pair<lint,lint>> can_go;//weight, node
    bool inTree=0;

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
    priority_queue<pair<lint,lint>> pq;
    for(auto a: nodess[1].can_go)
    {
        pq.push(a);

    }
    nodess[1].inTree=1;
    lint total=0;
    while(pq.size()>0)
    {
        pair<lint,lint> temp=pq.top();
        pq.pop();
        if(nodess[temp.sc].inTree) continue;
        total+=temp.fi;

        nodess[temp.sc].inTree=1;
        for(auto a: nodess[temp.sc].can_go)
        {
            pq.push(a);

        }


    }
    cout<<-1*total;

    return 0;
}