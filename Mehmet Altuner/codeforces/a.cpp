#include <bits/stdc++.h>

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while(t--){
        long long int a, b, k;
        scanf("%lli %lli %lli", &a, &b, &k);
        long long int res = (k - (k/2))*a - (k/2)*b;
        printf("%lli\n", res);
    }
    return 0;
}
