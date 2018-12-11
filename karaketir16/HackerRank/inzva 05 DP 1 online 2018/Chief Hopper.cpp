#include <bits/stdc++.h>

using namespace std;


void up(double &a)
{
    int b=a;
    a = a==b ? a : b+1;
}
// Complete the chiefHopper function below.


int main()
{
    double x;
    cin>>x;
    vector<double> arr(x);
    for(int i=x-1;i>=0;i--)
    {
        scanf("%lf", &arr[i]);
    }
    double init = 0;
    for(auto a:arr)
    {
        init+=a;
        init/=2;
        up(init);
    }
    cout<<init;
    
    return 0;
}
