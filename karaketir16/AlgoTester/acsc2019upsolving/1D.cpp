#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
int main()
{
    vector<vector<lint>> dp(10, vector<lint> (100));
    vector<lint> pre(1);
    for(int i = 1; i<10; i++) dp[i][1]=1;
    for(int j = 2; j < 100; j++) 
    {
        lint here =0;
        for(int i = 9; i>=1 ; i--)
        {
            here += dp[i][j-1];
            dp[i][j] = here;
        }
        pre.push_back(here);
    }
    
    for(int i = 1; i<pre.size(); i++) pre[i] += pre[i-1]; 
    // for(int i = 0; i<pre.size(); i++) cout<<pre[i]<<' '; 
    lint n;
    cin>>n;

    int index = (lower_bound(pre.begin(), pre.end(), n) - pre.begin());
    int num = pre[index];
    // cout<<index<<endl;
    vector<int> ans;
    while(num>=n&&index)
    {
        for(int i = 9;i>0;i--)
        {
            // cout << num <<' '<< i<<' '<< dp[i][index]<<endl;
            if(num - dp[i][index] <n)
            {
                ans.push_back(i);
                break;
            }
            
            num -= dp[i][index];
            // cout<<num<<' ';
        }
        // cout<<'t';
        index--;
    }
    // cout<<ans.size()<<endl;
    for(auto a: ans) cout<<a;
    // for(int i = 0; i < 10; i++)
    // {
    //     for(int j = 0; j<5; j++)
    //     {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    return 0;
}