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
vector<lint> results;
lint gcd(lint a, lint b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}
void fonk(int i, vector<lint> &v, lint x, int sayi)
{
    if(i==v.size())
    {
        if(x!=-1&&sayi>1)results.pb(x);
        return;
    }
    fonk(i+1, v, x, sayi);
    if(x!=-1) fonk(i+1, v, gcd(x, v[i]), sayi+1);
    else fonk(i+1, v, v[i], sayi+1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        results.clear();
        
        int n;
        cin>>n;
        vector<lint> v(n);
        for(int i =0;i<n;i++)
        {
            scanf("%lld", &v[i]);
        }
        fonk(0, v, -1, 0);
        sort(results.begin(), results.end());
        for(lint x: results)
        {
            printf("%lld ", x);
        }
        if(t!=0) printf("\n--\n");
    }
    return 0;
}