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
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
#define bit(number,i) ((number>>i)&1)
using namespace std;
typedef long long int lint;
int main()
{
    std::ios::sync_with_stdio(false);
    lint t;
    cin>>t;
    while(t--)
    {
        lint n;
        cin>>n;
        if(n<=3)
        {
            lint a, b, c;
            cin>>a>>b>>c;
            cout<<fixed<<a+b+c<<"\n";
            continue;
        }
        vector<lint> v(n);
        INPUT(v);

        vector<lint> sufSum(n);
        sufSum[n-1] = v.back();
        lint temp = v.back();
        for(int i = n-2; i >=0; i--){
            temp+=v[i];
            sufSum[i] = temp;
        }

        vector<lint> best(n);
        best[n-1] = sufSum[n-1];
        best[n-2] = sufSum[n-2];
        best[n-3] = sufSum[n-3];

        for(int i = n-4; i >=0; i--){
            best[i] = max3( v[i]+sufSum[i+1]-best[i+1] , v[i]+v[i+1]+sufSum[i+2]-best[i+2]  , v[i]+v[i+1]+v[i+2]+sufSum[i+3]-best[i+3]  );
        }
        
        cout<<fixed<<best[0]<<"\n";
    }

    return 0;    
}

