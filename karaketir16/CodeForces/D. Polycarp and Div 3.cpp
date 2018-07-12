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
    vector<int> arr;
    char ch;
    scanf("%c",&ch);
    
    while(ch!='\n')
    {
        arr.pb((ch-48)%3);
        scanf("%c",&ch);
    }
    int count=0;
    int n= arr.size();
    vector<bool> used(n,false);
    for(int i=0;i<n;i++)
    {
        if(used[i]) continue;

        if(arr[i]==0)
        {
            count++;
            used[i]=true;
            continue;
        }
        if(arr[i]==1&&i+1<n)
        {
            if(arr[i+1]==2)
            {
                count++;
                used[i]=used[i+1]=true;
                continue;
            }
            if(arr[i+1]==1&&i+2<n)
            {
                if(arr[i+2]==1)
                {
                    count++;
                    used[i]=used[i+1]=used[i+2]=true;
                    continue;
                }
            }
            
        }
        if(arr[i]==2&&i+1<n)
        {
            if(arr[i+1]==1)
            {
                count++;
                used[i]=used[i+1]=true;
                continue;
            }
        }
        //if(i!=n-1) count++;
    }
    /*
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]==0)
        {
            if((arr[i-1]+arr[i+1])==3)
            {
                if(used[i-1]==false&&used[i+1]==false)
                {
                    count--;
                    count--;
                }
            }
        }

    }
    */
    cout<<count;
    //cout<<arr.size()<<" test";
    
    return 0;
}