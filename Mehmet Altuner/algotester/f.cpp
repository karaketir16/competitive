#include <stdio.h>
#include <algorithm>
#define lli long long int

using namespace std;

int main(){
	int n;
	int len_for_1 = 1;
	lli a, t, ar[n];
	
	scanf("%d %lli", &n, &t);
	
	for(int i=0; i<n; i++){
		scanf("%lli", &ar[i]);
	}
	
	sort(ar, ar + n);
	lli sum = ar[0];
	
	for(int i=1; i<n; i++){
		if(ar[i] != ar[i-1]){		
			sum += ar[i];
			len_for_1++;
		}
	}
	
	lli max = ar[n-1];
	
	lli sol1 = t * len_for_1 + sum;
	lli sol2 = max * n + t;
	
	
	if(sol1 < sol2){
		printf("%lli", sol1);
	}else{
		printf("%lli", sol2);
	}	
	
	printf("\n");
	
	return 0;
}
