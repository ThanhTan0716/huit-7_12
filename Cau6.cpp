#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char hoTen[50];
    char ngaySinh[11];
    char gioiTinh[4];
} NguoiLaoDong;

void nhapThongTin(NguoiLaoDong *nld) {
    printf("Nhap ho ten: ");
    fgets(nld->hoTen, 50, stdin);
    nld->hoTen[strcspn(nld->hoTen, "\n")] = '\0'; 

    printf("Nhap ngay sinh (dd/mm/yyyy): ");
    fgets(nld->ngaySinh, 11, stdin);
    nld->ngaySinh[strcspn(nld->ngaySinh, "\n")] = '\0'; 

    printf("Nhap gioi tinh (nam/nu): ");
    fflush(stdin);
    fgets(nld->gioiTinh, 4, stdin);
    nld->gioiTinh[strcspn(nld->gioiTinh, "\n")] = '\0'; 
}

int tinhTuoi(NguoiLaoDong *nld, int namHienTai) {
    int ngay, thang, nam;
    sscanf(nld->ngaySinh, "%d/%d/%d", &ngay, &thang, &nam);
    return namHienTai - nam;
}

void tinhThoiGianNghiHuu(NguoiLaoDong *nld, int namHienTai) {
    int tuoi = tinhTuoi(nld, namHienTai);

    if (tuoi < 18 || (strcmp(nld->gioiTinh, "nam") == 0 && tuoi > 62) || (strcmp(nld->gioiTinh, "nu") == 0 && tuoi > 60)) {
        printf("Tuoi khong thuoc trong tuoi lao dong!\n");
        return;
    }

    if (strcmp(nld->gioiTinh, "nam") != 0 && strcmp(nld->gioiTinh, "nu") != 0) {
        printf("Gioi tinh khong hop le!\n");
        return;
    }

    int namNghiHuu;
    if (strcmp(nld->gioiTinh, "nam") == 0) {
        namNghiHuu = (62 - tuoi) + namHienTai;
    } else {
        namNghiHuu = (60 - tuoi) + namHienTai;
    }

    printf("%s, gioi tinh %s, sinh ngay %s. Thoi gian duoc nghi huu la thang %s/%d.\n",
           nld->hoTen, nld->gioiTinh, nld->ngaySinh, nld->ngaySinh, namNghiHuu);
}

int main() {
    NguoiLaoDong nld;
    nhapThongTin(&nld);

    int namHienTai;
    printf("Nhap nam hien tai: ");
    scanf("%d", &namHienTai);

    tinhThoiGianNghiHuu(&nld, namHienTai);

    return 0;
}

