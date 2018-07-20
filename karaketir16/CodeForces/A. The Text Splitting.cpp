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
int n,p,q;
string s;
void print(vector<int> v)
{
    int i=0;
    cout<<v.size()<<'\n';
    for(auto x:v)
    {
        //cout<<x<<endl;
        string a;
        while(x--)
        {
            a.pb(s[i]);
            i++;
        }
        cout<<a<<'\n';
    }
}
/*
void fonk(int kalan,vector<int> v)
{
    cout<<kalan<<endl;
    if(kalan<0) return;
    if(kalan==0)
    {
        print(v);
        exit(0);
    }
    if(kalan>0)
    {
        vector<int> temp=v;
        temp.pb(p);
        fonk(kalan-p,temp);
        temp=v;
        temp.pb(q);
        fonk(kalan-q,temp);
    }
}
*/
void fill(vector<int> &v,int x)
{
    for(int i=0;i<n+1;i++)
    {
        if(v[i]&&i+x<n+1)
        {
            v[i+x]=1;
        }
    }
}
int main()
{

    cin>>n>>p>>q;
    cin>>s;
    vector<int> blank;
    vector<int> numbers(n+1,0);
    numbers[0]=1;
    fill(numbers,p);fill(numbers,q);

    if(numbers[n]==0)
    {
        cout<<-1;
        return 0;
    }
    

    int kalan=n;
    int i=0;
    int sayac=0;
    while(kalan%q!=0)
    {
        sayac++;
        kalan-=p;
    }
    while(kalan>0)
    {
        sayac++;
        kalan-=q;
    }





    kalan=n;
    i=0;
    cout<<sayac<<'\n';
    while(kalan%q!=0)
    {
        string a;
        int x=p;
        while(x--)
        {
            a.pb(s[i]);
            i++;
        }
        cout<<a<<'\n';
        kalan-=p;
    }
    while(kalan>0)
    {
        string a;
        int x=q;
        while(x--)
        {
            a.pb(s[i]);
            i++;
        }
        cout<<a<<'\n';
        kalan-=q;
    }
    //fonk(n,blank);
    //cout<<-1;
    return 0;
}