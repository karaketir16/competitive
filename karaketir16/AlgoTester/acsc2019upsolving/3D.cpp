#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9)
//#define __ <<" "<<
typedef long long int lint;

lint dp[25][50];
bool used[25][50];
lint f(lint digit, lint tot) //-1 for 4 + for 7
{
    if(digit == 0) return(tot == 30);

    if(used[digit][tot]) return dp[digit][tot];
    
    lint res = 0;

    res += 8*(f(digit - 1, tot));
    res += f(digit -1, tot-1); //4
    res += f(digit -1, tot+1); //7

    dp[digit][tot] = res;
    used[digit][tot] = 1;

    return res;
}
vector<lint> digitsF(lint x)
{
    vector<lint> tmp;
    while (x>0)
    {
        tmp.push_back(x%10);
        x/=10;
    }

    reverse(tmp.begin(), tmp.end());

    return tmp;
}
lint fonk(lint x)
{
    x++;

    lint tot = 30;

    auto digits = digitsF(x);

    lint dg = digits.size();
    lint res = 0;
    for(int i = 0; i < dg; i++)
    {
        for(int j = 0; j < digits[i]; j++)
        {
            if(j == 4 || j == 7) 
            {
                res += f(dg - i - 1, tot + (j == 7 ? +1 : -1));
            }
            else
            {
                res += f(dg - i - 1, tot);
            }
        }
        if(digits[i] == 4 || digits[i] == 7) 
        {
            tot += (digits[i] == 7 ? +1 : -1);
        }
    }
    return res;
}
int main()
{
    // for (int i = 0; i<100; i++) cout <<i<<" "<< fonk(i)<<endl;
    lint a ,b;
    cin>>a>>b;
    cout << fixed<<fonk(b) - fonk(a-1)<<endl;
    return 0;
}
// g++  
// g++ -std=              c++17 -Wshadow -Wall -o a 2D.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g