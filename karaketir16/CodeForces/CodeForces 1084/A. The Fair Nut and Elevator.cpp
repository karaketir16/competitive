#include<iostream>
#include<algorithm>
#include <vector>


using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    int total=0;
    int total_kisi=0;
    for(int i =0 ; i<n ;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int kat = 0;

    //cout<<kat<<endl;
    int result = 0;
    for(int i=0;i<n;i++)
    {
        //cout<<"abs: "<<abs(i-kat)<<endl;
        result+=2*arr[i]*(abs(kat-i)+i+kat);
        //cout<<result<<endl;
    }
    for(int i=1;i<n;i++)
    {
        int result1 = 0;
        for(int i=0;i<n;i++)
        {
        //cout<<"abs: "<<abs(i-kat)<<endl;
            result1+=2*arr[i]*(abs(kat-i)+i+kat);
        //cout<<result<<endl;
        }
        result = min(result1, result);
    }
    cout<<result;
    return 0;
}