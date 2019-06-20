#include <bits/stdc++.h>
using namespace std;
#define BN 100005

class BigDecimalNumber
{
    public:
    vector<int> v;
    BigDecimalNumber()
    {

    }
    BigDecimalNumber(const vector<int>& x)
    {
        v = x;
    }
    BigDecimalNumber(long long a)
    {
        while(a > 0)
        {
            v.push_back(a%10);
            a/=10;
        }
    }   
    BigDecimalNumber operator*=(int a)
    {
        int sz = v.size();
        int elde = 0;
        for(int i = 0; i<sz;i++)
        {
            v[i]*=a;
            v[i] += elde;
            elde = v[i]/10;
            v[i] %= 10; 
        }
        while(elde>0)
        {
            v.push_back(elde%10);
            elde/=10;
        }
        return (*this);
    }


    void print()
    {
        for(int i = ((int)v.size()) - 1; i>=0; i--) cout<<v[i];
        cout<<endl;
    }

};



vector<int> sieve(BN, 1);
void setupSieve()
{
    sieve[0] = 0;
    sieve[1] = 1;
    for(int i = 2; i*i <= BN; i++)
    {
        if(sieve[i] == 1)
            for(int j = i*i; j <= BN; j+=i)
            {
                sieve[j] = i;
            }
    }
}
void cl(vector<int>& v)
{
    for(int i = ((int)v.size()) - 1; i>1; i--)
    {
        if(sieve[i] != 1)
        {
            v[sieve[i]] += v[i];
            v[i / sieve[i]] += v[i];
            v[i] = 0;
        }
    }
}
vector<int> operator+(vector<int>& a, vector<int>& b)
{
    vector<int> tmp;
    for(int i = 0; i < a.size(); i++ ) tmp.push_back(a[i] + b[i]);
    return tmp;
}
vector<int> operator-(vector<int>& a, vector<int>& b)
{
    vector<int> tmp;
    for(int i = 0; i < a.size(); i++ ) tmp.push_back(a[i] - b[i]);
    return tmp;
}
BigDecimalNumber res(int n)
{
    int k = n - 1;
    int a = (n-1)/2;
    int b = k - a;

    vector<int> kfac(k + 1, 1);
    vector<int> afac(a + 1, 1);
    vector<int> bfac(b + 1, 1);

    afac.resize(k+1); bfac.resize(k+1);

    cl(kfac); cl(afac); cl(bfac);
    auto res = afac + bfac;
    res = kfac - res;

    // for(int i = 0; i <= k; i++) cout<<i<<": "<<res[i]<<endl;
    BigDecimalNumber ans(1);
    for(int i = 2; i <= k; i++)
    {
        for(int j = 0; j<res[i]; j++)
            ans *= i;
    }
    return ans;
}
int main()
{
    setupSieve();
    int n;
    cin>>n;
    res(n).print();

    return 0;
}
