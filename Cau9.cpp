#include <stdio.h>

void nhap(float *pa, float *pb) {
    printf("Nhap so thuc a: ");
    scanf("%f", pa);
    printf("Nhap so thuc b: ");
    scanf("%f", pb);
}

void tinh_toan(float *pa, float *pb, float *tong, float *hieu, float *tich, float *thuong) {
    *tong = *pa + *pb;
    *hieu = *pa - *pb;
    *tich = (*pa) * (*pb);
    *thuong = (*pa) / (*pb);
}

void xuat(float *pa, float *pb, float *tong, float *hieu, float *tich, float *thuong) {
    printf("Gia tri a = %f, dia chi cua a = %p\n", *pa, (void*)pa);
    printf("Gia tri b = %f, dia chi cua b = %p\n", *pb, (void*)pb);
    printf("Tong a + b = %f, dia chi cua tong = %p\n", *tong, (void*)tong);
    printf("Hieu a - b = %f, dia chi cua hieu = %p\n", *hieu, (void*)hieu);
    printf("Tich a * b = %f, dia chi cua tich = %p\n", *tich, (void*)tich);
    printf("Thuong a / b = %f, dia chi cua thuong = %p\n", *thuong, (void*)thuong);
}

int main() {
    float a, b;
    float tong, hieu, tich, thuong;
    
    float *pa = &a;
    float *pb = &b;
    float *ptong = &tong;
    float *phieu = &hieu;
    float *ptich = &tich;
    float *pthuong = &thuong;
    
    nhap(pa, pb);
    tinh_toan(pa, pb, ptong, phieu, ptich, pthuong);
    xuat(pa, pb, ptong, phieu, ptich, pthuong);
    
    return 0;
}

