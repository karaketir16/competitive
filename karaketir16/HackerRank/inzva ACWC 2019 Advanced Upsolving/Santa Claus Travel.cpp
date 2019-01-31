#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;

vector<int> uf(N);

int find(int x)
{
    if(x!=uf[x]) uf[x] = find(uf[x]);
    return uf[x];
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        FOR0(N) uf[i] = i;

        int n, m;

        cin >> n >> m;

        priority_queue<
                        pair<int, pair<int, int>>,
                        vector<pair<int, pair<int, int>>>,
                        greater<pair<int, pair<int, int>>>
                        > pq;

        FOR0(m)
        {
            int x, y, z;
            cin >> x >> y >> z;

            pq.push({z, {x, y}});

        }
        int tot=0;
        while(!pq.empty())
        {
            int len = pq.top().first;
            int n1 = pq.top().second.first;
            int n2 = pq.top().second.second;
            pq.pop();

            if(find(n1)!=find(n2))
            {
                uf[uf[n1]] = uf[n2];
                tot += len;
            }
        }

        cout << tot;
        if(t) cout<<"\n--\n";
    }

    return 0;
}
