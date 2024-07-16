#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ham nhap mang 1 chieu so nguyen
void nhapM1C_SoNguyen(int **a, int *n) {
    printf("Nhap so luong phan tu: ");
    scanf("%d",n);
    *a = (int *)malloc((*n) * sizeof(int)); 
    for(int i = 0; i < *n; i++){
    	printf("Nhap gia tri cho phan tu thu %d: ",i);
        scanf("%d",(*a + i));
    }
}

// Ham xuat mang 1 chieu so nguyen
void xuatM1C_SoNguyen(int *a, int n) {
    for(int i = 0; i < n; i++) {
        printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, *(a + i), (a + i));
    }
}

// a. Tim phan tu lon nhat và xuat ra phan tu lon nhat va dia chi cua no
void timPhanTuLonNhat(int *a, int n) {
    if (n == 0) return;
    int max = *a;
    int *pMax = a;
    for (int i = 1; i < n; i++) {
        if (*(a + i) > max) {
            max = *(a + i);
            pMax = (a + i);
        }
    }
    printf("\nPhan tu lon nhat la %d va dia chi o nho la %p", max, pMax);
}

// b. Xuat dia chi cua phan tu chan lon nhat va phan tu le nho nhat
void xuatDiaChiChanLe(int *a, int n) {
    int *pMaxChan = NULL, *pMinLe = NULL;
    for (int i = 0; i < n; i++) {
        if (*(a + i) % 2 == 0) {
            if (pMaxChan == NULL || *(a + i) > *pMaxChan) {
                pMaxChan = (a + i);
            }
        } else {
            if (pMinLe == NULL || *(a + i) < *pMinLe) {
                pMinLe = (a + i);
            }
        }
    }
    if (pMaxChan != NULL)
        printf("\nDia chi cua phan tu chan lon nhat la %p", pMaxChan);
    else
        printf("\nKhong co phan tu chan trong mang");

    if (pMinLe != NULL)
        printf("\nDia chi cua phan tu le nho nhat la %p", pMinLe);
    else
        printf("\nKhong co phan tu le trong mang");
}

// c. Xoa phan tu co gia tri 0
void xoaPhanTu0(int **a, int *n) {
    int count = 0;
    for (int i = 0; i < *n; i++) {
        if (*(*a + i) != 0) {
            *(*a + count) = *(*a + i);
            count++;
        }
    }
    *n = count;
    *a = (int *)realloc(*a, (*n) * sizeof(int));
}

// d. Them phan tu x vao sau phan tu dau tien
void themPhanTu(int **a, int *n, int x) {
    *n += 1;
    *a = (int *)realloc(*a, (*n) * sizeof(int));
    for (int i = *n - 1; i > 1; i--) {
        *(*a + i) = *(*a + i - 1);
    }
    *(*a + 1) = x;
}

// Kiem tra so chinh phuong
int laSoChinhPhuong(int x) {
    int s = sqrt(x);
    return (s * s == x);
}

// e. Tính tong cac phan tu là so chinh phuong
int tongSoChinhPhuong(int *a, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (laSoChinhPhuong(*(a + i))) {
            tong += *(a + i);
        }
    }
    return tong;
}

// f. Xuat cac so cuc dai
void xuatSoCucDai(int *a, int n) {
    if (n == 0) return;
    if (n == 1 || *(a + 0) > *(a + 1)) {
        printf("\nSo cuc dai: %d", *(a + 0));
    }
    for (int i = 1; i < n - 1; i++) {
        if (*(a + i) > *(a + i - 1) && *(a + i) > *(a + i + 1)) {
            printf("\nSo cuc dai: %d", *(a + i));
        }
    }
    if (*(a + n - 1) > *(a + n - 2)) {
        printf("\nSo cuc dai: %d", *(a + n - 1));
    }
}

int main() {
    int *a, n;
    nhapM1C_SoNguyen(&a, &n);
    xuatM1C_SoNguyen(a, n);
    timPhanTuLonNhat(a, n);
    xuatDiaChiChanLe(a, n);
    xoaPhanTu0(&a, &n);
    printf("\nMang sau khi xoa phan tu 0:");
    xuatM1C_SoNguyen(a, n);
    themPhanTu(&a, &n, 50);
    printf("\nMang sau khi them phan tu 50:");
    xuatM1C_SoNguyen(a, n);
    printf("\nTong cac so chinh phuong trong mang: %d", tongSoChinhPhuong(a, n));
    printf("\nCac so cuc dai trong mang:");
    xuatSoCucDai(a, n);
    free(a);
    return 0;
}

