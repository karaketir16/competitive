#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    //rotate(s.begin() + 2, s.begin() + 3, s.begin() + 6);
    int m;
    cin>>m;
    while (m--)
    {
        int l, r, k;
        cin>>l>>r>>k;
        l--;
        r--;
        if(l==r) continue;
        k%=(r-l+1);
        //cerr<<k<<endl;
        rotate(s.begin() + l, s.begin() + l + (r-l+1) - k, s.begin() + r+1);
        //cout<<s<<endl;
    }
    cout<<s;
    return 0;
}