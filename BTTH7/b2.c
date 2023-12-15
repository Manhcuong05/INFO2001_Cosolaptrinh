#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    char ten[50];
    char maSV[10];
    float diem;
};

void ghiSinhVienVaoTep(const char* tenTep) {
    struct SinhVien sinhVien;
    FILE* tep = fopen(tenTep, "wb");

    if (tep == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }

    printf("Nhap ten sinh vien: ");
    scanf(" %[^\n]s", sinhVien.ten);
    printf("Nhap ma sinh vien: ");
    scanf(" %[^\n]s", sinhVien.maSV);
    printf("Nhap diem sinh vien: ");
    scanf("%f", &(sinhVien.diem));

    fwrite(&sinhVien, sizeof(struct SinhVien), 1, tep);

    fclose(tep);
    printf("Da ghi sinh vien vao tep.\n");
}

void docSinhVienTuTep(const char* tenTep) {
    struct SinhVien sinhVien;
    FILE* tep = fopen(tenTep, "rb");

    if (tep == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }

    fread(&sinhVien, sizeof(struct SinhVien), 1, tep);

    printf("Thong tin sinh vien:\n");
    printf("Ten: %s\n", sinhVien.ten);
    printf("Ma sinh vien: %s\n", sinhVien.maSV);
    printf("Diem: %.2f\n", sinhVien.diem);

    fclose(tep);
}

int main() {
    const char* tenTep = "sinhvien.bin";

    ghiSinhVienVaoTep(tenTep);
    docSinhVienTuTep(tenTep);

    return 0;
}
