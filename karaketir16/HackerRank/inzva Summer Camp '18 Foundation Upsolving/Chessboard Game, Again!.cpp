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

struct Kare
{

};

vector<vector<int>> brd;
int greedy(int x,int y)
{
    
    if((x<1||x>15)||(y<1||y>15)) return -1;
    if(brd[x][y]!=-1) return brd[x][y];
    //cout<<"x: "<<x<<" y: "<<y<<endl;
    /*
    if(brd[x][y]==2) return 1;
    return 0;
    */
   set<int> olanlar;
   olanlar.insert(greedy(x+1,y-2));
   olanlar.insert(greedy(x-1,y-2));
   olanlar.insert(greedy(x-2,y+1));
   olanlar.insert(greedy(x-2,y-1));
   for(int i=0;i<5;i++)
   {
       
       if(olanlar.find(i)==olanlar.end())
       {
           //cout<<"test";
           return i;
       }
   }
   return -1;


}
int main()//1 Lose 2 Win
{
    
    vector<int> row(19,-1);
    vector<vector<int>> board(19,row);
    brd=board;
    for(int i=1;i<16;i++)
    {
        for(int j=1;j<16;j++)
        {
            brd[i][j]=greedy(i,j);
        }
    }
    /*
    
    cout<<endl;
    for(int i=1;i<16;i++)
    {
        for(int j=1;j<16;j++)
        {
            cout<<brd[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    

    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int result=0;
        while(n--){
            int x;
            int y;
            cin>>x;
            cin>>y;
            //cout<<board[x][y]<<" ";
            result^=brd[x][y];

        }
        if(result!=0)
        {
            cout<<"First\n";
        }
        
        else
        {
            cout<<"Second\n";
        }
        
        
    }
    


    return 0;
}