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
typedef long long int lint;

struct Node
{
    Node* childs[75]={NULL};
    bool is_end=false;
};

int main()
{
    int n,m;
    cin>>n>>m;
    Node* start=new Node;
    
    while(m--)
    {
        string str;
        cin>>str;
        Node* now=start;
        for(auto ch:str)
        {
            ch-=48;
            if(now->childs[ch]!=NULL)
            {
                now=now->childs[ch];
            }
            else
            {
                now->childs[ch]=new Node;
                now=now->childs[ch];

            }
        }
        now->is_end=true;
    }
    
    while(n--)
    {
        string str;
        cin>>str;
        Node* now=start;
        for(int i=0;now->is_end!=true;i++)
        {
            printf("%c",str[i]);
            now=now->childs[str[i]-48];
            //cout<<now<<endl;
            if(now==NULL)
            {
                for(int j=i+1;j<str.size();j++)
                {
                    printf("%c",str[j]);
                }
                break;
            }
        }
        printf(" ");
    }
    
    return 0;
}