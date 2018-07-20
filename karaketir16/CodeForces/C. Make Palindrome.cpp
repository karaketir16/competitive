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
    vector<int> alfa(26,0);
    char ch;
    int total=0;
    scanf("%c",&ch);    
    while(ch!='\n')
    {
        total++;
        alfa[ch-'a']++;
        scanf("%c",&ch);
        //cout<<"girdi";
    }
    //cout<<"girdi end";
    /*
    for(int a=0;a<26;a++)
    {
        char c=a+'a';
        cout<<c<<": "<<alfa[a]<<endl;
    }
    */
    //cout<<"test\n";
    bool tek=true;
    if(total%2==0)
    {
        tek=false;
    }
    
    int saved=-1;
    int i=0;
    int j=25;
    while(i!=j)
    {
        
        if(alfa[j]%2==0)
        {
            j--;
            
        }
        
        else//if(alfa[j]%2==1)
        {
            /*
            if(bir_tek==true)
            {
                bir_tek=false;
                saved=j;
                j--;
            }
            else
            */
            
            if(alfa[i]%2==0)
            {
                i++;
            }
            else //if(alfa[i]%2==1)
            {
                alfa[i]++;
                alfa[j]--;
            }
            
            
        }
        
    }
    
    if(tek)
    {
        saved=i;
    }
    /*
    for(int a=0;a<26;a++)
    {
        char c=a+'a';
        cout<<c<<": "<<alfa[a]<<endl;
    }
    cout<<"saved: "<<saved;
    */

    for(int a=0;a<26;a++)
    {
        alfa[a]/=2;
    }
    vector<int> ikinci=alfa;
    for(int a=0;a<25;a++)
    {
        char c=a+'a';
        while(alfa[a]--)
        {
            cout<<c;
        }
    }
    if(tek)
    {
        char c=saved+'a';
        cout<<c;
    }
    for(int a=25;a>=0;a--)
    {
        char c=a+'a';
        while(ikinci[a]--)
        {
            cout<<c;
        }
    }


    return 0;
}