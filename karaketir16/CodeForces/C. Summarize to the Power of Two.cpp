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
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<bool> used(n,0); 
    int count=0;
    for(int i=0;i<n;i++)
    {
        //cout<<endl;
        for(int j=0;j<31;j++)
        {
            int test=(1<<j);
            //cout<<"kaydirilan: "<<test<<endl;
            int aranan=test-arr[i];
            //cout<<"aranan"<<aranan<<endl;;
            //if(aranan==)
            auto t = lower_bound(arr.begin(),arr.end(),aranan);
            if(t!=arr.end()&&*t==aranan)//bulundu
            {
                //cout<<"bulundu"<<endl;
                if(t-arr.begin()==i)//kendisi ise
                {
                    if(i!=n-1)//en son degil ise
                    {
                        t++;
                        if(*t==aranan)//sonraki de ayni ise
                        {
                            //cout<<i<<" true yapildi"<<endl;
                            used[i]=1;
                            count++;
                            break;
                        }
                    }

                }
                else
                {
                    //cout<<i<<" true yapildi"<<endl;
                    used[i]==1;
                    count++;
                    break;

                }

            }
            else
            {
                //cout<<"bulunamadi"<<endl;
            }


        }
    }

    
/*
    for(int i=0;i<n;i++)
    {
        cout<<used[i]<<" ";
        if(used[i]==false) count++;
    }
    cout<<endl;
    cout<<count;
    */
   cout<<n-count;
    return 0;
}