#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
int main()
{
    vector<vector<int>> divisors(2002);
    divisors[1].push_back(1);
    for(int i = 2; i<2002;i++)
    {
        int j;
        for(j = 1; j*j < i; j++)
        {
            if(i%j == 0)
                divisors[i].push_back(j), divisors[i].push_back(i/j);
        }
        if(j*j == i) divisors[i].push_back(j);
    }
    int n, k;
    cin>>n>>k;
    vector<vector<lint>> table(2002, vector<lint>(2002));
    table[1] = vector<lint>(2002, 1);
    
    for(int i = 2; i<=k;i++)
    {
        for(int j = 1; j <=n; j++)
        {
            lint tot = 0;
            for(auto d : divisors[j])
            {
                tot+=table[i-1][d];
                // cerr<<"i: "<<i<<" j: "<<j<<" d: "<<d<<" tab: "<<table[i-1][d]<<endl;
            }
            table[i][j] = tot%1000000007;
            
        }
    }
    // for(int i = 1; i<=k;i++)
    // {
    //     for(int j = 1; j <=n; j++)
    //     {

    //             cerr<<table[i][j]<<"\t";

    //     }
    //     cerr<<endl;
    // }
    lint tot = 0;
    for(int i = 1; i<=n;i++)
    {
        tot += table[k][i];
    }
    cout<<fixed<<tot%1000000007;
    return 0;
}