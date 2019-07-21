#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int z, o;
    cin>>z>>o;
    int oz = min(o, z);
    o-=oz;
    z-=oz;
    if(z>1)
    {
        cout<<-1;
        return 0;
    }
    int ooz = min(oz, o);
    oz-=ooz;
    o-=ooz;
    if(o>2)
    {
        cout<<-1;
        return 0;
    }
    if(z) cout<<0;
    for(int i = 0;i<oz;i++) cout<<"10";
    for(int i = 0;i<ooz;i++) cout<<"110";
    if(o-->0) cout<<1; if(o-->0) cout<<1;
    return 0;
}