#include <bits/stdc++.h>
#define N 100007
using namespace std;


int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        bool flag=false;
        for(int i=x;i>=0;i-=5)
        {
            if(i%3==0)
            {
                for(int j=0;j<i;j++) cout<<'5';
                for(int j=0;j<x-i;i++) cout<<'3';
                cout<<"\n";
                flag=true;
                break;
            }
        }
        if(!flag) cout<<"-1\n";
    }
    return 0;
}