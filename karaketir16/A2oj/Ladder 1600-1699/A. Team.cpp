#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin>>a;
    int res =0;
    for(int i =0; i< a; i++)
    {
        int a,o,e;
        cin>>a>>o>>e;
        int tot = a+ o+ e;
        if(tot>=2)
            res++;
    }
    cout<<res;
    return 0;
}