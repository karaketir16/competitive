#include <algorithm>
#include <functional>
#include <array>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++)
        cin >> ar[i];

    int m = 99999999;

    for(int i=0; i<n; i++){
        m = min(m, ar[i] - lower_bound(ar + i + 1, n - i, ar[i]));
    }

    cout << m;
    return 0;
}
