#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tu;
    int mau;
} PhanSo;

// Hàm nh?p phân s?
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

// Hàm xu?t phân s?
void xuatPhanSo(PhanSo ps) {
    printf("%d/%d\n", ps.tu, ps.mau);
}

// Hàm nh?p m?ng phân s?
void nhapMangPhanSo(PhanSo *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&arr[i]);
    }
}

// Hàm xu?t m?ng phân s?
void xuatMangPhanSo(PhanSo *arr, int n) {
    for (int i = 0; i < n; i++) {
        xuatPhanSo(arr[i]);
    }
}

// Hàm tìm phân s? nh? nh?t
PhanSo timPhanSoNhoNhat(PhanSo *arr, int n) {
    PhanSo min = arr[0];
    for (int i = 1; i < n; i++) {
        if ((double)arr[i].tu / arr[i].mau < (double)min.tu / min.mau) {
            min = arr[i];
        }
    }
    return min;
}

// Hàm tìm phân s? l?n nh?t
PhanSo timPhanSoLonNhat(PhanSo *arr, int n) {
    PhanSo max = arr[0];
    for (int i = 1; i < n; i++) {
        if ((double)arr[i].tu / arr[i].mau > (double)max.tu / max.mau) {
            max = arr[i];
        }
    }
    return max;
}

// Hàm xóa ph?n t? t?i v? trí k
void xoaPhanTu(PhanSo *arr, int *n, int k) {
    for (int i = k; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

// Hàm thêm ph?n t? x t?i v? trí k
void themPhanTu(PhanSo *arr, int *n, int k, PhanSo x) {
    for (int i = *n; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    (*n)++;
}

int main() {
    int n;
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    PhanSo *arr = (PhanSo*) malloc((n + 1) * sizeof(PhanSo)); // C?p phát du 1 ph?n t? d? thêm vào sau này

    nhapMangPhanSo(arr, n);

    printf("\nMang phan so vua nhap:\n");
    xuatMangPhanSo(arr, n);

    PhanSo min = timPhanSoNhoNhat(arr, n);
    printf("\nPhan so nho nhat: ");
    xuatPhanSo(min);

    PhanSo max = timPhanSoLonNhat(arr, n);
    printf("\nPhan so lon nhat: ");
    xuatPhanSo(max);

    int k;
    printf("\nNhap vi tri can xoa: ");
    scanf("%d", &k);
    if (k >= 0 && k < n) {
        xoaPhanTu(arr, &n, k);
        printf("\nMang phan so sau khi xoa phan tu tai vi tri %d:\n", k);
        xuatMangPhanSo(arr, n);
    } else {
        printf("Vi tri khong hop le.\n");
    }

    PhanSo x;
    printf("\nNhap phan so can them:\n");
    nhapPhanSo(&x);
    printf("Nhap vi tri can them: ");
    scanf("%d", &k);
    if (k >= 0 && k <= n) {
        themPhanTu(arr, &n, k, x);
        printf("\nMang phan so sau khi them phan tu tai vi tri %d:\n", k);
        xuatMangPhanSo(arr, n);
    } else {
        printf("Vi tri khong hop le.\n");
    }

    free(arr);
    return 0;
}

