#include <iostream>
using namespace std;
typedef long long int lint;
int main()
{
    lint x,y,tot=0;
    x = y = 1;
    lint a;
    cin>>a;
    for(int i=1;i<a;i++){
        y=x+y;
        tot+=x;
        x=y-x;
    }
    tot+=x;
    cout<<tot;
    return 0;
}