#include <stdio.h>
#include <math.h>
#define PI 3.14159
int main(){
	int r;
	float chuvi,dientich;
	printf("nhap ban kinh r");
	scanf("%d", &r);
	chuvi=2 * PI * r;
	dientich=PI * r * r;
	printf("chu vi va dien tich cua hinh tron lan luot la:%.2f %.2f", chuvi, dientich);
	return 0;
}
