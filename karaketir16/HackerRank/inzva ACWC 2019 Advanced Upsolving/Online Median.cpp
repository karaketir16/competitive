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
int main()
{
    std::ios::sync_with_stdio(false);
    priority_queue<lint> max_h;
    priority_queue<lint, vector<lint>, greater<lint>> min_h; 
    int n;
    cin>>n;
    for(int i = 1;  i<=n;i++)
    {
        lint x;
        cin>>x;

        i&1 ? max_h.push(x) : min_h.push(x);

        if(i > 1&& max_h.top() > min_h.top())
        {
            lint a = min_h.top();
            lint b = max_h.top();
            min_h.pop();
            max_h.pop();
            min_h.push(b), max_h.push(a);
        }

        cout<<(i&1 ? max_h.top() : mid(min_h.top(), max_h.top()))<<'\n';
    }
    return 0;
}