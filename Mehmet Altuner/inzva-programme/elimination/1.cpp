#include <bits/stdc++.h>
#define Z 1000000009

using namespace std;

typedef long long int lli;


lli pwr(lli base, lli to){
    if(to == 1)
        return base;

    lli down = pwr(to / 2);
    lli res;

    if(to % 2 == 0){
        res = down * down;
    }else{
        res = down * down * base;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    f[0] = 1; // base case
    lli t;
    scanf("%lli", &t);
    while(t--){
        lli n;
        vector <lli> ar(n);
        for(int i=0; i<n; i++)
            scanf("%lli", &ar[i]);
        
        for(int i=0; i<n; i++){
            ar[i] = pwr(3, pwr(2, ar[i]) % Z) % Z;
       }

        sort(ar.begin(), ar.end());
        for(int i=0; i<n; i++)
            printf("%lli ", ar[i]);
        
        if(t - 1 > 0)
            printf("--");
    }
    return 0;
}