#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,n;
    int total=0;
    cin>>n>>k;
    vector<int> cities(n);
    k--;
    for(int i=0;i<n;i++)
    {
        cin>>cities[i];
    }
    vector<bool> electiric(n,false);
    for(int i=0;i<n;i++)
    {
        if(electiric[i]==true)
        {
            continue;
        }
        bool edildi_mi=0;
        for(int j=k;j>=0;j--)
        {
            if(i+j>=n) continue;         
            if(cities[i+j]==1)
            {
                for(int l=0;l<=k;l++)//plant
                {
                    if(i+j+l<n)
                    {
                        electiric[i+j+l]=1;
                    }
                    if (i+j-l>=0)
                    {
                        electiric[i+j-l]=1;
                    }
                }
                total++;
                edildi_mi=1;
                break;
            }
        }
        if(!edildi_mi)
        {
            for(int j=0;j<=k;j++)
            {
                if(i-j<0) continue;         
                if(cities[i-j]==1)
                {
                    for(int l=0;l<=k;l++)//plant
                    {
                        if(i-j+l<n)
                        {
                            electiric[i-j+l]=1;
                        }
                        if (i-j-l>=0)
                        {
                            electiric[i-j-l]=1;
                        }
                    }
                    total++;
                    edildi_mi=1;
                    break;
                }
            }
            if(!edildi_mi)
            {
                cout<<-1;
                return 0;    
            }    
        }   
    }
    cout<<total;
    return 0;
}
