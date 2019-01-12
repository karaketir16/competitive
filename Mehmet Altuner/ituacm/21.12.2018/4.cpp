#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	vector <char> res;
	cin >> s;
	int len = s.length();
	stack <char> st;
	
	for(int i=0; i<len; i++)
		st.push(s[i]);
	
	while(!st.empty()){
		res.push_back(st.top()); st.pop();
	}
	
	for(int i=0; i<len; i++)
		res.push_back(s[i]);

	for(char r: res)
		cout << r;

	cout << endl;
	return 0;
}