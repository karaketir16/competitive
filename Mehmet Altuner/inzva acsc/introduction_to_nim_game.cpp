#include <bits/stdc++.h>

using namespace std;

int g, n, s;

int main(){
  cin >> g;
  while(g--){
    cin >> n;
    int sum=0;
    while(n--){
      cin >> s;
      sum ^= s;
    }
    if(sum == 0) cout << "Second\n";
    else cout << "First\n";
  }
  return 0;
}
