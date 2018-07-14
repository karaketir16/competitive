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

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    int count =0;
    sort(arr.begin(),arr.end());
    vector<bool> used(n,false);
    for(int i=0;i<n;i++)
    {
        auto x = upper_bound(arr.begin(),arr.end(),arr[i]);
        //int t=x-arr.begin();
        if(x==arr.end()) break;
        
        else 
        {
            if(used[x-arr.begin()]==true)//kullanilmissa
            {
                x++;
                while(x!=arr.end())//sona kadar
                {
                    if(used[x-arr.begin()]==false)//kullanilmamisa denk gelince
                    {
                        count++;
                        used[x-arr.begin()]=true;
                        break;
                    }
                    x++;
                }
                if(x==arr.end())
                {
                    break;
                }
            }
            else
            {
                count++;
                used[x-arr.begin()]=true;
            }
                      
        }
        
    }
    printf("%d",count);
    return 0;
}