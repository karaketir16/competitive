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
const int MAX=305;
int arr[MAX][MAX];
int matrix[MAX][MAX];
int d;
void fill()
{
    for(auto &a:arr)
    {
        for(auto &b:a)
        {
            b=0;
        }
    }
    for(auto &a:matrix)
    {
        for(auto &b:a)
        {
            b=-1;
        }
    }
}
int fnk(int i,int j, int left, int up)
{
    if(left==0||up==0) return 0;
    cout<<i<<" "<<j<<" "<<left<<" "<<up<<endl; 
    //if(matrix[i][j]!=-1) return matrix[i][j];
    if(i==1&&j==1) return 1;
    if(arr[i][j]==0) return 0;
    int total=0;
    if(up>0) total+=fnk(i-1,j,d,up-1);
    if(left>0) total+=fnk(i,j-1,left-1,d);
    //matrix[i][j]=total;
    return total;


}
int main()
{
    fill();
    int r,c;
    cin>>r>>c>>d;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin>>arr[i][j];
        }
    }
    matrix[1][1]=1;
    cout<<fnk(r,c,d,d)<<endl;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;


}