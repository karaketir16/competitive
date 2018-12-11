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
using namespace std;




int main()
{
    int alf=10;
    vector<int> harfler(10,0);
    vector<vector<int>> matrix(N*60,harfler);
    /*
    string ahmet="ahmet";
    cout<<ahmet[0];
    */
    int n;
    cin>>n;
    int node_sayisi=1;
    set<int> lasts;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int a=1;
        int last=0;
        int eski_node_sayisi=node_sayisi;
        for(auto h:s)
        {
            
            int harf=h-97;
            if(matrix[a][harf]!=0)
            {
                a = matrix[a][harf];
                
            if(lasts.find(a)!=lasts.end())
            {
                cout<<"BAD SET\n"<<s;
                return 0;
            }

                //cout<<s;
                //cout<<endl;
                /*
                for(auto a:matrix)
                {
                    for(auto b: a)
                    {
                        cout<<b<<" ";
                    }
                    cout<<endl;
                }
                */
                
            } 
            else
            {
               
            if(lasts.find(a)!=lasts.end())
            {
                cout<<"BAD SET\n"<<s;
                return 0;
            }
            node_sayisi++;
            matrix[a][harf]=node_sayisi;
            a = node_sayisi;
                

            }
            last=a;


        }
        if(eski_node_sayisi==node_sayisi)
        {
            cout<<"BAD SET\n"<<s;
            return 0;
        }

        if(lasts.find(a)!=lasts.end())
        {
            cout<<"BAD SET\n"<<s;
            return 0;
        }

            lasts.insert(last);


        
        /*
        cout<<endl;
        for(auto l: lasts)
        {
            cout<<l<<" ";
        }
        cout<<endl;
        */
        /*
        for(auto a:matrix)
        {
            for(auto b: a)
            {
                cout<<b<<" ";
            }
            cout<<endl;
        }
        */
    }
    cout<<"GOOD SET\n";


    return 0;
}