#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> is_leap(401), answer(401);
    is_leap[0] = answer[0] = 1;
    for(int i=1; i<400;i++)
    {
        is_leap[i] = ((i%4 == 0) && (i%100));
        answer[i] = answer[i-1] + is_leap[i];
        // cout<<i<<": "<<answer[i]<<endl;
    }
    
    int n;
    cin>>n;

    int a = n/400;
    int m = n%400;

    int minn = 1e9;
    int maxx = -1;
    for(int i = 0; i<400; i++)
    {
        int j = i;
        int k = 0;
        int tmp = 0;
        for(; j < 400 && k < m; j++, k++)
        {
            tmp += is_leap[j];
        }
        if(k<m)
        {
            tmp+=answer[m-k-1];
        }
        // cout << "i: "<<i<<' '<<tmp<<' '<<k<<endl; 
        minn = min(minn, tmp);
        maxx = max(maxx, tmp);
    }

    a *= answer[399]; 
    cout<< a + minn << ' '<< a + maxx;

    return 0;
}