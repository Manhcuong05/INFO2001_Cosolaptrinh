#include <stdio.h>
int main(){
	int x1, x2, y1 ,y2;
	float gap;
	printf ("toa do hai diem x1, x2, y1 ,y2 la cac so nguyen(-106<=xi,yi<=106)");
    scanf(" %d %d %d %d", &x1, &x2, &y1, &y2);
    gap=sqrt( pow(x1-x2,2) +pow(y1-y2,2));
    printf("khoang cach giua hai diem la:%.2f",gap);
    return 0;
//em chao thay giao
}
