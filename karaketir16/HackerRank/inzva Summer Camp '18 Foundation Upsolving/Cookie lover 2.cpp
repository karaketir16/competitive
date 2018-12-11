#include <bits/stdc++.h>
using namespace std;


int main() {
    deque<pair<int,int> > liste;
    int n,k;
    cin>>n>>k;
    vector<int> cookies(n);
    for(int i=0;i<n;i++)
    {
        cin>>cookies[i];
    }
    for(int i=0;i<k;i++)
    {
        while(liste.size()>0&&liste.back().first<cookies[i])
        {
            liste.pop_back();
        }
        liste.push_back(make_pair(cookies[i],i));
    }
    cout<<liste.front().first<<" ";
    if(liste.front().second==0)
    {
        liste.pop_front();
    }
    for(int i=1,j=k;j<n;i++,j++)
    {
        while(liste.size()>0&&liste.back().first<cookies[j])
        {
            liste.pop_back();
        }
        liste.push_back(make_pair(cookies[j],j));
        cout<<liste.front().first<<" ";
        if(liste.front().second==i)
        {
            liste.pop_front();
        }
    }
    return 0;
}
