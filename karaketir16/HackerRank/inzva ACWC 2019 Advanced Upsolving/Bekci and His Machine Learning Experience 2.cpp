#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
class D   
{   
    public:
    D (lint a, lint b, lint c, lint d)
    {
        this->a =a;
        this->b =b;
        this->c =c;
        this->d =d;
    }

    lint a,b,c,d;

    void prt()
    {
        cerr<< endl<< a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    lint t;
    cin>>t;
    while(t--)
    {
        lint n, m;
        cin>>n>>m;

        vector<vector<lint>> v(n, vector<lint> (m));
        FORE(v) INPUT(a);

        vector<vector<lint>> prer(n);

        for(lint i = 0; i<n; i++)
        {
            lint a =0;
            for(lint j =0 ; j <m; j++)
            {
                prer[i].push_back(v[i][j]+a);
                a=v[i][j]+a;
                // dbg(a);
            }
/*             FORE(prer[i]) cout<<a<<" ";
            cout<<endl; */
        }

        lint gmax = -1*inf;
        vector<D> dd;
        
        for(lint l = 0; l < m; l++)
        {
            for(lint r = l; r < m; r++)
            {
                vector<lint> col;
                for(lint i = 0; i<n; i++) col.push_back(prer[i][r] - (l-1 >=0 ? prer[i][l-1] : 0));
/*                  dbg(l); dbg(r);
                FORE(col) cerr<<a<<" ";
                cerr<<endl;  */
                //vector<lint> kad(n);
                lint now = 0, maxx = -1*inf, maxxi =-1, lastz = -1, lastz_tmp = -1;
                for(lint i = 0; i<n; i++)
                {
                    now += col[i];
                    if(now<0)
                    {
                        now = 0;
                        lastz_tmp = i;   
                    }
                    else if(now >=maxx)
                    {
                        maxx = now;
                        maxxi = i;
                        lastz = lastz_tmp;
                    }
                }
                if(maxx > gmax)
                {
                    dd.clear();
                    gmax = maxx;
                    dd.push_back(D(lastz+1, maxxi, l, r));
                    //cout<<"t1\n";
                }
                else if(maxx == gmax)
                {
                    dd.push_back(D(lastz+1, maxxi, l, r));
                    //cout<<"t2\n";
                }
                //dbg(maxx);
            }
        }
//////////////
///////////////////
////////////////
//////////////
//////////////////
////////////

        for(lint l = 0; l < m; l++)
        {
            for(lint r = l; r < m; r++)
            {
                vector<lint> col;
                for(lint i = 0; i<n; i++) col.push_back(prer[i][r] - (l-1 >=0 ? prer[i][l-1] : 0));
/*                  dbg(l); dbg(r);
                FORE(col) cerr<<a<<" ";
                cerr<<endl;  */
                //vector<lint> kad(n);
                lint now = 0, maxx = -1*inf, maxxi =-1, lastz = -1, lastz_tmp = -1;
                for(lint i = 0; i<n; i++)
                {
                    now += col[i];
                    if(now<0)
                    {
                        now = 0;
                        lastz_tmp = i;   
                    }
                    else if(now >=gmax)
                    {
                        maxx = now;
                        maxxi = i;
                        lastz = lastz_tmp;
                        dd.push_back(D(lastz+1, maxxi, l, r));
                    }
                }
                if(maxx > gmax)
                {
                    dd.clear();
                    gmax = maxx;
                    dd.push_back(D(lastz+1, maxxi, l, r));
                    //cout<<"t1\n";
                }
                else if(maxx == gmax)
                {
                    dd.push_back(D(lastz+1, maxxi, l, r));
                    //cout<<"t2\n";
                }
                //dbg(maxx);
            }
        }


        auto g = vector<vector<lint>> (n, vector<lint> (m+1));

        FORE(dd) 
        {
            for(lint i = a.a; i <=a.b; i++)
            {
                g[i][a.c]+=1;
                g[i][a.d+1]+=-1;
                
            }
            
            //a.prt();
        }
        for(lint i = 0; i<n; i++)
        {

            for(lint j =1 ; j <m; j++)
            {
                
                g[i][j] +=  g[i][j-1];
                //cerr << g[i][j]<<" ";
            }
            //cerr<<"\n";
        }
        for(lint j = 0; j<m; j++)
        {
            for(lint i =0 ; i<n; i++)
            {
                cout << (g[i][j] > 0? gmax : v[i][j])<<" ";
            }
            cout<<"\n";
        }


        if(t) cout<<"--\n";
    }

    return 0;
}
