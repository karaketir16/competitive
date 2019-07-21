#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
int main()
{
    // cout<<(-9)%3;
    ios::sync_with_stdio(0);
    lint n = 0, res =0;
    cin>>n;
    vector<lint> arr(n);
    lint tot = 0;
    for (int i =0;i<n;i++)
    {
        lint x;
        cin>>x;
        tot+=x;
        arr[i] = x;
    }
    if(tot % 3 != 0)
    {
        cout<<0;
        return 0;
    }
    tot/=3;
    lint temp = 0;
    vector<lint> left(n+1);
    // if(tot == 0) left[n] = 1;
    for(int i = n-1;i>=0;i--)
    {
        temp +=arr[i];
        left[i]=left[i+1];
        if(tot == temp) left[i]++;
    }
    // cout<<"asd: "<<left[0]<<'\n';
    // if(tot == 0) res+=left[0];
    temp = 0;
    for(int i = 0; i<n-1;i++)
    {
        temp+=arr[i];
        if(tot == temp) res+=left[i+2];
    }
    cout<<res<<'\n';
    return 0;
}