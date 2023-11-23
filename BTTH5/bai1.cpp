#include <stdio.h>

struct Student {
	 int id;
	 int age;
	 char name [50];
	 float gradeMath;
	 float gradeE;
	 float gradeVN;
	 
};
int main(){
	int n;
	printf ("so luong sinh vien la:");
	scanf ("%d",&n);
	struct 	Student Sv[n];
    for (int i = 0; i < n; i++){
        printf ("thong tin cua sinh vien: \n");
        getchar();
        printf ("ho va ten:");
        fgets(Sv[i].name, sizeof(Sv[i].name), stdin);
        printf ("id:");
        scanf ("%d",&Sv[i].id);
        printf ("tuoi:");
        scanf ("%d",&Sv[i].age);
        printf ("diem toan:");  
        scanf ("%f",&Sv[i].gradeMath);
        printf ("diem tieng anh:");
        scanf ("%f",&Sv[i].gradeE);
        printf ("diem van:");
        scanf ("%f",&Sv[i].gradeVN);
        getchar ();

    } 
    for (int i = 0; i< n; i++){
        printf ("\nthong tin cua sinh vien: \n");
        printf ("ho va ten:%s", Sv[i].name);
        printf ("id:%d\n",Sv[i].id);
        printf ("tuoi:%d\n",Sv[i].age);
        printf ("diem toan:%.2f\n",Sv[i].gradeMath);
        printf ("diem tieng anh:%.2f\n",Sv[i].gradeE);
        printf ("diem van:%.2f\n",Sv[i].gradeVN);
    }
    return 0;
}


