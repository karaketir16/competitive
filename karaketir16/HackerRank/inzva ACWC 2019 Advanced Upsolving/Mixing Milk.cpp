#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
void pour(int a,int& x , int b, int& y)
{
    if(x+y > b)
    {
        x -= b-y;
        y = b;
    }
    else
    {
        y += x;
        x = 0;
    }
    
}
int main()
{
    std::ios::sync_with_stdio(false);
    int a,b,c,x,y,z;
    cin >> a >> x;
    cin >> b >> y;
    cin >> c >> z;

    for(int i=0;i<33;i++)
    {
        pour(a,x,b,y);
        pour(b,y,c,z);
        pour(c,z,a,x);
    }
    pour(a,x,b,y);


    cout << x << endl << y << endl << z;
}