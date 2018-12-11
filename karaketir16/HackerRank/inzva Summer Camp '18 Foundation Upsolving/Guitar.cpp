#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;

int main()
{
    int n,p;
    cin>>n>>p;
    vector<int> frets;
    vector<vector<int>> all(7,frets);


    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        all[x].pb(y);
    }
    int move =0;
    for(int str=1;str<=6;str++)
    {
        vector<int> ftrs=all[str];
        stack<int> basili;
        for(auto ft:ftrs)
        {
            while(!basili.empty()&&ft<basili.top())
            {
                basili.pop();
                move++;
        
            }
            if(!basili.empty())
            {
                if(basili.top()==ft)
                {

                }
                
                else

                {
                    basili.push(ft);
                    move++;
                }

            }
            else
            {
                basili.push(ft);
                move++;

            }

            
            
            
            





        }
    }
    cout<<move;
    return 0;

}