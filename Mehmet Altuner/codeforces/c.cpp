#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
    vector <int_fast64_t> exists(200405, 0);
    int n;
    
    scanf("%d", &n);
    vector <lli> ar(n+1);
    lli sum = 0;
    
    for(int i=0; i<n; i++){
        scanf("%lli", &ar[i]);
        exists[ar[i]]++;
        sum += ar[i];
    }

    lli k = 0;

    for(int i=0; i<n; i++){
        sum -= ar[i];
        exists[ar[i]]--;
        for(int j=0; j<n; j++){            
            exists[ar[j]]--;
            if(exists[sum - ar[j]]){
                k++;
                cout << i+1 << "as" << endl;
                break;
            }
            exists[ar[j]]++;
                
        }
        sum += ar[i];
        exists[ar[i]]++;
    }

    printf("%lli\n", k);

    for(int i=0; i<n; i++){
        sum -= ar[i];
        exists[ar[i]]--;
        for(int j=0; j<n; j++){            
            exists[ar[j]]--;
            if(exists[sum - ar[j]]){
                cout << i + 1 << " ";
                break;
            }
            exists[ar[j]]++;
                
        }
        sum += ar[i];
        exists[ar[i]]++;
    }

    return 0;
}
