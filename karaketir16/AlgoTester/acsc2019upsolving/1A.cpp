#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, c;
    cin>>n>>a>>b>>c;

    int lucky =0, nott =0;
    while (n>0)
    {
        int a = n % 10;
        if(a == 7 || a== 4)
        {
            lucky++;
        }
        else nott++;
        n/=10;
    }
    int res1 = nott*a;
    int res2 = nott*c + (lucky == 0 ? b : 0);
    int res3 = (nott-1)*c + a;
    int res = min({res1, res2, res3});
    cout<<(nott == 0 ? 0 : res);
    return 0;
}