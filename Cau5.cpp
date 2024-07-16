#include <stdio.h>
#include <stdlib.h>
int Tinh(int a,int b, int c){
	printf("Nhap a: ");	scanf("%d",&a);
	printf("Nhap b: ");	scanf("%d",&b);
	printf("Nhap c: ");	scanf("%d",&c);
	printf("Ket qua la: %d",c/(a-b));
}
int main(){
	int a,b,c;
	Tinh(a,b,c);
	return 0;
}





