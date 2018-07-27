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
void go_left(int &pos, int &n)
{
    if(pos==0) return;
    pos--;
}
void go_right(int &pos, int &n)
{
    if(pos==n-1) return;
    pos++;
}
void pick(int &pos,vector<int> &stacks,bool &picked)
{
    if(stacks[pos]==0||picked) return;
    stacks[pos]--;
    picked=true;
}
void drop(int &pos,vector<int> &stacks,bool &picked,int &h)
{
    if(stacks[pos]==h||!picked) return;
    stacks[pos]++;
    picked=false;
}
void quit(vector<int> &stacks)
{
    for(auto x:stacks)
    {
        printf("%d ",x);
    }
    exit(0);
}
int main()
{
    int n,h,pos=0;
    bool picked=0;
    cin>>n>>h;
    vector<int> stacks;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        stacks.pb(x);
    }
    int x;
    while(true)
    {
        cin>>x;
        
        switch (x)
        {
            case 1:
                go_left(pos,n);
                break;
            
            case 2:
                go_right(pos,n);
                break;

            case 3:
                pick(pos,stacks,picked);
                break;
            
            case 4:
                drop(pos,stacks,picked,h);
                break;
            
            case 0:
                quit(stacks);
                break;
        
            default:
                break;
        }
    }
    return 0;
}