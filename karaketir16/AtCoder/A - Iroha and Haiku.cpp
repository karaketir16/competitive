#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(500);
    int x;
    cin>>x;
    v[x]++;
    cin>>x;
    v[x]++;
    cin>>x;
    v[x]++;
    if(v[5]==2&&v[7]==1) cout <<"YES";
    else cout <<"NO";
    return 0;
}