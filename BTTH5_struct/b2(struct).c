#include <stdio.h>
#include <string.h>

struct SinhVien {
    char hoten[50];
    char masv[10];
    int tuoi;
    float gpa;
};

typedef struct SinhVien Sinhvien;

void hienThiDS(Sinhvien s){
    printf("Ten: %s\n", s.hoten);
    printf("Ma sinh vien: %s\n", s.masv);
    printf("Tuoi: %d\n", s.tuoi);
    printf("Gpa: %.2f\n", s.gpa);
}

void sapXepTheoTen(Sinhvien dssv[],int slsv){
    Sinhvien tmp;
    int i,j;
    for(i=0;i<slsv-1;i++){
        for(j=0;j<slsv-i-1;j++){
            if(strcmp(dssv[j].hoten,dssv[j+1].hoten)>0){
                tmp=dssv[j];
                dssv[j]=dssv[j+1];
                dssv[j+1]=tmp;
            }
        }
    }
}

void sapXepTheoGpa(Sinhvien dssv[],int slsv){
    Sinhvien tmp;
    int i,j;
    for(i=0;i<slsv-1;i++){
        for(j=0;j<slsv-i-1;j++){
            if(dssv[j].gpa>dssv[j+1].gpa){
                tmp=dssv[j];
                dssv[j]=dssv[j+1];
                dssv[j+1]=tmp;
            }
        }
    }
}

int timKiemTheoTen(Sinhvien dssv[],int slsv, char hoten[50]){
    for(int i=0;i<slsv;i++){
        if(strcmp(dssv[i].hoten,hoten)==0){
            return i;
        }
    }
    return -1;
}

int timKiemTheoMaSV(Sinhvien dssv[],int slsv,char masv[10]){
    for(int i=0;i<slsv;i++){
        if(dssv[i].masv==masv){
            return i;
        }
    }
    return -1;
}

int main(){
    Sinhvien dssv[50];
    int slsv=0;
    int chon;
    do{
        printf("\n--- Chuong trinh quan ly danh sach sinh vien ---\n");
        printf("1. Them thong tin sinh vien.\n");
        printf("2. Hien thi danh sach sinh vien.\n");
        printf("3. Sap xep danh sach sinh vien theo ten.\n");
        printf("4. Sap xep danh sach sinh vien theo gpa.\n");
        printf("5. Tim kiem sinh vien theo ten.\n");
        printf("6. Tim kiem sinh vien theo ma sinh vien.\n");
        printf("7. Thoat ung dung.\n");
        printf("Lua chon cua ban la:");
        scanf("%d", &chon);

        switch(chon){
            case 0:
              break;
            case 1:
              if(slsv<50){
                Sinhvien sv;
                getchar();
                printf("Nhap ten sinh vien:");
                gets(sv.hoten);
                printf("Nhap ma sinh vien:");
                gets(sv.masv);
                printf("Nhap tuoi sinh vien:");
                scanf("%d",&sv.tuoi);
                printf("Nhap gpa sinh vien:");
                scanf("%f",&sv.gpa);
                dssv[slsv]=sv;
                slsv++;
                printf("Them thong tin sinh vien thanh cong.\n");
              }else{
                printf("So luong sinh vien qua tai.\n");
              }
              break;
            case 2:
              if(slsv>0){
                printf("\n----Danh sach sinh vien----\n");
                for(int i=0;i<slsv;i++){
                    printf("Sinh vien %d\n",i+1);
                    hienThiDS(dssv[i]);
                    printf("---------------------\n");
                }
              }else{
                    printf("Khong tim thay thong tin sinh vien.\n");
                }
                break;
            case 3:
                if (slsv>0) {
                    sapXepTheoTen(dssv,slsv);
                    printf("Sap xep danh sach sinh vien theo ten.\n");
                } else {
                    printf("Khong tim thay danh sach sinh vien.\n");
                }
                break;
            case 4:
                if (slsv>0) {
                    sapXepTheoGpa(dssv,slsv);
                    printf("Sap xep danh sach sinh vien theo gpa.\n");
                } else {
                    printf("Khong tim thay danh sach sinh vien.\n");
                }
                break;
            case 5:
                if (slsv>0) {
                    char timTen[50];
                    printf("\nNhap ten sinh vien can tim: ");
                    scanf("%s",timTen);

                    int mucLuc = timKiemTheoTen(dssv,slsv,timTen);
                    if (mucLuc != -1) {
                        printf("Sinh vien can tim tai muc luc %d\n",mucLuc);
                        hienThiDS(dssv[mucLuc]);
                    } else {
                        printf("Khong tim thay sinh vien.\n");
                    }
                } else {
                    printf("Khong tim thay sanh sach sinh vien.\n");
                }
                break;
            case 6:
                if (slsv>0) {
                    char timMaSV[10];
                    printf("\nNhap ma sinh vien can tim: ");
                    scanf("%s",timMaSV);

                    int mucLuc = timKiemTheoMaSV(dssv,slsv,timMaSV);
                    if (mucLuc != -1) {
                        printf("Sinh vien can tim tai muc luc %d\n",mucLuc);
                        hienThiDS(dssv[mucLuc]);
                    } else {
                        printf("Khong tim thay sinh vien.\n");
                    }
                } else {
                    printf("Khong tim thay sanh sach sinh vien.\n");
                }
                break;
            case 7:
                printf("Thoat chuong trinh.Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le\n.Vui long chon lai.\n");
        }
    }while(chon!=7);
    return 0;
}