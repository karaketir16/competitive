// https://csacademy.com/contest/round-86/task/penguin-dance/

#include <iostream>

using namespace std;

int main() {
    int n, p, t;
    cin >> n >> p >> t;
    int moves = 1;
    moves += 3 * (t / 9);
    int remaining_moves = t % 9;
    switch (remaining_moves){
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
            break;
        case 5:
            moves++;
            break;
        case 7:
            moves++;
            break;
        case 8:
            moves += 2;
            break;
    }
    if((p < n + moves) && (p >= moves)){
        cout << p - moves + 1;
        return 0;
    }
    cout << -1;
    return 0;
}




