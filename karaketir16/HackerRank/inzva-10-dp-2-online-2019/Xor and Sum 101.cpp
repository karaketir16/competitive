#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long lint;
lint fastPow(lint n, lint k)
{
    if(k==0) return 1;
    if(k==1) return n%mod;
    lint temp=fastPow(n,k>>1)%mod;
    if(k&1) return (temp*temp*n)%mod;
    return (temp*temp)%mod;
}
#define N 100005
vector<int> b;
vector<int> a;

int fonk(int i, int j)
{
    if(i <= 0) return b[j];
    return b[j]^b[i-1]; 
}
int main(){
    ios::sync_with_stdio(0);
    string aa, bb;
    cin>>aa>>bb;
    for(auto c:aa){
        if(c == '1') a.push_back(1);
        else a.push_back(0);
    }

    for(auto c:bb){
        if(c == '1') a.push_back(1);
        else a.push_back(0);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while(a.size()<N){
        a.push_back(0);
    }
    while(b.size()<N){
        b.push_back(0);
    }
    for(int i =1; i < N; i++){
        b[i] ^= b[i-1]; 
    }
    for(int i = 0; i<N; i++){
        a[i] ^= fonk(i-314159, i);
    }
    int res = 0;
    for(int i = 0; i<N; i++){
        if(a[i])
        {
            cerr<<"test";
            res = (res + fastPow(2, i))%mod;
        }
    }
    cout <<res;
    return 0;
}