#include <bits/stdc++.h>

using namespace std;
typedef long long int lint;
int main(){
    int n, m;
    cin>>n>>m;
    lint tot=0;
    int start = 1;
    while(m--){
        int x;
        cin>>x;
        if(x<start)
        {
            tot += (n-(start-x));
        }
        else{
            tot += (x-start);
        }
        start=x;
    }
    cout<<tot;
    return 0;
}