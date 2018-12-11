#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,t;
    cin>>n>>t;
    vector<int> cookies(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>cookies[i];
    }
    int maxx=0;
    int total=0;
    total+=cookies[0];
    for(int i=0,j=0;true;)
    {
        //cout<<"i: "<<i<<" j: "<<j<<" total: "<<total<<endl;
        if(total<=t) maxx=max(maxx,j-i+1);
        if(total>t)
        {
            i++;
            if(i>=n) break;
            total-=cookies[i-1];
            
        }else
        {
            j++;
            if(j>=n) break;
            total+=cookies[j];
        }
        
    
    }
    cout<<maxx;
    return 0;
}
