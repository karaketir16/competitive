#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int m, s;
    cin>>m>>s;
    if(s == 0)
    {
        if(m == 1) cout <<"0 0\n";
        else cout << "-1 -1\n";
        return 0;
    }
    vector<int> arr(m); //01234
    for(int i =0;i < m;i++)
    {
        if(s >= 9)
        {
            arr[i] = 9;
            s-=9;
        }    
        else
        {
            arr[i] = s;
            s = 0;
        }
    }
    if(s != 0)
    {
        cout<<"-1 -1\n";
        return 0;
    }
    auto maksi = arr;
    reverse(arr.begin(), arr.end());
    auto mini = arr;
    if(mini[0] == 0)
    {
        for(int i = 1; i < m; i++)
        {
            if (mini[i] != 0)
            {
                mini[0] = 1;
                mini[i]--;
                break;
            }
        }
    }
    for (auto a:mini) cout<<a;
    cout <<" ";
    for (auto a:maksi) cout<<a;
    cout<<'\n';
    return 0;
}