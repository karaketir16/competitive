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
#define orta ((a+b)/2)
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long int lint;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    lint total=0;
    cin>>n;
    vector<int> v(n);
    for(auto &x:v) cin>>x;
    sort(ALL(v));
    vector<int> numbers(8005);
    for(auto &x:v) numbers[x]++;
    for(int i = 0; i+1<n;i++)
    {
        if(v[i]==v[i+1])
        {
            for(int j = v[i];true;j++)
            {
                if(!numbers[j])
                {
                    total+=(j-v[i]);
                    v[i]=j;
                    numbers[j]++;
                    break;
                }
            }
        }
    }
    cout<<total;
    return 0;
}