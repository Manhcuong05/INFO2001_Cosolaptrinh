#include <stdio.h>
#include <string.h>

struct SinhVien {
    char HoTen[50];
    char MSSV[50];
    int Tuoi;
    float gpa;
};

typedef struct SinhVien Sinhvien;

void hienThiDS(Sinhvien Z){
    printf("Ho va ten:%s\n",Z.HoTen);
    printf("Ma so sv:%s\n",Z.MSSV);
    printf("Tuoi:%d\n",Z.Tuoi);
    printf("Gpa:%.2f\n",Z.gpa);
}

int main(){
    Sinhvien DSSV[50];
    int SLSV=0;
    int LuaChon;
    do{
        printf("CHUONG TRINH QUAN LY DANH SACH SINH VIEN\n");
        printf("1.Them thong tin sinh vien\n");
        printf("2.Hien thi danh sach sinh vien\n");
        printf("3.Cap nhat thong tin sinh vien\n");
        printf("4.Thoat chuong trinh\n");
        printf("lua chon cua ban la:");
        scanf("%d",&LuaChon);

        switch(LuaChon){
            case 0:
              break;
            case 1:
              if(SLSV<50){
                Sinhvien sv;
                getchar();
                printf("Nhap ten sinh vien:");
                gets(sv.HoTen);
                printf("Nhap ma sinh vien:");
                gets(sv.MSSV);
                printf("Nhap tuoi sinh vien:");
                scanf("%d",&sv.Tuoi);
                printf("Nhap gpa sinh vien:");
                scanf("%f",&sv.gpa);
                DSSV[SLSV]=sv;
                SLSV++;
                printf("Them thong tin sinh vien thanh cong.\n");
              }else{
                printf("So luong sinh vien qua tai.\n");
              }
              break;
            case 2:
              if(SLSV>0){
                printf("\nDanh sach sinh vien la:\n");
                for(int i=0;i<SLSV;i++){
                    printf("Sinh vien so %d\n",i+1);
                    hienThiDS(DSSV[i]);
                    printf("---------------------\n");
                }
              }else{
                    printf("Khong tim thay thong tin sinh vien.\n");
                }
                break;
            case 3:
            if(SLSV>0){
                int mucLuc;
                printf("\nNhap muc luc sinh vien (1-%d):",SLSV);
                scanf("%d",&mucLuc);
                mucLuc--;
                if(mucLuc>=0 && mucLuc<SLSV){
                    Sinhvien ThayDoi;
                    getchar();
                    printf("\nTen sinh vien duoc cap nhat:");
                    gets(ThayDoi.HoTen);
                    printf("\nMa sinh vien duoc cap nhat:");
                    gets(ThayDoi.MSSV);
                    printf("\nTuoi sinh vien duoc cap nhat:");
                    printf("\nCap nhat gpa:");
                    scanf("%f",&ThayDoi);
                    printf("Cap nhat thong tin sinh vien thanh cong.\n");
                }else{
                    printf("Muc luc khong hop le.\n");
                }
            }else{
                    printf("Khong tim thay thong tin sinh vien.\n");
                }
                break;
            case 4:
              printf("Thoat chuong trinh. Tam biet!\n");
              break;
            default:
              printf("Lua chon khong hop le. Vui long chon lai.\n");
              break;
        }
    }while 
        (LuaChon!=4);
    return 0;
}