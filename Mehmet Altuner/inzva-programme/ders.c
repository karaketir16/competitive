#include <stdio.h>

struct mystruct{

	int veri;
	char harf;
	float yaricap;
	double uzunluk;

}mystruct;

int main(){
	mystruct.veri = 'a';
	printf("%c", mystruct.veri);
	return 0;
}