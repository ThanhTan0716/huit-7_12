#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Bai 7
void nhapM1C_SoNguyen(int **a, int *n) {
    printf("Nhap so luong phan tu: ");
    scanf("%d", n);
    *a = (int *)malloc((*n) * sizeof(int)); // c?p phát a v?i s? ph?n t? n
    for (int i = 0; i < *n; i++) {
        printf("Nhap gia tri cho phan tu thu %d: ", i);
        scanf("%d", (*a + i));
    }
}

void xuatM1C_SoNguyen(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, *(a + i), (a + i));
    }
}

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

void themPhanTu(int **a, int *n, int x) {
    *n += 1;
    *a = (int *)realloc(*a, (*n) * sizeof(int));
    for (int i = *n - 1; i > 1; i--) {
        *(*a + i) = *(*a + i - 1);
    }
    *(*a + 1) = x;
}

int laSoChinhPhuong(int x) {
    int s = sqrt(x);
    return (s * s == x);
}

int tongSoChinhPhuong(int *a, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (laSoChinhPhuong(*(a + i))) {
            tong += *(a + i);
        }
    }
    return tong;
}

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
//Bai 11
// a. Xuat cac so cuc tieu trong a
void xuatSoCucTieu(int *a, int n) {
    if (n == 0) return;
    if (n == 1 || *(a + 0) < *(a + 1)) {
        printf("\nSo cuc tieu: %d", *(a + 0));
    }
    for (int i = 1; i < n - 1; i++) {
        if (*(a + i) < *(a + i - 1) && *(a + i) < *(a + i + 1)) {
            printf("\nSo cuc tieu: %d", *(a + i));
        }
    }
    if (*(a + n - 1) < *(a + n - 2)) {
        printf("\nSo cuc tieu: %d", *(a + n - 1));
    }
}

// b. Xoa phan tu tri vi tri k
void xoaPhanTuTaiViTri(int **a, int *n, int k) {
    if (k < 0 || k >= *n) {
        printf("\nVi tri xoa khong hop le");
        return;
    }
    for (int i = k; i < *n - 1; i++) {
        *(*a + i) = *(*a + i + 1);
    }
    *n -= 1;
    *a = (int *)realloc(*a, (*n) * sizeof(int));
}

// c. Them phan tu x toi vi tri k
void themPhanTuTaiViTri(int **a, int *n, int x, int k) {
    if (k < 0 || k > *n) {
        printf("\nVi tri them khong hop le");
        return;
    }
    *n += 1;
    *a = (int *)realloc(*a, (*n) * sizeof(int));
    for (int i = *n - 1; i > k; i--) {
        *(*a + i) = *(*a + i - 1);
    }
    *(*a + k) = x;
}

// d. Chuyen so chan len dau mang, so le xuong cuoi mang
void chuyenChanLe(int **a, int n) {
    int *temp = (int *)malloc(n * sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(*a + i) % 2 == 0) {
            temp[count++] = *(*a + i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (*(*a + i) % 2 != 0) {
            temp[count++] = *(*a + i);
        }
    }
    for (int i = 0; i < n; i++) {
        *(*a + i) = temp[i];
    }
    free(temp);
}

// e. Kiem tra mang co chua chan le xen ke khong?
int kiemTraChanLeXenKe(int *a, int n) {
    for (int i = 1; i < n; i++) {
        if ((*a + i) % 2 == (*(a + i - 1)) % 2) {
            return 0;
        }
    }
    return 1;
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
    
   
    printf("\nCac so cuc tieu trong mang:");
    xuatSoCucTieu(a, n);
    
    int k;
    printf("\nNhap vi tri xoa: ");
    scanf("%d", &k);
    xoaPhanTuTaiViTri(&a, &n, k);
    printf("\nMang sau khi xoa phan tu tai vi tri %d:", k);
    xuatM1C_SoNguyen(a, n);
    
    int x;
    printf("\nNhap gia tri can them: ");
    scanf("%d", &x);
    printf("Nhap vi tri them: ");
    scanf("%d", &k);
    themPhanTuTaiViTri(&a, &n, x, k);
    printf("\nMang sau khi them phan tu %d tai vi tri %d:", x, k);
    xuatM1C_SoNguyen(a, n);
    
    chuyenChanLe(&a, n);
    printf("\nMang sau khi chuyen so chan len dau, so le xuong cuoi:");
    xuatM1C_SoNguyen(a, n);
    
    if (kiemTraChanLeXenKe(a, n)) {
        printf("\nMang chua chan le xen ke");
    } else {
        printf("\nMang khong chua chan le xen ke");
    }
    
    free(a);
    return 0;
}

