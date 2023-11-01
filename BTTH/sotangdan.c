#include <stdio.h>
int main (){
	int a,b,c;
	printf ("nhap so a:");
	scanf("%d",&a);
	printf ("nhap so b:");
	scanf ("%d",&b);
	printf ("nhap so c:");
	scanf ("%d",&c);
	
	
	if (a>b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (b>c){
		int temp = b;
		b = c;
		c =temp;
	}
	if (a>b){
		int temp = a;
		a = b;
		b = temp;
	}
    printf ("so thu tu tang dan la:%d %d %d", a,b,c);
    return 0;
}

