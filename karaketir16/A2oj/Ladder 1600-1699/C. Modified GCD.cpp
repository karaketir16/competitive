#include <bits/stdc++.h>

using namespace std;

int fastG(int a, int b)
{
    return (b==0 ? a : fastG(b, a%b));
}

int main()
{
    int a, b;
    cin>>a>>b;
    int g=fastG(a, b);
    vector<int> v;
    for(int i=1;i*i<=g;i++)
        if(g%i==0)
        {
            v.push_back(i);
            if(g/i!=i) v.push_back(g/i);
        }
            
    
    sort(v.begin(), v.end());
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;

        auto it=upper_bound(v.begin(), v.end(), y);
        it--;
        if(it<v.begin()||*it<x) cout<<-1<<'\n';
        else cout<<*it<<'\n';
    }
    
    return 0;
}