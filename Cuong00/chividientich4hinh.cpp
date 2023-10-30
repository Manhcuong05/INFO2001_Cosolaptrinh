#include <stdio.h>
#include <math.h>
#define pi 3.14
int main(){
	int luachon;
	printf ("1.tinh dien tich va chi vi hinh tron\n");
	printf ("2.tinh dien tich va chu vi hinh chu nhat\n");
	printf ("3.tinh dien tich va chu vi hinh tam giac\n");
	printf ("4.tinh dien tich va chu vi hinh vuong\n");
	printf ("lua chon cua ban la (1-4):");
	scanf ("%d", &luachon);
	
	
	switch (luachon) {
		case 1: {
			float bankinh;
			printf ("nhap ban kinh cua hinh tron:");
			scanf ("%f", &bankinh);
			float chuvi = 2 * pi * bankinh;
			float dientich = pi * bankinh * bankinh;
			
			printf ("chu vi cua hinh tron la: %.2f\n", chuvi);
			printf ("dien tich cua hinh tron la: %.2f\n", dientich);
			break;
		}
		
		case 2:{
			float canh;
			printf ("nhap mot canh cua hinh vuong:");
			scanf ("%f",&canh);
			float chuvi = 4 * canh;
			float dientich = canh * canh;
			
			printf ("chu vi cua hinh vuong la: %.2f\n",chuvi);
			printf ("dien tich cua hinh vuong la: %.2f",dientich);
			break;
		}
		
		
		case 3: {
			float chieudai, chieurong;
			printf ("chieu dai cua hinh chu nhat la:");
			scanf ("%f",&chieudai);
			printf ("chieu rong cua hinh chu nhat la:");
			scanf ("%f",&chieurong);
			
			float chuvi = 2 * chieudai + chieurong;
			float dientich = chieudai * chieurong;
			
			printf ("chu vi cua hinh chu nhat la:%2.f\n",chuvi);
			printf ("dien tich cua hinh chu nhat la:%.2f",dientich);
			
			break;
		}
		
		
		case 4: {
			float canh1,canh2,canh3;
			printf ("nhap canh so 1 cua tam giac:");
			scanf ("%f",&canh1);
			printf ("nhap canh so 2 cua tam giac:");
			scanf ("%f",&canh2);
			printf ("nhap canh so 3 cua tam giac:");
			scanf ("%f",&canh3);
			
			float nuachuvi = (canh1 +canh2 + canh3)/2;
			float chuvi = canh1 + canh2 +canh3;
			float dientich = sqrt (nuachuvi*(nuachuvi-canh1)*(nuachuvi-canh2)*(nuachuvi-canh3));
			
			printf ("chu vi cua hinh tam giac la:%.2f\n",chuvi);
			printf ("dien tich cau hinh tam giac la:%.2f",dientich);
			break;
		}
		
		default :
			printf ("khong hop le");
			break;
	}
	
}
