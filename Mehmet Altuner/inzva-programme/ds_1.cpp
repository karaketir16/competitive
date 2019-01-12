#include <bits/stdc++.h>
#define LIM 2005
using namespace std;

typedef long long lli;

vector<char> s, s_sorted;
queue <char> u;
stack <char> t;
int s_ptr, s_sorted_ptr;

void append_t(){
	t.push(s[s_ptr++]);
	return;
}

void append_u(){
	u.push(t.top()); t.pop();
	return;
}

int main(int argc, char const *argv[])
{
	string input;
	cin >> input;
	int len = input.length();
	
	for(int i=0; i<len; i++){
		s.push_back(input[i]);
		s_sorted.push_back(input[i]);
	}
	
	sort(s_sorted.begin(), s_sorted.end());

	append_t();
	while(s_ptr < len){
		if(!t.empty())
			if(t.top() == s_sorted[s_sorted_ptr]){
				append_u();
				s_sorted_ptr++;
			}else
				append_t();
		else
			append_t();
	}

	while(!t.empty())
		append_u();
	
	while(!u.empty()){
		cout << u.front();
		u.pop();
	}

	cout << endl;

	return 0;
}