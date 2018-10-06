#include <stdio.h>

/*int cal(double n){
	if((n - (int)n) > 0){
		return (int)n + 1;
	}
	return (int)n
}*/

int main(){
	int n, m, x, y;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &x, &y);
	
	float second_loses_on = (m * y * y) / (n);
	float first_loses_on = (n * x * x) / (m);
	
	if(second_loses_on > first_loses_on){
		printf("SECOND");
	}else if(first_loses_on > second_loses_on){
		printf("FIRST");	
	}else{
		printf("DRAW");
	}
	return 0;
}
