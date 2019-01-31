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

int main()
{
    std::ios::sync_with_stdio(false);
    lint n, m, k;
    cin>>n>>m>>k;
    vector<lint> numbers(n);
    
    
    INPUT(numbers);

    vector<lint> prefix = numbers;
    for(int i = 1; i<n;i++)
    {  
        prefix[i] += prefix[i-1]; 
    }
    stack<pair<lint, lint>> stc; //nu, index
    vector<pair<lint, lint>> water(n, {0, 0}); //0 index;  seviye, end 
    vector<char> se(n); //start or end
    FOR0(n)
    {
        lint nu = numbers[i];
        if(nu == 0) continue;
        //cout<<"s "<<stc.size()<<" ";
        lint maxx = 0;
        lint maxxi = -1;
        while(!stc.empty() && stc.top().first <= nu)
        {
            int nw = stc.top().first;
            //cout<<nu<<' '<<nw<<"\n";
            if(nw >= maxx)
            {
                maxx = nw;
                maxxi = stc.top().second;
            }
            stc.pop();
        }
        if(stc.empty() && maxxi == -1) // uygun yok
        {
            stc.push({nu, i});
            continue;
        }
        //cout<<"test "<<i<<" t ";
        lint nw, ind;
        if(!stc.empty())
        {
            nw = stc.top().first;
            ind = stc.top().second;
        }
        else
        {
            nw = maxx;
            ind = maxxi;
        }

        if(i - ind > 1) // bosluk varsa
        {
            water[ind+1] = {min(nw, nu), i};
            //cout<<ind<<" "<<i<<" \n";

        }

        stc.push({nu, i});
    }
    lint tot = 0;
    for(int i = 0; i<n; i++)
    {
        if(water[i].first!=0)
        {
            lint s = i, e = water[i].second, h = water[i].first;

            tot+=((e - s)*h - (prefix[e-1]-prefix[s-1]));
            
            i = e;
            //cout<<"pf "<<prefix[e-1]<<" "<<prefix[s-1]<<" \n";
        }
    }
    printf("%lld", tot*m*k);
  /*   cout<<"\n\n";
    FORE(water)
    {
        cout<<a.first <<" "<<a.second<<"\n";
    } */
    return 0;
}