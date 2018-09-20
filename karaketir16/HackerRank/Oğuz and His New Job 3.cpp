#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    sorry:
    while(t--)
    {
        string s;
        cin>>s;
        string a;
        cin>>a;
        int as=a.size();
        int ss=s.size();
        if(as>ss)
        {
            cout<<"Wrong Communication\n";
            continue;
        }
        for(int i=as-1,j=ss-1;i>=0;i--,j--)
        {
            if(a[i]!=s[j])
            {
                cout<<"Wrong Communication\n";
                goto sorry;
            }
        }
        cout<<"Correct Communication\n";
    }
    return 0;
}
