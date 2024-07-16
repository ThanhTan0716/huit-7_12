#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tu;
    int mau;
} PhanSo;

// Hàm nhap phan so
void nhapPhanSo(PhanSo *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so khong the bang 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}

// Ham xuat phan so
void xuatPhanSo(PhanSo ps) {
    printf("%d/%d\n", ps.tu, ps.mau);
}

// Ham nhap mang phan so
void nhapMangPhanSo(PhanSo *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&arr[i]);
    }
}

// Ham xuat mang phan so
void xuatMangPhanSo(PhanSo *arr, int n) {
    for (int i = 0; i < n; i++) {
        xuatPhanSo(arr[i]);
    }
}

// Ham xuat cac phan so có mau > tu
void xuatPhanSoMauLonHonTu(PhanSo *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i].mau > arr[i].tu) {
            xuatPhanSo(arr[i]);
        }
    }
}

// Ham dem so phan so co tu và mau chan
int demPhanSoTuMauChan(PhanSo *arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].tu % 2 == 0 && arr[i].mau % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Ham tim UCLN
int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

// Ham rut gon phan so
void rutGonPhanSo(PhanSo *ps) {
    int ucln = UCLN(ps->tu, ps->mau);
    ps->tu /= ucln;
    ps->mau /= ucln;
}

// Ham tinh tich cac phan so trong mang
PhanSo tinhTichPhanSo(PhanSo *arr, int n) {
    PhanSo tich = {1, 1}; // kh?i t?o tích b?ng 1
    for (int i = 0; i < n; i++) {
        tich.tu *= arr[i].tu;
        tich.mau *= arr[i].mau;
    }
    rutGonPhanSo(&tich); // rút g?n phân s?
    return tich;
}

// Ham tim phan so lon nhat
PhanSo timPhanSoLonNhat(PhanSo *arr, int n) {
    PhanSo max = arr[0];
    for (int i = 1; i < n; i++) {
        if ((double)arr[i].tu / arr[i].mau > (double)max.tu / max.mau) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    PhanSo *arr = (PhanSo*) malloc(n * sizeof(PhanSo));

    nhapMangPhanSo(arr, n);

    printf("\nMang phan so vua nhap:\n");
    xuatMangPhanSo(arr, n);

    printf("\nCac phan so co mau > tu:\n");
    xuatPhanSoMauLonHonTu(arr, n);

    int soLuongPhanSoChan = demPhanSoTuMauChan(arr, n);
    printf("\nSo luong phan so co tu va mau chan: %d\n", soLuongPhanSoChan);

    PhanSo tich = tinhTichPhanSo(arr, n);
    printf("\nTich cac phan so trong mang: ");
    xuatPhanSo(tich);

    PhanSo max = timPhanSoLonNhat(arr, n);
    printf("\nPhan so lon nhat: ");
    xuatPhanSo(max);

    free(arr);
    return 0;
}

