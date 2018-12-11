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

    }
    set<lint> use;
    for(int i=0;i<m;i++)
    {
        lint a;
        cin>>a;
        use.insert(a);
    }
    vector<Node> nodess = nodes;
    stack<lint> stck=stckk;
    stck.push(1);
    lint maxx=0;
    lint maxx_i=0;
    while(stck.size()>0)
    {
        
        lint current = stck.top();
        stck.pop();
        nodess[current].is_visited=1;
        //cout<<"current: "<<current<<" value: "<<nodess[current].value;
        if(use.find(current)!=use.end()) 
        {
            //cout<<current;
            //maxx=max(nodess[current].value,maxx);
            if(nodess[current].value>maxx)
            {
                maxx=nodess[current].value;
                maxx_i=current;
            }
            
        }
        
        for(auto a:nodess[current].can_go)
        {
            
            
            if(nodess[a.sc].is_visited) continue;
            nodess[a.sc].value=nodess[current].value+1;
            //cout<<"TEST";
            stck.push(a.sc);


        }
        
    }
    //cout<<"ilk max: "<<maxx_i;
    nodess = nodes;
    stck=stckk;
    stck.push(maxx_i);
    maxx=0;
    maxx_i=0;
     while(stck.size()>0)
    {
        
        lint current = stck.top();
        stck.pop();
        nodess[current].is_visited=1;
        //cout<<"current: "<<current<<" value: "<<nodess[current].value;
        if(use.find(current)!=use.end()) 
        {
            //cout<<current;
            //maxx=max(nodess[current].value,maxx);
            if(nodess[current].value>maxx)
            {
                maxx=nodess[current].value;
                maxx_i=current;
            }
            
        }
        
        for(auto a:nodess[current].can_go)
        {
            
            
            if(nodess[a.sc].is_visited) continue;
            nodess[a.sc].value=nodess[current].value+1;
            //cout<<"TEST";
            stck.push(a.sc);


        }
        
    }
    cout<<maxx;



    return 0;
}