#include <bits/stdc++.h>

using namespace std;

vector <int> ar(3);

int perform(int index, int res){
	if(index == 2){ // if it has ended
		return max(res * ar[index], res + ar[index]);
	}

	int rec1 = perform(index + 2, ar[index] + ar[index+1]);
	int rec2 = perform(index + 2, ar[index] * ar[index+1]);
	int rec3 = ar[index] + perform(index + 2, ar[index+1]);
	int rec4 = ar[index] * perform(index + 2, ar[index+1]);

	return max(rec1, max(rec2, max(rec3, rec4)));
}

int main(int argc, char const *argv[])
{
	for(int i=0; i<3; i++)
		scanf("%d", &ar[i]);

	printf("%d", perform(0, 0));

	return 0;
}