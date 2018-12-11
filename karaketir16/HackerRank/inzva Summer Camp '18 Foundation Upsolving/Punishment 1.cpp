#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 1000005
#define MOD 1000000007
using namespace std;
typedef long long int lint;
/*
lower bound al esit mi diye bak ileri dogru git
*/
int main()
{
    int n;
    int m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    /*
    onceki elemen son eklenen sayi
    */
   
    int son_eklenen=0;
    int sonuc=0;
    int kok_sayisi=0;
    
    if(m==0)
    
    {
        int sifir_sayisi=0;
        for(auto a: arr)
        {
            if(a==0)
            {
                sifir_sayisi++;
            }
        }
        if(sifir_sayisi==1)
        {
            cout<<n-1;
            
            return 0;
        }
        else if(sifir_sayisi>1)
        {
            int diger=n-sifir_sayisi;
            cout<<(n*(n-1)/2)-(diger*(diger-1)/2);
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }

    }
    
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==0)
        {
            son_eklenen=0;
            continue;
        }
        int simdi_eklenen=0;
        if(i>0)
        {
            if(arr[i-1]==arr[i])
            {
                //cout<<i<<" test: "<<son_eklenen<<endl;
                sonuc+=son_eklenen;
                continue;
            }
        }
        if(m%arr[i]!=0)//tam bolmuyorsa
        {   
        }
        else//tam boluyorsa
        {
            //cout<<"i: "<<i<<endl; 
            int aranan=m/arr[i];
            if(arr[i]*arr[i]==m) son_eklenen=0;
            auto it=lower_bound(arr.begin(),arr.end(),aranan);
            if(it!=arr.end())//bulunursa
            {
                
                if(aranan==arr[i])
                {
                    while(it!=arr.end()&&(*it)==aranan)
                    {
                        it++;
                        kok_sayisi++;
                    }
                    son_eklenen=0;
                    continue;
                }
                
                while(it!=arr.end()&&(*it)==aranan)
                {
                    /*
                    if(distance(arr.begin(),it)==i)
                    {
                        it++;
                        continue;
                    }
                    */
                    
                    simdi_eklenen++;
                    it++;
                }


            }
            else//bulunmazsa
            {
                //do nothing
            }
        }
        sonuc+=simdi_eklenen;
        son_eklenen=simdi_eklenen;
    

    }
    /*
    cout<<"kok sayisi: "<<kok_sayisi<<endl;
    cout<<"kok eklenmeden onceki sonuc: "<<sonuc<<endl;
    */
    /*
    int a=5;
    if(kok_sayisi>=2)
    {
        
    
        a = kok_sayisi*(kok_sayisi-1);
        cout<<"test: "<<kok_sayisi<<" "<<(kok_sayisi-1)<<endl;
    }
    */
    //cout<<kok_sayisi*(kok_sayisi-1)<<endl;
    if(kok_sayisi>=2)
    {
        
    
        sonuc+= kok_sayisi*(kok_sayisi-1);
        cout<<sonuc/2;
    }
    else
    {
        cout<<sonuc/2;
    }
    
    return 0;
    
}