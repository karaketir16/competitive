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
void add(set<int> &voters, set<int> &st, int vot)
{
    auto x = st.find(vot);
    if(x==st.end())
    {
        st.insert(vot);
    }
    else
    {
        voters.insert(vot);
    }   
}
int main()
{
    int n1,n2,n3;
    set<int> st;
    set<int> voters;
    cin>>n1>>n2>>n3;
    while(n1--)
    {
        int vot;
        cin>>vot;
        add(voters,st,vot);
    }
    while(n2--)
    {
        int vot;
        cin>>vot;
        add(voters,st,vot); 
    }
    while(n3--)
    {
        int vot;
        cin>>vot;
        add(voters,st,vot);
    }
    printf("%d\n",voters.size());
    for(auto x:voters)
    {
        printf("%d\n", x);
    }

    return 0;
}