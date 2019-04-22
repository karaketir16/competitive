#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c=0;
    int a=0,b=0;
    scanf("%c", &c);
    while(c!='\n')
    {
        //cout<<c*1;
        if(c=='0')
        {
            a++;b = 0;
        }
        else
        {
            b++; a=0;
        }
        if(a>6||b>6)
        {
            cout<<"YES";
            return 0;
        }
        scanf("%c", &c);
    }
    cout<<"NO";
    return 0;
}