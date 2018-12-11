#include<iostream>
#include<algorithm>
#include <vector>
#define pb push_back
#define mod 1000000007
using namespace std;
typedef long long int lint;


int main()
{
    vector<lint> arr;
    char c;
    scanf("%c", &c);
    int k=0;
    lint anum=0;
    while(c!='\n')
    {
        if(c=='a')
        {
            anum++;
        }
        else if(c=='b')
        {
            if(anum!=0) arr.pb(anum);
            anum=0;
        }
        scanf("%c", &c);
    }
    if(anum!=0) arr.pb(anum);
    lint result=0;
    for(lint x: arr)
    {
        result+= (result*x)%mod +x;
        result%=mod;
    }
    cout<<result;
    return 0;
}