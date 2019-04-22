#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    map<char, int> mp;
    for(auto a:s)
    {
        mp[a]++;
    }
    int t=0, c=0, ss=s.size();
    for(auto a:mp)
    {
        if(a.second%2)
        {
            t++;
        }
        else
        {
            c++;
        }
        
    }
    //cout<<t<<" "<<c<<endl;
    if(ss&1)
    {
        cout<<"First";
    }
    else
    {
        if(t>0) cout<<"Second";
        else cout<<"First";
    }
    return 0;
}