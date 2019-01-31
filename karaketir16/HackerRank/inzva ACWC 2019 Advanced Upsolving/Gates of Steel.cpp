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
int main()
{
    std::ios::sync_with_stdio(false);
    set<pair<int, int>> points;
    set<pair<pair<int, int>, pair<int, int>>> fences;
    int i =0, j =0;
    int old_i=INT_MAX, old_j = INT_MAX;
    char c;
    int t;
    cin>>t;
    int tot = 0;
    
    points.insert({i, j});
    while(t--){
        cin >> c;

        switch (c)
        {
            case 'N':
                i++;
                break;
            
            case 'S':
                i--;
                break;
            
            case 'E':
                j++;
                break;
            
            case 'W':
                j--;
                break;
        
            default:
                break;
        }

        if(fences.count({{old_i, i},{old_j, j}}) == 0   &&   points.count({i, j}) > 0)
        {
            tot ++;
        }

        fences.insert({{old_i, i},{old_j, j}});

        fences.insert({{i, old_i},{j, old_j}});

        points.insert({i, j});

        old_i = i;
        old_j = j;
    }
    
    cout << tot;



    return 0;
}