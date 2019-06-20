#include <bits/stdc++.h>
using namespace std;

map<int, int> par;
map<int, int> dis;

void koy(int a, int b)
{
    par[a] = b;
    dis[a] = 1;
}
int find_par(int a)
{
    if(a == par[a]) return a;

    int pr = par[a];
    par[a] = find_par(par[a]);
    dis[a] += dis[pr]; 
    return par[a];
}
int main()
{

    int n, m;
    cin>>n>>m;
    
    for(int i = 0; i <= n; i++) par[i] = i;

    while(m--)
    {
        char ch;
        cin>>ch;

        if(ch == '+')
        {
            int x, y;
            cin>>x>>y;
            koy(x, y);
        }
        else
        {
            int x; cin>>x;
            find_par(x);
            cout<< dis[x] + dis[par[x]]<<endl;
        }
    }

    return 0;
}