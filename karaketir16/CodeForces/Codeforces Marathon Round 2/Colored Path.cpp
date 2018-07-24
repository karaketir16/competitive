#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl

#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;

int main()
{
    //srand(time(NULL));
    int N, S, C, H, U;
    cin>>N>>S>>C>>H>>U;
    vector<int> colors(C);
    vector<int> bkls(U);

    vector<char> stripe;
    for(int i=0;i<N;i++)
    {
        char c;
        cin>>c;
        int t=c-'A';
        colors[t]++;
    }
    vector<pair<int,char>> clrs;
    for(int i=0;i<C;i++)
    {
        char c=i+'A';
        clrs.pb(MP(colors[i],c));
    }
    sort(clrs.begin(),clrs.end());
    vector<char> hand;
    vector<char> bottles;
    for(int i=0;i<H;i++)
    {
        char c;
        cin>>c;
        hand.pb(c);
    }
    for(int i=0;i<S;i++)
    {
        char c;
        cin>>c;
        bottles.pb(c);
    }
    for(int i=0;i<S;i++)
    {
        int u=i%10;
        //int u=rand();
        //char c=bottles[i];
        char c;
        for(int b=0;b<C;b++)
        {
            char a=clrs[b].sc;
            auto f=find(hand.begin(),hand.end(),a);
            if(f==hand.end()) continue;
            else
            {
                c=a;
                hand.erase(f);
                hand.pb(bottles[i]);
                break;
            }
        }
        printf("%d %c\n",u,c);
    }

    return 0;
}