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
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
vector<lint> arr1;
vector<lint> arr2;
vector<lint> a1;
vector<lint> a2;

void fonk(int i, int n, lint total, int dahil, vector<lint> &a, vector<lint>& arr)
{
    if(i>=n)
    {
        //cout<<total<<" "<<dahil<<endl;
        if(dahil>0) a.pb(total);
        return;
    }
    fonk(i+1,n,total, dahil, a, arr);
    dahil++;
    fonk(i+1,n,total+arr[i], dahil, a, arr);

}
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        lint p;
        cin>>p;
        if(i<(n/2+1)) arr1.pb(p);
        else arr2.pb(p);
    }

    //for(int i=1;i<=n;i++) arr[i]+=arr[i-1];
    fonk(0, (n/2+1), 0, 0, a1, arr1);
    //cout <<" test " <<(n/2)-1<<" ";
    fonk(0, n-n/2-1, 0, 0, a2, arr2);

    lint minn = inf;

    sort(ALL(a2));
/*     
    FORE(arr1)
    {
        cout << a <<" arr1 ";
    }
        cout << "\n";
    FORE(arr2)
    {
        cout << a <<" arr2 ";
    }
        cout << "\n";
    FORE(a1)
    {
        cout << a <<" a1 ";
    }
        cout << "\n";
    FORE(a2)
    {
        cout << a <<" a2 ";
    }
 */
    FORE(a1)
    {
        auto x = lower_bound(ALL(a2), -1*a);

        if(x != a2.end()) minn = min(minn, abs((*x)+a));
        if(x != a2.begin()) minn = min(minn, abs(*(x-1)+a));
    }
    FORE(a1)
    {
        minn = min(minn, abs(a));
    }
    FORE(a2)
    {
        minn = min(minn, abs(a));
    }
    cout << minn;

    return 0;
}