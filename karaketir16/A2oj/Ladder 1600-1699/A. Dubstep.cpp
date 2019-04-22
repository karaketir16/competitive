#include <bits/stdc++.h>
using namespace std;
bool check(string s, int x)
{   
    if(x+2 >= s.size()) return false;
    char a = s[x], b = s[x+1], c = s[x+2];
    if(a=='W' && b == 'U' && c == 'B' )
        return true;
    return false;
}
int main(){
    string s, res = "";
    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        if(check(s, i)) {
            if(res.size() != 0 && res.back()!=' ')
            {
                res+=' ';
            }
            i+=2;
            continue;
            }
        res+=s[i];
    }
    cout<<res;
    return 0;
}