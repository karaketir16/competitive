#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);

    string s;

    cin>>s;


    set<char> ss(s.begin(), s.end());

    if(ss.size()%2)
    {
        cout<<"IGNORE HIM!";
    }
    else
    {
        cout<<"CHAT WITH HER!";
    }
    
    return 0;
}