#include <bits/stdc++.h>
using namespace std;

#define MOD (lint)(1e9+7) 

typedef long long int lint;
lint p_o_w(lint a, lint b)
{
    if(b == 1) return a;

    lint cal = p_o_w(a, b/2);
    cal = (cal*cal)%MOD;
    if(b%2 == 0) return cal;
    else return (cal*a)%MOD;
}
lint maxPal(string s)
{
    vector<lint> v;

    for(auto ch:s) v.push_back(ch - 'A' + 1);

    lint sz = v.size();

    lint pw = 31;
    lint hduz = v[0];
    lint hters = v[0];
    // lint pw2 = 113;
    // lint hduz2 = v[0];
    // lint hters2 = v[0];

    lint maxp = 1;
    for(lint i = 1; i < sz; i++)
    {
        hduz = ((hduz*pw)%MOD + v[i])%MOD;
        hters = (hters + (v[i]*p_o_w(pw, i)%MOD)%MOD)%MOD;
        
        // hduz2 = ((hduz2*pw2)%MOD + v[i])%MOD;
        // hters2 = (hters2 + (v[i]*p_o_w(pw2, i)%MOD)%MOD);
        // cout<<hduz<<" "<<hters<<endl;
        if(hters == hduz 
        // && hters2 == hduz2
        )
        {
            maxp = max(maxp, i+1);
        }
    }

    
   
    return maxp;
}

int main()
{    
    string s;
    cin>>s;
    lint sz = s.size();

    lint a = maxPal(s);
    reverse(s.begin(), s.end());
    // cout<<"XXXXXXXXXXX\n";
    lint b = maxPal(s);
    cout<<sz - max(a,b) << endl;
    // cout<< p_o_w(10, 10);
    return 0;
}