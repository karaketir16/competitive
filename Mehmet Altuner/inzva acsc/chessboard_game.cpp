// https://www.hackerrank.com/contests/inzva-acsc-foundation-6/challenges/chessboard-game-again-1/

#include <bits/stdc++.h>

using namespace std;

int moves[15 * 15][15 * 15];

bool contains(set <int> container, int element){
  for(auto c: container){
    if(element == c){
      return true;
    }
  }
  return false;
}

int grundy(int x, int y){
    if(x < 1 || y < 1 || x > 15 || y > 15)  
        return -1;

    if(moves[x][y])
        return moves[x][y];

    set <int> from_down;
    from_down.insert(grundy(x-2, y+1));
    from_down.insert(grundy(x-2, y-1));
    from_down.insert(grundy(x+1, y-2));
    from_down.insert(grundy(x-1, y-2));

    int i=0;
    while(true){
      if(!contains(from_down, i)){
        moves[x][y] = i;
        return i;
      }
      i++;
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int q, xorvalue = 0;
        cin >> q;
        while(q--){
            int x, y;
            cin >> x >> y;
            xorvalue = xorvalue ^ grundy(x, y);
        }
        if(xorvalue){
            cout << "First\n";
        }else{
            cout << "Second\n";
        }

    }

    return 0;
}
