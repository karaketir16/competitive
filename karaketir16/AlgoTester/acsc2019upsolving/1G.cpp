#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
int main()
{
    vector<int> st = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 25, 26, 27, 28,
    30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57 ,60};

    vector<int> nps(500, 1000000);
    nps[0]=0;
    for(auto a: st)
    {
        for(int i =0; i<200; i++)
        {
            if(nps[i]!=1000000)
            {
                nps[i + a] = min(nps[i+a], nps[i]+1);
            }
        }
    }
    // for(int i =0; i< 70; i++) cout << nps[i]<<' ';

    int n;
    cin>>n;
    if(n < 200)
    {
        cout<<nps[n];
    }
    else
    {
        int m = n%60;
        int b = n/60;
        cout<< (b-1) + nps[60+m]<<endl;    
    }
    
    return 0;
}