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

////////////////////////////////////////////////////////////////////////////////////////
/*
*   Function that calculate how many times s is found in text  
*
*/
int KMP(string &s, string &text)
{
    int found_number=0;
    int pn;
    pn=s.size();
    int textn;
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
    for(int i=0,j=0;i<pn,j<textn;)
    {
        if(s[i]==text[j])
        {
            if(i==pn-1)
            {
                found_number++;
                i=pat[i-1];
            }
            else
            {
                i++;
                j++;
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
    return found_number;
}

/////////////////////////////////////////////////////////////////////////////
struct Compare {
    constexpr bool operator()(pair<lint, lint> const & a,
                              pair<lint, lint> const & b) const noexcept
    { return a.first > b.first || (a.first == b.first && a.second > b.second); }
};

priority_queue<pair<lint,lint>, vector<pair<lint,lint>>, Compare> pq_pair()
{
    priority_queue<pair<lint,lint>, vector<pair<lint,lint>>, Compare> Q;
    return Q;
}



//////////////////////////////////////////////////////////////////////////////////
int main()
{
    srand(time(NULL));
    auto Q=pq_pair();
    for(int i=0;i<10;i++) Q.push(MP(rand()%10,rand()%10));
    for(int i=0;i<10;i++)
    {
        cout<<Q.top().fi<<" "<<Q.top().sc<<endl;
        Q.pop();
    }
    
    return 0;
}