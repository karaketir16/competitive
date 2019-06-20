#include <bits/stdc++.h>
using namespace std;

#define MOD (lint)(1e9+7) 
#define BN (lint)(1e9) 
typedef long long int lint;
lint gcd(lint a, lint b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}
lint ekok(lint a, lint b)
{
    return (a*b)/gcd(a, b);
}
vector<int> lucky;
vector<int> les;
vector<int> grea;
vector<int> use;
void lky(int x, int y, int z)
{
    if (z == 10) return;

    lucky.push_back(x*10 + y);

    lky(10*x +y, 4, z+1);
    lky(10*x +y, 7, z+1);
}
int fonk(int x)
{
    //Less part    
    int ls = les.size();
    int gr = grea.size();
    // cout << "ls: "<<ls<<endl;
    lint res = 0;
    for(int i = 0; i <= (1<<ls); i++)
    {
        int tot = __builtin_popcount(i);
        int katsayi = (tot % 2 == 0 ? -1:1);
        lint ans = 1;
        for(int j = 0; j < ls; j++)
        {
            if((1<<j) & i)
            {
                ans = ekok(ans, les[j]);
                // cout<<les[j]<<' ';
            }
            if(ans > BN) break;
        }
        // cout<<endl;
        ans = x/ans;
        res += katsayi*ans;
    } 

    res += (upper_bound(use.begin(), use.end(), x) - use.begin());

    return res;
}
int main()
{    
    lky(0, 4, 1);
    lky(0, 7, 1);
    sort(lucky.begin(), lucky.end());
    for(vector<int>::iterator it = lucky.begin(); it != lucky.end(); it++)
    {
        for(vector<int>::iterator jt = it + 1; jt != lucky.end();)
        {
            if( (*jt) % (*it) == 0 )  lucky.erase(jt);
            else jt++;
        }
        if((lint)(*it)*(*it) > BN) grea.push_back(*it);
        else les.push_back(*it);
    }
    int gr = grea.size();
    set<int> ss;
    for(int i = 0; i < gr; i++)
    {
        for(int j = grea[i]; j < BN; j+=grea[i])
        {
            ss.insert(j);
        }
    }
    for(set<int>::iterator it = ss.begin(); it != ss.end();)
    {
        bool can = false;
        for(auto& a: les) 
            if((*it)%a == 0)
            {
                can = true;
                break;
            } 
        
        if(can)
        {
            ss.erase(it++);
        }  
        else it++;
    }

    use = vector<int> (ss.begin(), ss.end());

    int a, b;
    cin >> a >> b;
    cout << fonk(b) - fonk(a-1);
    // for(auto a: les) cout << a<<endl;
    // set<int> xx = {1,2,3,4,5,6};
    // for(set<int>::iterator it = xx.begin(); it != xx.end();it++)
    // {
    //     if(*it == 3) 
    //     {
    //         xx.erase(it++);
            
    //     }
    //     cout<<"dbg: "<<*it<<endl;
    // }
// cout <<"g: "<<grea.size()<<endl;
// cout << fonk(5);
    // for(int i = 0; i < 100; i++) cout <<i<<": "<< fonk(i)<<endl;
    return 0;
}