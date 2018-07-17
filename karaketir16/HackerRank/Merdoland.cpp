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
struct Minq
{
    lint value=inf;
    int bas;
    int son;


};
struct Node
{
    vector<pair<int,int>> can_go;//weight, node
    bool visited=0;

};
vector<ii> tta;

void dfs(vector<Node> &nodes, int node, int dept)
{
    cout <<"test: "<<node<<" "<<dept<<endl;
    tta.pb(MP(node,dept));
    nodes[node].visited=1;
    for(auto a: nodes[node].can_go)
    {
        if(nodes[a.sc].visited) continue;
        dfs(nodes,a.sc,dept+1);
        tta.pb(MP(node, dept));
    }

}
lint calculate(vector<Minq> &arr,int a,int b,int no)
{

    if(a==arr[no].bas&&b==arr[no].son)
    {
        return arr[no].value;
    }
    
    
    int c1b=arr[2*no].bas;
    int c1s=arr[2*no].son;
    int c2b=arr[2*no+1].bas;
    int c2s=arr[2*no+1].son;
    if(a<=c1s&&b<=c1s)
    {
        return calculate(arr,a,b,2*no);//ikisini de ilk childa
    }
    else if(a>=c2b&&b>=c2b)
    {
        return calculate(arr,a,b,2*no+1);//ikisi de ikinci childa
    }
    else
    {
        return min(calculate(arr,a,c1s,2*no),calculate(arr,c2b,b,2*no+1));
    }

}
int main()
{
    
    int n;
    cin>>n;

    vector<Node> nodes(n+1);

    for(int i=0;i<n-1;i++)
    {
        int f;
        int s;
        int d;

        cin>>f;
        cin>>s;
        cin>>d;
        nodes[f].can_go.pb(MP(d,s));
        nodes[s].can_go.pb(MP(d,f));

    }
    dfs(nodes, 1, 1);
    double logn=(log(tta.size())/log(2));
    int LN = logn;
    if(logn!=LN) LN++;
    int size=pow(2,LN);
    vector<Minq> arr(4*size);
    for(int i=0;i<4*size;i++)
    {
        arr[i].bas=i;
        arr[i].son=i;
    }
    int n_for_loop=tta.size();
    for(int i=size,j=0;n_for_loop;i++,n_for_loop--,j++)
    {    
        arr[i].value=tta[j].sc;
    }
    for(int i=2*size-1;i>0;i-=2)
    {
        arr[i/2].value=min(arr[i].value,arr[i-1].value);
        arr[i/2].bas=arr[i-1].bas;
        arr[i/2].son=arr[i].son;
    }
    for(auto a:tta)
    {
        cout<<a.fi<<" ";
    }
    cout<<endl;
    for(auto a:tta)
    {
        cout<<a.sc<<" ";
    }
    cout<<endl;
    for(int i=1;i<2*size;i++)
    {
        cout<<i<<": "<<arr[i].value<<" : bas: "<<arr[i].bas<<" son: "<<arr[i].son<<endl;
    }
    cout<<calculate(arr,3+size-1,6+size-1,1)<<"\n";
    

    
    return 0;
}
/*


typedef long long int lint;
struct Node
{
    lint value=0;
    int bas;
    int son;
    lint lazy=0;
};
vector<Node> arr;


lint calculate(int a,int b,int no)
{

    if(a==arr[no].bas&&b==arr[no].son)
    {
        return arr[no].value;
    }
    
    
    int c1b=arr[2*no].bas;
    int c1s=arr[2*no].son;
    int c2b=arr[2*no+1].bas;
    int c2s=arr[2*no+1].son;
    if(a<=c1s&&b<=c1s)
    {
        return calculate(a,b,2*no);//ikisini de ilk childa
    }
    else if(a>=c2b&&b>=c2b)
    {
        return calculate(a,b,2*no+1);//ikisi de ikinci childa
    }
    else
    {
        return calculate(a,c1s,2*no) + calculate(c2b,b,2*no+1);
    }   


    //return calculate(a,arr[2*no].son,2*no)+calculate(arr[2*no+1].bas,b,2*no+1);
    
}
int main()
{
    int n,q;
    cin>>n>>q;
    double logn=(log(n)/log(2));
    int LN = logn;
    if(logn!=LN) LN++;
    int size=pow(2,LN);
    //cout<<size;

    vector<Node> temp(4*size);
    arr=temp;
    for(int i=0;i<4*size;i++)
    {
        arr[i].bas=i;
        arr[i].son=i;
    }
    int n_for_loop=n;
    for(int i=size;n_for_loop;i++,n_for_loop--)
    {    
        cin>>arr[i].value;
    }

    for(int i=2*size-1;i>0;i-=2)
    {
        arr[i/2].value=arr[i].value+arr[i-1].value;
        arr[i/2].bas=arr[i-1].bas;
        arr[i/2].son=arr[i].son;
    }
    //add_lazy(10,12,1,2);
    while(q--)
    {
        int e;
        cin>>e;
        
        switch (e)
        {
            int L;
            int R;

            case 1:
                cin>>L;
                cin>>R;
                int v;
                cin>>v;
                add_lazy(L+size-1,R+size-1,1,v);
                break;
            case 2:
                cin>>L;
                cin>>R;
                cout<<calculate(L+size-1,R+size-1,1)<<"\n";

                break;
            default:
                break;
        }
        
        
    }
    



    return 0;
}

*/