#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int n, k;
        cin>>n>>k;
        lint step = 0;
        while (n>0)
        {
            if(n%k != 0)
            {
                step += n%k;
                n -= n%k;
            }
            else
            {
                n/=k;
                step++;
            }
        }
        cout << step<<'\n';
    }
    return 0;
}