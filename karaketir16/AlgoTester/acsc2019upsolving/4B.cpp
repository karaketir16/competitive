#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    cout<<(n&1 ? "John" : "Brus");
	return 0;
}

//	g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a a.cpp
//	g++ -std=c++17 -Wshadow -Wall -o a.out 4F.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
