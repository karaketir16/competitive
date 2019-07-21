#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
int main(){
    ios::sync_with_stdio(0);
    lint l, limit = ((lint)1<<32) - 1;
    cin>>l;
    stack<pair<lint, lint>> stc;
    lint e = 0;
    while(l--)
    {
        string s;
        cin>>s;
        if(s == "for")
        {
            lint x;
            cin>>x;
            stc.push({x, e});
            e = 0;
        }

        if(s == "add")
        {
            e++;
            if(e > limit)
            {
                cout<<"OVERFLOW!!!\n";
                return 0;
            }
        }

        if(s == "end")
        {
            lint tp = stc.top().first, tpe = stc.top().second; stc.pop();
            e*=tp;
            e+=tpe;
            if(e > limit)
            {
                cout<<"OVERFLOW!!!\n";
                return 0;
            }
        }
    }
    cout << e;
    return 0;
}