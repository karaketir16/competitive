#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;
typedef long long int lint;
lint ans=0;
vector<lint> v;
queue<lint> merge_sort(lint bas, lint son)
{
    queue<lint> temp;
    if(bas==son)
    {
        temp.push(v[bas]);
        return temp;
    }
    lint mid= (bas+son)/2;
    queue<lint> sol = merge_sort(bas, mid);
    queue<lint> sag = merge_sort(mid+1, son);
    auto sag_cp = sag;
    auto sol_cp = sol;
    while((!sol.empty()&&(!sag.empty())))
    {
        if(sol.front()<=sag.front())//sag buyukse //soldan koy
        {

            temp.push(sol.front());
            sol.pop();

        }
        else                        //sol buyukse //sagdan koy
        {
            temp.push(sag.front());
            sag.pop();
        }
    }
    if(sol.size()>0)
    {
        while(!sol.empty())
        {
            temp.push(sol.front());
            sol.pop();
        }
    }
    if(sag.size()>0)
    {
        while(!sag.empty())
        {
            temp.push(sag.front());
            sag.pop();
        }
    }

    ////////////////////
    //queue<lint> temp_cp;
    while((!sol_cp.empty()&&(!sag_cp.empty())))
    {
        if(sol_cp.front()<=sag_cp.front()*2)//sag buyukse //soldan koy
        {

            //temp.push(sol.front());
            sol_cp.pop();

        }
        else                        //sol buyukse //sagdan koy
        {
            //temp.push(sag.front());
            sag_cp.pop();
            ans+=sol_cp.size();
        }
    }
    return temp;
}
int main()
{
    int n;
    cin>>n;
    if(n==0) 
    {
        cout<<1;
        return 0;
    }
    v = vector<lint> (n);
    for(int i = 0;i<n;i++)
    {
        scanf("%lld", &v[i]);
    }

    auto x = merge_sort(0, n-1);
    /*
    while(!x.empty())
    {
        cout<<x.front()<<endl;
        x.pop();
    }
    */
    cout<<ans+1;
    return 0;

}