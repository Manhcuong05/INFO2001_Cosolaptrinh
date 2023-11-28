#include <stdio.h>

int main(){
    int diem[100];
    int SiSo;
    float TongDiem=0, DiemTB=0;
    
    printf ("------Chuong trinh tinh diem trung binh cua lop hoc------\n");
    printf("So luong sinh vien trong lop hoc:");
    scanf("%d",&SiSo);
    for(int i=0;i<SiSo;i++){
        printf("Nhap diem cua sinh vien thu %d: ",i+1);
        scanf("%d",&diem[i]);
        TongDiem+=diem[i];
    }
    
    DiemTB=TongDiem/SiSo;
    printf("Diem trung binh cua ca lop=%.2f\n", DiemTB);

    return 0;
}
