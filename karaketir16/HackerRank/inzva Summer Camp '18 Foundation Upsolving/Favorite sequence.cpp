#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1000005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;
typedef long long int lint;
typedef pair<int,int> ii;
struct Node
{
    int in_count=-1;
    set<int> out;
};
vector<Node> nodes(N);
int main()
{
    //set<int> values;
    int t;
    cin>>t;
    for(int w=0;w<t;w++)
    {

        int k;
        cin>>k;
        vector<int> fnd(k);
        for(int o=0;o<k;o++)
        {
            cin>>fnd[o];
            //values.insert(-1*fnd[o]);
            //if(nodes[fnd[o]].in_count==-1)
            nodes[fnd[o]].in_count=0;
                

        }
        for(int i=0;i<k-1;i++)
        {
            
            {
                //cout<<"j testi :::"<<fnd[j]<<":::\n";
               // nodes[fnd[i]].out.insert(fnd[j]);
                int j=i+1;
                int x;
                int y;
                x=fnd[i];
                y=fnd[j];
                //cout<<x <<":"<<y<<endl;

                nodes[x].out.insert(y);


            }
        }
    }
    for(int i=0;i<N;i++)
    {
        if(nodes[i].in_count<0) continue;

        for(auto x:nodes[i].out)
        {
            nodes[x].in_count++;
        }
    }
    /*
    cout<<"TEST: "<<nodes[7].in_count;
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        if(nodes[i].in_count>=0) cout<<i<<": "<<nodes[i].in_count<<endl;
    }
    */
    priority_queue<int> pq;
    vector<int> result;
    for(int i=0;i<N;i++)
    {
        if(nodes[i].in_count==0)
        {
            //cout<<"pushlanan: "<<i<<endl;
            pq.push(-1*i);
            nodes[i].in_count=-1;
        }
    }
    while (pq.size()>0)
    {
        
        int temp=-1*pq.top();
        //cout<<"temp: "<<temp<<"\n";
        pq.pop();
        result.pb(temp);

        
        for(auto a: nodes[temp].out)
        {
            nodes[a].in_count--;
            if(nodes[a].in_count==0) 
            {
                pq.push(-1*a);
                nodes[a].in_count=-1;
            }
        }
        /*
        for(int i=0;i<N;i++)
        {
            
            if(nodes[i].in_count==0)
            {
                //cout<<"pushlanan: "<<i<<endl;
                pq.push(-1*i);
                nodes[i].in_count=-1;
            }
            
        }
        */
    } 

    for(auto a:result)
    {
        cout<<a<<" ";
    }
    
   
    return 0;
}