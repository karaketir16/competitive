#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

lint convert(vector<lint> digits){
    lint res = 0;
    for(auto a: digits) res = (res*10 + a);
    return res;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
    lint n, k;
    cin>>n>>k;
    vector<lint> digits;
    lint a = n;
    while(a>0)
    {
        digits.push_back(a%10);
        a/=10;
    }
    reverse(digits.begin(), digits.end());

    lint bas = digits.size();
    lint minn = 1e18;
    for(lint i = 1; i < (1<<bas); i++){
        if(__builtin_popcount(i) < (bas - k)) continue;
        vector<lint> v;
        for(lint j = 0; j < bas; j++){
            if(i & (1<<j)) v.push_back(digits[j]);
        }
        if(v[0] == 0) continue;

        minn = min(minn, convert(v));
    }
    cout<<minn;
	return 0;
}

//	g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a a.cpp
//	g++ -std=c++17 -Wshadow -Wall 4D.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
