#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 8981
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;

int main()
{
    int x;
    int total=0;
    vector<int> mine;
    vector<int> expected;

    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        mine.pb(x);
    }
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        expected.pb(x);
    }
    for(int i=0;i<N;i++)
    {
        if(mine[i]!=expected[i])
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
/*
50
78
263
373
566
602
841
1041
1090
1201
1335
1350
1621
1954
2361
2649
3584
*/