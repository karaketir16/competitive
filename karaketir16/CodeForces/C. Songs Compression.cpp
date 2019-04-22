#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
int main()
{
    lint n, k;
    cin>>n>>k;
    vector<int> v;
    lint a, b, c=0;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        c+=a;
        v.push_back(a-b);
    }
    sort(v.rbegin(), v.rend());
    int i=0;
    for(;n--&&c>k;i++){
        c-=v[i];
    }
    if(c>k) cout<<-1;
    else cout<<i;
    return 0;
}