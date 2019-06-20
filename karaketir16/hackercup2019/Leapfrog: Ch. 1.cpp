#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <=n; i++)
    {
        string s;
        cin>>s;
        map<char, int> mp;
        for (auto c:s)
        {
            mp[c]++;
        }
        int sz = s.size();
        sz--;
        if(sz == mp['B'])
        {
            printf("Case #%d: N\n", i);
            continue;
        }
        if(mp['B'] >= mp['.'])
        {
            printf("Case #%d: Y\n", i);
            continue;
        }
        else
        {
            printf("Case #%d: N\n", i);
            continue;
        }
    }
    return 0;
}