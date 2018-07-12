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
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int number=0;
    int en_son=0;
    vector<int> lenghts;
    for(auto m:arr)
    {
        if(m==1)
        {
            number++;
            if(en_son!=0)
            {
                lenghts.pb(en_son);
            }

        }
        en_son=m;

    }
    lenghts.pb(en_son);
    cout<<number<<"\n";
    for(auto m:lenghts)
    {
        cout<<m<<" ";
    }
    return 0;
}