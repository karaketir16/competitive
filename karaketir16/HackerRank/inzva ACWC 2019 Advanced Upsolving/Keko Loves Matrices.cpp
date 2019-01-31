#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1005
#define MOD 1000000007
#define mid ((a+b)/2)
#define ALL(x) x.begin(),x.end()
#define INPUT(v) for(auto &x:v)cin>>x
#define FOR0(x) for(int i = 0;i<x;i++)
#define FOR1(x) for(int i = 1;i<=x;i++)
#define FORE(v) for(auto &a:v)
using namespace std;
typedef long long int lint;


int main()
{
    std::ios::sync_with_stdio(false);
    vector<int> results(N); //0 now 1 old

    vector<vector<int>> v(N, vector<int> (N)); //0 now 1 old

    int n;
    cin>> n;

    for(int i = 0; i<n;i++)
    {
        for(int j =0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    int res=0;

    for(int i = 0; i<n;i++)
    {
        int row= 0;
        for(int j =0; j < n; j++)
        {

            res+=(v[i][j]*v[j][i]);
            row+=(v[i][j]*v[j][i]);
        }
        results[i] = row%2;
    }
    /*
    for(int i =0; i < n; i++)
    {
        cout<< results[i]<<" ";
    }
    cout<<endl;
    */
    res%=2;
    int q;
    cin>>q;
    while(q--){
        int x;
        cin >> x;
        if(x == 1)
        {
            int i;
            cin>>i;
            i--;
            int row= 0;
            for(int j =0; j < n; j++)
            {

                v[i][j] = !v[i][j];
                if(i!=j) if(v[j][i] == 1) results[j] = !results[j]; 
                row+=(v[i][j]*v[j][i]);
            }
            results[i] = row%2;
            int a =0;
            for(int i =0; i < n; i++)
            {
                a+=results[i];
            }
            res = a%2;
        }
        if(x == 2)
        {
            int j;
            cin>>j;
            j--;
            int row= 0;
            for(int i =0; i < n; i++)
            {            
                v[i][j] = !v[i][j];
                if(i!=j) if(v[j][i] == 1) results[i] = !results[i];     
                row+=(v[i][j]*v[j][i]);
            }
            results[j] = row%2;
            int a =0;
            for(int i =0; i < n; i++)
            {
                a+=results[i];
            }
            res = a%2;
            
        }
        if(x == 3) cout<< res%2;
        /*
        cout<<"a\n";
        for(int i = 0; i<n;i++)
        {
            for(int j =0; j < n; j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"b\n";
        for(int i =0; i < n; i++)
        {
            cout<< results[i]<<" ";
        }
        cout<<endl;
        */
    }
    
    //cout << root;
    return 0;
}