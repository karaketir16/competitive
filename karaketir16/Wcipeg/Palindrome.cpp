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
const int MAX=5002;
int matrix[3][MAX];

void fill()
{
    for(auto &a:matrix)
    {
        for(auto &b:a)
        {
            b=-1;
        }
    }
}

int fonk(string &s, int i, int j)
{
    if(matrix[i][j]!=-1) return matrix[i][j];
    if(i>=j) return 0;

    int result=0;
    if(s[i]==s[j]) result = fonk(s,i+1,j-1);
    else result = min(fonk(s,i+1,j)+1,fonk(s,i,j-1)+1);
    matrix[i][j]=result;
    return result;
}
int main()
{
    fill();
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<fonk(s,0,n-1)<<"\n";
    return 0;

}