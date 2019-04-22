#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrice(105, vector<int>(105, INT_MAX/2));
int main()
{
    
    int n, kk;
    cin>>n>>kk;

    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        matrice[x][y] = 1;
        matrice[y][x] = 1;
        matrice[x][x] = 0;
        matrice[y][y] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <=n ; k++)
            {
                matrice[i][j] = min(matrice[i][j], matrice[i][k] + matrice[k][j]);
            }
        }
    }
    vector<bool> marked(105,  0);  
    int result =0;
    vector<int> num(105);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            //cerr<<matrice[i][j]<<' ';
            // if(matrice[i][j] > kk &&( !marked[i] && !marked[j]))
            // {
            //     result++;
            //     marked[i] = true;
            // }
            if(matrice[i][j] > kk) num[i]++;
        }
        //cerr<<'\n';
    }
    for(int i = 1; i <= n; i++)
    {
        vector<pair<int, int>> vp;
        for(int i = 1; i <= n; i++)
        {
            vp.push_back({num[i], i});
        }
        sort(vp.rbegin(), vp.rend());
        if(vp[0].first == 0) break;

        int m = vp[0].second;
        result++;

        for(int i = 1; i <= n; i++)
        {
            if(matrice[i][m] > kk) num[i]--;
        }
        num[m] = 0;
    }
    


    cout<<result;
    return 0;   
}