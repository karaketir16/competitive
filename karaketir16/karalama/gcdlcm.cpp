#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1000005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
lint fastPow(lint n, lint k)
{
    if(k==0) return 1;
    if(k==1) return n%MOD;
    lint temp=fastPow(n,k>>1)%MOD;
    if(k&1) return (temp*temp*n)%MOD;
    return (temp*temp)%MOD;
}

vector<bool> prime(N, true);

void prime_calc()
{
    prime[0] = prime[1] = 0;

    for(int i = 2; i * i <= N; i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j <= N; j+=i)
            {
                prime[j] = false;
            }
        }
    }
}

vector<lint> rs(lint a)
{
    vector<lint> res;
    lint i = 0; 
    while(a > 1)
    {
        lint temp=0;

        while(!prime[i]) i++;

        while(a % i == 0) temp++, a/=i;
        if(temp != 0) res.push_back(temp);
        i++;    
    }
    return res;
}


lint formul(lint number, lint n)
{
    auto rler = rs(number);

    lint res = 1;

    for(auto r: rler)
    {
        res = (res * (fastPow(r+1, n) - 2 * fastPow(r, n) + fastPow(r-1, n)))%MOD;
        //dbg(mod(fastPow(r+1, n) - 2 * fastPow(r, n) + fastPow(r-1, n)));
        //dbg(r);
    }
    //dbg(res);
    return res;
}
lint count(lint x, lint y, lint k)
{
    lint c  = y/k - x + 1; 
    //dbg(c);
    return c;
}
int main()
{
    prime_calc();
    std::ios::sync_with_stdio(false);
    lint x, y, n;
    cin >> x >> y >> n;

    lint result =0;
    for(lint k =1; count(x, y, k) > 0; k++)
    {
        result = (result + count(x, y, k) * formul(k, n))%MOD;
    } 

    cout<<(result >= 0 ? result : result+ MOD);
    return 0;
}