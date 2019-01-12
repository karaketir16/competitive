#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
    vector <pair <int, int>> occurence(200005, make_pair(0, 0));
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        occurence[x].first++;
        occurence[x].second = x;
    }

    sort(occurence.begin(), occurence.end(), greater<pair <int, int>>());

    for(int i=0; i<k; i++){
        printf("%d ", occurence[0].second);
        occurence[0].first = (occurence[0].first) / k + 1;
        sort(occurence.begin(), occurence.end(), greater<pair <int, int>>());
    }
    return 0;
}
