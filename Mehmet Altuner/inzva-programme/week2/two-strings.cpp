#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(char *s1, char *s2) {
    int h1[1000];
    int h2[1000];
    int res[1000];
    
    for(int i=0; i<1000; i++){
        res[i] = 0;
        h1[i] = 0;
        h2[i] = 0;
    }
    
    int len1 = strlen(s1), len2 = strlen(s2);
    
    for(int i=0; i<len1; i++){
        h1[(int)s1[i]] = 1;
    }
    
    for(int i=0; i<len2; i++){
        h2[(int)s2[i]] = 1;
    }
    
    for(int i=0; i<1000; i++){
        res[i] = h1[i] + h2[i];
    }
    
    for(int i=0; i<1000; i++){
        if(res[i] >= 2){
            return "YES";
        }
    }
    
    return "NO";

}

int main()
{
    int q;
    cin >> q;

    while(q--){
        char s1[(int)1e5 + 10], s2[(int)1e5 + 10];
        cin >> s1;
        cin >> s2;
        cout << twoStrings(s1, s2) << endl;
    }
    
    return 0;
}
