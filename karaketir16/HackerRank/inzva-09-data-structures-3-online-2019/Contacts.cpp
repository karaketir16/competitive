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
#define mid(a, b) ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;
struct Node
{
    char c;
    vector<Node*> ch;
    int many = 0;
    Node()
    {
        ch = vector<Node*> (30, NULL);
    }
};
void add(Node* head, int x, string &s)
{
    head->many++;
    
    if(x==s.size()) return;
    
    if(head->ch[s[x]-'a'])
    {
        add(head->ch[s[x]-'a'], x+1, s);
    }
    else
    {
        head->ch[s[x]-'a'] = new Node;
        add(head->ch[s[x]-'a'], x+1, s);
    }
}
lint count(Node* head, int x, string &s)
{
    if(x==s.size()) return head->many;
    if(head->ch[s[x]-'a'])
    {
        return count(head->ch[s[x]-'a'], x+1, s);
    }
    else
    {
        return 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    Node* head = new Node;
    while(q--)
    {
        string s;
        cin>>s;
        if(s == "add")
        {
            cin>>s;
            add(head, 0, s);
        }
        else
        {
            cin>>s;
            cout<<count(head, 0, s)<<"\n";
        }
    }
    return 0;
}
