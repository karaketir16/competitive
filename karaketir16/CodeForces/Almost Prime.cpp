#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t = 60;
    int arr[3605];
    bool primes[3605];
    bool wanted[3605];
    for(int i=0;i<3605;i++)
    {
        wanted[i]=0;
    }
    for(int i=2;i<3605;i++)
    {
        primes[i]=1;
    }
    for(int i=2;i<=60;i++)
    {
        for(int j=2;j<=1805;j++)
        {
            int calc=i*j;
            if(calc>3600) break;
            primes[calc]=0;
        }
    }
    int n;
    cin>>n;
    int total=0;
    for(int i=2;i<=n;i++)
    {
        int count=0;
        for(int j=2;j<=n;j++)
        {
            if(!primes[j]) continue;
            if(i%j==0) count++;

        }
        if(count==2) total++;
    }
    cout<<total;
    return 0;
}