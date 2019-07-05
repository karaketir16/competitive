#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9)
//#define __ <<" "<<
typedef long long int lint;
vector<lint> scores;
bool checker(lint x)
{
    lint tot = 0;

    for(auto a: scores) tot+=(a/(x+1));

    return tot <= 7;
}
int main()
{
    // for (int i = 0; i<100; i++) cout <<i<<" "<< fonk(i)<<endl;
    lint n;
    cin>>n;
    while(n--)
    {
        lint x;
        cin>>x;
        scores.push_back(x);
    }

    lint l = 0;
    lint r = 1e9 + 9;
    while(r > l)
    {
        lint mid = (l+r)/2;

        if(checker(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
    // for(int i = 1; i < 10; i++) cout<<i<< " " << checker(i)<<endl;
    return 0;
}
// g++  
// g++ -std=              c++17 -Wshadow -Wall -o a 2D.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g