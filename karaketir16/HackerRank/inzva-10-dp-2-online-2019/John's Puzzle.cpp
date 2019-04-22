#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
vector<lint> isPrime(10000005,true);
vector<lint> dp(50, -1);
lint f(int x){
    if(x < 0) return 0;
    if(x == 0) return 1;
    if(dp[x] != -1) return dp[x];

    dp[x] = f(x - 1) + f(x - 4);  
    return dp[x]; 
}
int main(){

    isPrime[0]=isPrime[1]=0;
    for(int i=2;i*i<10000005;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<10000005;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    for(int i=1;i<10000005;i++)
    {
        isPrime[i] += isPrime[i-1];
    }
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        cout<<isPrime[f(a)]<<"\n";
    }

    return 0;
}