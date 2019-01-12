#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

struct seq{
	lli size;
	vector <lli> s;
};

vector <seq> seqList;

int main(int argc, char const *argv[])
{
	lli n, q;
	scanf("%lli %lli", &n, &q);
	
	// create empty seqList
	seqList.resize(n, seq{0, vector<lli>(0)});
	lli lastAnswer = 0;

	while(q--){
		lli c, x, y;
		scanf("%lli %lli %lli", c, x, y);

		if(c == 1){ // append seq
			lli index = (x ^ lastAnswer) % n
			seqList[index].size++;
			seqList[index].s.push_back(y);
		}else{
			lli index = (x ^ lastAnswer) % n
			lastAnswer = seqList[index].s[y % seqList[index].size];
			printf("%lli\n", lastAnswer);		
		}
	}

	return 0;
}