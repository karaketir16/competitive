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

int main()
    {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //vector<vector<vector<int>*>> sizes(n);
    deque<vector<int>> arrays;
    set<int> son_elemanlar;
    for(auto x:arr)//N
    {
        
        for(auto test:arrays)
        {
            for(auto t: test) cout<<t<<" ";
            cout<<endl;
        }
        cout<<endl;
        
        bool koyuldu=0;
//        for(int i=arrays.size()-1;i>=0;i--)
 //       {
            //cout<<"denenen sayi: "<<x<<" denenen dizi"<<arrays[i].back()<<endl;
        auto it =son_elemanlar.upper_bound(x);
        if(it==son_elemanlar.end())
        {
            son_elemanlar.erase(arrays.back().back());
            arrays[arrays.size()-1][arrays[arrays.size()-1].size()-1]=x;
            son_elemanlar.insert(x);
            /*
            int i=distance(son_elemanlar.begin(),it);
            i--;
            arrays.insert(arrays.begin()+i,arrays[i]);
            i++;
            arrays[i].pb(x);
            son_elemanlar.insert(x);
            */
            /*
            int s=arrays[i].size();
            if(i+1<arrays.size())
            {
                arrays[i+1].size()== s;
                son_elemanlar.erase(arrays[i+1].back());
                arrays.erase(arrays.begin()+i+1);
                

            }
            */

            /*
            it--;
            //if((*it)==x) continue;
            int i=distance(son_elemanlar.begin(),it);
            arrays.insert(arrays.begin()+i,arrays[i]);
            i++;
            arrays[i].pb(x);
            son_elemanlar.insert(x);
            int s=arrays[i].size();
            if(i+1<arrays.size())
            {
                arrays[i+1].size()== s;
                son_elemanlar.erase(arrays[i+1].back());
                arrays.erase(arrays.begin()+i+1);
                

            }
            */

        }

            
            /*
            if(x>arrays[i].back())
            {
                koyuldu=1;
                arrays.insert(arrays.begin()+i,arrays[i]);
                i++;
                arrays[i].pb(x);
                int s=arrays[i].size();
                if(i+1<arrays.size())
                {
                    arrays[i+1].size()== s;
                    arrays.erase(arrays.begin()+i+1);
                }
                break;
            }
            */

 //       }
//        if(koyuldu==0)
        else
        {
            if(it==son_elemanlar.begin())
            {
                son_elemanlar.erase(arrays[0][0]);
                arrays[0][0]=x;
                son_elemanlar.insert(x);
                /*
                if(arrays.size()>1)
                {
                son_elemanlar.erase(arrays[1].back());
                arrays.erase(arrays.begin()+1);
                }
                */
            

            }
            
            else
            {
        
                it--;
                if((*it)==x) continue;
                int i=distance(son_elemanlar.begin(),it);
                son_elemanlar.erase(arrays[i][i-1]);
                arrays[i][i-1]=x;
                son_elemanlar.insert(x);
                /*
                arrays.insert(arrays.begin()+i,arrays[i]);
                i++;
                arrays[i].pb(x);
                son_elemanlar.insert(x);
                int s=arrays[i].size();
                if(i+1<arrays.size())
                {
                    arrays[i+1].size()== s;
                    son_elemanlar.erase(arrays[i+1].back());
                    arrays.erase(arrays.begin()+i+1);
                    

                }
                */
            }
            



            
            
        }

    }
    cout<<arrays.back().size();


    return 0;


}