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

int degerler[26];
char kk[305];
char nn[N];
int matrix[305][N];
int k ,n;
int get_int(int a, int b)
{
    if(a<0||a>=k||b<0||b>=n) return 0;
    else return matrix[a][b];
}
int main() {

    cin>>k>>n;
    for(int i=0;i<26;i++) cin>>degerler[i];
    scanf("%s", kk);
    scanf("%s", nn);

    for(int i=0;i<1;i++)
        for(int j=0;j<n;j++)
            if(kk[i]!=nn[j]) matrix[i][j] = get_int(i, j-1);
            else matrix[i][j] =get_int(i, j-1) +1;
    for(int i=1;i<k;i++)
        for(int j=0;j<n;j++)
            if(kk[i]!=nn[j]) matrix[i][j] = get_int(i, j-1);
            else matrix[i][j] =(get_int(i, j-1) + get_int(i-1, j-(degerler[kk[i-1]-'A']+1)))%MOD;

    cout<<matrix[k-1][n-1];
    return 0;
}
