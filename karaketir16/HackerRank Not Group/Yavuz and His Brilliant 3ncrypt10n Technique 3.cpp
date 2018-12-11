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
#define orta ((a+b)/2)
using namespace std;
#define pp pair<int,int>

typedef long long int lint;

string rvs(string s)
{
    string r;
    for(int i=3;i>=0;i--)
    {
        r.pb(s[i]);
    }
    return r;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        char ch;
        char matrix[102][102];
        vector<string> strs;
        cin>>n>>m;
        scanf("%c",&ch);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>matrix[i][j];
                //scanf("%c",&matrix[i][j]);
            }
           
            scanf("%c",&ch);
        }
        for(int i=0;i<n;i++)//yatay
        {
            for(int j=0;j<m-3;j++)
            {
                string s;
                for(int k=0;k<4;k++)
                {
                    s.pb(matrix[i][j+k]);
                }
                strs.pb(s);
                s=rvs(s);
                strs.pb(s);
            }
        }
        for(int i=0;i<n-3;i++)//dikey
        {
            for(int j=0;j<m;j++)
            {
                string s;
                for(int k=0;k<4;k++)
                {
                    s.pb(matrix[i+k][j]);
                }
                strs.pb(s);
                s=rvs(s);
                strs.pb(s);
            }
        }
        for(int i=0;i<n-3;i++)//asagicapraz
        {
            for(int j=0;j<m-3;j++)
            {
                string s;
                for(int k=0;k<4;k++)
                {
                    s.pb(matrix[i+k][j+k]);
                }
                strs.pb(s);
                s=rvs(s);
                strs.pb(s);
            }
        }
        for(int i=n-1;i>=3;i--)//yukari capraz
        {
            for(int j=0;j<m-3;j++)
            {
                string s;
                for(int k=0;k<4;k++)
                {
                    s.pb(matrix[i-k][j+k]);
                }
                strs.pb(s);
                s=rvs(s);
                strs.pb(s);
            }
        }
        vector<bool> dahil(strs.size(),1);
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i][0]!=strs[i][1]&&strs[i][1]==strs[i][2]&&strs[i][2]==strs[i][3])
            {
                
            }
            else
            {
                dahil[i]=0;
            }
        }
        set<string> setstring;
        map<string,int> mapp;
        for(int i=0;i<strs.size();i++)
        {
            if(dahil[i]==0) continue;
            string x=strs[i];
            if(x[0]=='I'||x[1]=='E') continue;
            setstring.insert(x);
            mapp[x]++;
        }
        int maxx=0;
        for(auto x:setstring)
        {
            maxx=max(maxx,mapp[x]);
        }
        cout<<maxx<<"\n";


    }
    return 0;
}
