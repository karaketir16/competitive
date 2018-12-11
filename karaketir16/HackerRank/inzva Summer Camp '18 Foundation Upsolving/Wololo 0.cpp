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
    lint value=0;
    int bas;
    int son;
    lint lazy=0;
};
vector<Node> arr;

lint add_lazy(int a,int b,int no,int x)
{
    /*
    cout<<endl;
    cout<<"a: "<<a<<" b: "<<b<<" no: "<<no<<" x: "<<x<<endl;
    */
    if(a==arr[no].bas&&b==arr[no].son)
    {

        arr[no].lazy+=x;
        return x*(b-a+1);
    }

    /*
    if(b<arr[no].bas||a>arr[no].son)
    {
        return 0;
    }
    */
    int c1b=arr[2*no].bas;
    int c1s=arr[2*no].son;
    int c2b=arr[2*no+1].bas;
    int c2s=arr[2*no+1].son;
    lint gelen;
    if(a<=c1s&&b<=c1s)
    {
        gelen=add_lazy(a,b,2*no,x);//ikisini de ilk childa
    }
    else if(a>=c2b&&b>=c2b)
    {
        gelen=add_lazy(a,b,2*no+1,x);//ikisi de ikinci childa
    }
    else
    {
        gelen=add_lazy(a,c1s,2*no,x) + add_lazy(c2b,b,2*no+1,x);
    }
    
    //=add_lazy(arr[2*no].son,a,2*no,x)+add_lazy(b,arr[2*no+1].bas,2*no+1,x);;
    arr[no].value+=gelen;
    return gelen;
    
}
lint calculate(int a,int b,int no)
{
    /*
    if(b<arr[no].bas||a>arr[no].son)
    {
        return 0;
    }
    */
    arr[no].value+=arr[no].lazy*(arr[no].son-arr[no].bas+1);
    arr[2*no].lazy+=arr[no].lazy;
    arr[2*no+1].lazy+=arr[no].lazy;
    arr[no].lazy=0;
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
    
    /*
    cout<<endl;
    for(int i=1;i<2*size;i++)
    {
        cout<<i<<": "<<arr[i].value<<" : bas: "<<arr[i].bas<<" son: "<<arr[i].son<<" lazy: "<<arr[i].lazy<<endl;
    }
    */


    return 0;
}