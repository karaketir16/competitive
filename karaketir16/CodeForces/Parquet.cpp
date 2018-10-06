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
using namespace std;
int imp()
{
    cout<<"IMPOSSIBLE\n";
    exit(0);
}


int main()
{
    char matrix[105][105];
    
    for(int i=0;i<105;i++)
    {
        for(int j=0;j<105;j++)
        {
            matrix[i][j]='o';
        }
    }
    
    int n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;
    int om=0;
    int on=0;
    if(n*m%2!=0) imp();
    if(m%2==1)
    {
        b-=n/2;
        if(b<0) imp();
        m--;
        om++;
        for(int i=1;i<=n/2;i++)
        {
            char x='y';
            if(i%2==0) x='z';
            matrix[2*i][m+1]=matrix[2*i-1][m+1]=x;
        }
    }
    if(n%2==1)
    {
        a-=m/2;
        if(a<0) imp();
        n--;
        on++;
        for(int j=1;j<=m/2;j++)
        {
            char x='y';
            if(j%2==0) x='z';
            matrix[n+1][2*j]=matrix[n+1][2*j-1]=x;
        }
    }
    //cout<<a;
    if(a%2==1) a--;
    if(b%2==1) b--;
    if(m*n>2*a+2*b+4*c) imp();
    char ch='n';
    int total=0;
    int need=m*n;

    for(int i=1;i+1<=n;i+=2)
    {
        for(int j=1;j+1<=m;j+=2)
        {
            char x='a';
            if(((i+1)%4)^((j+1)%4))x='b';
            matrix[i][j]=matrix[i][j+1]=matrix[i+1][j]=matrix[i+1][j+1]=x;
        }
    }
    int i=1;
    int j=1;
    for(;i<=n;i+=2)
    {
        for(j=1;j<=m;j+=2)
        {
            if(a>1)
            {
                a-=2;
                char x='c';
                if((j-1)%4==0) x='d';
                matrix[i+1][j]=matrix[i+1][j+1]=x;
            }
            else if(b>1)
            {
                b-=2;
                //cout<<"TeST";
                char x='e';
                if((i-1)%4==0) x='f';
                matrix[i][j+1]=matrix[i+1][j+1]=x;
            }
        }
    }
    //cout<<"n: "<<n<<" m: "<<m<<endl;
    /*
    for(;i<=n;i+=2)
    {
        if(j>m) j=1;
        for(;a>1&&j<=m;j+=2,a-=2)
        {
            //cout<<"test";
            char x='c';
            if((j-1)%4==0) x='d';
            matrix[i+1][j]=matrix[i+1][j+1]=x;
            
        }
        if(a==0) {break;}
    }
    cout<<i<<" "<<j;
    if(j>m) {j=1;i+=2;cout<<"t";}
    for(;i<=n;i+=2)
    {
        cout<<"TEST1";
        if(j>m) {j=1;}
        for(;b>1&&j<=m;j+=2,b-=2)
        {

            cout<<"test";
            char x='e';
            if((i-1)%4==0) x='f';
            matrix[i][j+1]=matrix[i+1][j+1]=x;
            
        }
        if(a==0) {i+=2;break;}
    }
    */
    m+=om;
    n+=on;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
    return 0;
}