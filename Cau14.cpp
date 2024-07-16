#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    fgets(nld->gioiTinh, 4, stdin);
    nld->gioiTinh[strcspn(nld->gioiTinh, "\n")] = '\0'; 
}

int tinhTuoi(NguoiLaoDong *nld, int namHienTai) {
    int ngay, thang, nam;
    sscanf(nld->ngaySinh, "%d/%d/%d", &ngay, &thang, &nam);
    return namHienTai - nam;
}

int tinhThoiDiemNghiHuu(NguoiLaoDong *nld, int namHienTai) {
    int ngay, thang, nam;
    sscanf(nld->ngaySinh, "%d/%d/%d", &ngay, &thang, &nam);
    
    if (strcmp(nld->gioiTinh, "nam") == 0) {
        if (nam >= 1961 && nam <= 1963) {
            if (namHienTai == 2021) return 60 * 12 + 3;
            if (namHienTai == 2022) return 60 * 12 + 6;
            if (namHienTai == 2023) return 60 * 12 + 9;
            if (namHienTai == 2024) return 61 * 12;
            if (namHienTai == 2025) return 61 * 12 + 3;
            if (namHienTai == 2026) return 61 * 12 + 6;
            if (namHienTai == 2027) return 61 * 12 + 9;
            if (namHienTai == 2028) return 62 * 12;
        }
    } else if (strcmp(nld->gioiTinh, "nu") == 0) {
        if (nam >= 1966 && nam <= 1968) {
            if (namHienTai == 2021) return 55 * 12 + 4;
            if (namHienTai == 2022) return 55 * 12 + 8;
            if (namHienTai == 2023) return 56 * 12;
            if (namHienTai == 2024) return 56 * 12 + 4;
            if (namHienTai == 2025) return 56 * 12 + 8;
            if (namHienTai == 2026) return 57 * 12;
            if (namHienTai == 2027) return 57 * 12 + 4;
            if (namHienTai == 2028) return 57 * 12 + 8;
            if (namHienTai == 2029) return 58 * 12;
            if (namHienTai == 2030) return 58 * 12 + 4;
            if (namHienTai == 2031) return 58 * 12 + 8;
            if (namHienTai == 2032) return 59 * 12;
            if (namHienTai == 2033) return 59 * 12 + 4;
            if (namHienTai == 2034) return 59 * 12 + 8;
            if (namHienTai == 2035) return 60 * 12;
        }
    }
    return -1; 
}

void tinhThoiGianNghiHuu(NguoiLaoDong *nld, int namHienTai) {
    int tuoi = tinhTuoi(nld, namHienTai);
    
    if (tuoi < 18 || (strcmp(nld->gioiTinh, "nam") == 0 && tuoi > 62) || (strcmp(nld->gioiTinh, "nu") == 0 && tuoi > 60)) {
        printf("Loi 101: Tuoi khong thuoc trong tuoi lao dong!\n");
        return;
    }
	
	fflush(stdin);
    if (strcmp(nld->gioiTinh, "nam") != 0 && strcmp(nld->gioiTinh, "nu") != 0) {
    	fflush(stdin);
        printf("Loi: Gioi tinh khong hop le!\n");
        return;
    }
	
	fflush(stdin);
    int thoiDiemNghiHuu = tinhThoiDiemNghiHuu(nld, namHienTai);
    if (thoiDiemNghiHuu == -1) {
        printf("Khong the tinh toan tuoi nghi huu cho nguoi lao dong nay!\n");
        return;
    }
    
    int namNghiHuu = thoiDiemNghiHuu / 12;
    int thangNghiHuu = thoiDiemNghiHuu % 12;

    printf("%s, gioi tinh %s, sinh ngay %s. Thoi gian duoc nghi huu la thang %d/%d.\n",
           nld->hoTen, nld->gioiTinh, nld->ngaySinh, thangNghiHuu, namNghiHuu);
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

