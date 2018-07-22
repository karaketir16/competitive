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

#define pp pair<int,int>
typedef long long int lint;
/*
bool cmp(const pp &l,const pp &r)
{

    return l.first<r.first
}

struct compare {
    bool operator()(const pair<int, int>& value, 
                                const int& key)
    {
        return (value.first < key);
    }
    bool operator()(const int& key, 
                    const pair<int, int>& value)
    {
        return (key < value.first);
    }
};
*/

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> numbers;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        numbers.pb(MP(x,i));
    }
    sort(numbers.begin(),numbers.end());
    /*
    int x=0;
    x=1;
    int id=(int)(lower_bound(v.begin(),v.end(),MP(x,0),cmp)-v.begin());
    int onceki=id;
    int total=0;
    */
    lint total=0;
    int onceki=numbers[0].sc;
    for(int i=0;i<n;i++)
    {
        
        int id= numbers[i].sc;
        total+=abs(id-onceki);
        onceki=id;
    }
    cout<<total;
    

    return 0;
}