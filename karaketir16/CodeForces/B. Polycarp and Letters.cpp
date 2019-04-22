#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m=0;
    cin>>n;
    set<int> s;
    while(n--)
    {
        char c;
        cin>>c;
        if(c<'[')
        {
            s.clear();

        }
        else
        {
            s.insert(c);
            m=max(m, (int)s.size());
        }
        
    }
    cout<<m;
    return 0;
}