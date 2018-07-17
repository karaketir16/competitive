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
    vector<string> giren;
    string s="";
    vector<string> sayilar;
    vector<string> diger;
    int g_s=0;
    int s_s=0;
    int d_s=0;
    char ch;
    scanf("%c",&ch);
    while(ch!='\n')
    {
        //cout<<"t";
        if(ch==';'||ch==',')
        {
            giren.pb(s);
            s="";

        }
        else
        {
            s+=ch;
        }
        
        scanf("%c",&ch);
    }
    giren.pb(s);
    for(auto x: giren)
    {
        //cout<<x<<endl;
        if(x.size()>1&&x[0]=='0')
        {
            diger.pb(x);
        }
        else if(x.size()>=1)
        {
            bool hepsi=true;
            for(auto h:x)
            {
                
                if(h<'0'||h>'9')
                {
                    hepsi=false;
                    break;
                }
            }
            if(hepsi)
            {
                sayilar.pb(x);
            }
            else
            {
                diger.pb(x);
            }
        }
        
        else
        {
            diger.pb(x);


        }
        

        
    }
    if(sayilar.size()>0)
    {
        cout<<"\"";
        for(int i=0;i<sayilar.size();i++)
        {
            cout<<sayilar[i];
            if(i!=sayilar.size()-1)
            {
                cout<<",";
            }
        }
        cout<<"\"\n";

    }
    else
    {
        cout<<"-\n";
    }

    if(diger.size()>0)
    {
        cout<<"\"";
        for(int i=0;i<diger.size();i++)
        {
            cout<<diger[i];
            if(i!=diger.size()-1)
            {
                cout<<",";
            }
        }
        cout<<"\"\n";

    }
    else
    {
        cout<<"-\n";
    }

    return 0;
}