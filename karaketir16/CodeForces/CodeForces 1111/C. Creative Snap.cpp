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
using namespace std;
typedef long long int lint;


map<lint, lint> aves;
std::vector<lint> avs; 
lint n, k, A, B;
pair<lint, lint> dp(lint l, lint r) //min, tot aven
{
    pair<lint, lint> res;
    if(l == r) 
    {
        res.first = aves.count(l) > 0 ? aves[l] * B : A;
        res.second = aves[l];
        return res;
    }
    if (upper_bound(ALL(avs), r) - lower_bound(ALL(avs),l) <= 0)
    {
        res.first = A;
        res.second =0;
        return res;    
    }
    auto ll =  dp(l, mid(l, r));
    auto rr =  dp(mid(l, r)+1, r);
    lint totaven = ll.second+rr.second;
    res.first = totaven > 0 ? totaven * B * (r - l + 1) : A;
    res.first = min(res.first, ll.first + rr.first);
    res.second = totaven;
    // dbg(l);
    // dbg(r);
    // dbg(totaven);
    // lint dbg = (mem[{l, r}].first);
    // dbg(dbg);
    return res;
}
int main()
{
    std::ios::sync_with_stdio(false);

    cin >>n>>k>>A>>B;
    FOR0(k)
    {
        lint a;
        cin>>a;
        aves[a]++;
        avs.pb(a);
    }
    sort(ALL(avs));
    // lint onceki = 0;
    // aves[0] = 0;
    // FORE(aves)
    // {
    //     a.second += onceki;
    //     onceki = a.second;
    // }
    auto res = dp(1, pow(2, n));
    cout.setf(ios::fixed);
    cout << setprecision(0) <<res.first;
	return 0;
}
