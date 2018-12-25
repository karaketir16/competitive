#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long int lli;

int main(int argc, char const *argv[])
{
    vector <lli> ar;
    lli n, res = 0;
    scanf("%lli", &n);
    for(int i=0; i<n; i++){
        lli x;
        scanf("%lli", &x);
        auto res_it = upper_bound(ar.begin(), ar.end(), 2*x);
        if(res_it != ar.end()){
            res += ar.end() - res_it;
        }    
        auto ins_it = lower_bound(ar.begin(), ar.end(), x);
        ar.insert(ins_it, x);
    }
    printf("%lli", res+1);
    return 0;
}