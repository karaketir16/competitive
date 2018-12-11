#include<iostream>
#include<algorithm>
#include <vector>
#define pb push_back
#define inf	1000000000000000LL
using namespace std;
typedef long long int lint;
int main()
{
    std::ios::sync_with_stdio(false);
    lint n, s;
    lint minn = inf;
    cin>>n>>s;
    lint fazla=0;
    for(lint i=0;i<n;i++)
    {
        lint x;
        cin>>x;
        minn = min(minn, x);
        if(s>0)
        {
            s-=x;
            if(s<0)
            {
                fazla+=-1*s;
                s=0;
            }
        }
        else
        {
            fazla+=x;
        }
    }
    if(s>0)
    {
        cout<<-1;
        return 0;
    }
    cout<<min(fazla/n,minn);
    return 0;
}