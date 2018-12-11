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

typedef long long int ll;
int len_of_pref(string &s)
{
    int sn;
    sn=s.size();
    vector<int> pat(sn,0);
    int len=0;
    for(int i=1;i<sn;)
    {
        if(s[len]==s[i])
        {
            len++;
            pat[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                i++;
            }
            else
            {
                len=pat[len-1];
            }
        }
    }
    return pat[sn-1];
}
void fonk(string s,string &text)
{

    int len_of_longest=len_of_pref(s);
    if(len_of_longest==0)
    {
        cout<<-1;
        return;
    }
    s="";
    for(int i=0;i<len_of_longest;i++)
    {
        s.pb(text[i]);
    }

    int pn;
    int textn;
    pn=s.size();
    textn=text.size();
    vector<int> pat(pn,0);
    int len=0;
    for(int i=1;i<pn;)
    {
        if(s[len]==s[i])
        {
            len++;
            pat[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                i++;
            }
            else
            {
                len=pat[len-1];
            }
        }
    }

//////////////////////////

    for(int i=0,j=1;i<pn,j<textn-1;)
    {
        if(s[i]==text[j])
        {
            i++;
            j++;
            if(i==pn)//found
            {

                cout<<s<<"\n";
                return;
            }
        }
        else
        {
            if(i>0)
            {
                i=pat[i-1];
            }
            else
            {
                j++;
            }
        }
    }

    //if not found

    fonk(s,text);


}
int main()
{
    int pn;
    string text;
    string s="";
    cin>>text;

    fonk(text,text);

    
    return 0;
}