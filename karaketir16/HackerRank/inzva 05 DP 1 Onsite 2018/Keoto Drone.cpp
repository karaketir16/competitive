#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int lint;

int main() {
    int n,m;
    cin>>m>>n;
    vector<lint> mm(m);
    vector<vector<lint>> matrix(n, mm);

    for(int i = 0 ;i<n; i++)
    {
        for(int j=0;j<m;j++)
        {
            lint x;
            scanf("%lld", &x);
            matrix[i][j]=-1*x;
        }
    }

    for(int j=m-1;j>0;j--)
    {
        priority_queue<lint> qq;

        for(int i=n-1;i>=0;i--)
        {
            qq.push(matrix[i][j]);
            matrix[i][j-1]+=qq.top();
        }
    }
    /*
    for(int i = 0 ;i<n; i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<< matrix[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    lint maxx=matrix[0][0];
    
    for(int i=n-1;i>=0;i--)
    {
        maxx=max(maxx, matrix[i][0]);
    }
    
    printf("%lld", -1*maxx);
    return 0;
}
