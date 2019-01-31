#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1000005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
double x1, yy1, z1, x2, y2, z2, ax1, ay1, az1, ax2, ay2, az2, R; 

double fx(double x, double a, double t)
{
    return ((pow(t, 2)* a *(0.5)) + x);
}

double dist(double tx1, double tyy1, double tz1, double tx2, double ty2, double tz2)
{
    //cout<< tx1<<" "<< tyy1<<" "<< tz1<<" "<< tx2<<" "<< ty2<<" "<< tz2<<endl;
    double d = sqrt(pow(tx1-tx2, 2)+pow(tyy1-ty2, 2)+pow(tz1-tz2, 2));
    return d;
}

double f(double t)
{
    return dist(fx(x1, ax1, t), fx(yy1, ay1, t), fx(z1, az1, t), fx(x2, ax2, t), fx(y2, ay2, t), fx(z2, az2, t));
}

double ternarySearch(double left, double right, double eps=1e-7){
    while (right - left > eps){
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;
        
        if (f(mid1) > f(mid2))
            left = mid1;
        else
            right = mid2;
    }
    return f(left);
}
int main()
{

    std::ios::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--)
    {
        lint r1, r2;
        cin>> r1>>r2>> x1>> yy1>> z1;
        cin>> ax1>> ay1>> az1;
        cin>>x2>> y2>> z2>> ax2>> ay2>> az2;
        if(ternarySearch(0, 1000000000) - (r1+r2) <=0) cout<<"YES\n";

        else  cout<<"NO\n";

       // cout<<ternarySearch(0, 1000000000);
        //cout<<endl<<f(7)<<endl;
        //cout<<fx(x1, ax1, 7)<<endl;
        //cout<< x1<<" "<< ax1<<"\n";
    }
    return 0;
}