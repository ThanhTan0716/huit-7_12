#include <stdio.h>
#include <stdlib.h>

void chiaMang(int *a, int n_a, int *b, int n_b) {
    if (n_a != n_b) {
        printf("Hai mang phai co cung so phan tu.\n");
        return;
    }

    for (int i = 0; i < n_a; i++) {
        if (b[i] == 0) {
            printf("Phan tu thu %d cua mang b là 0. Không thi chia cho 0.\n", i);
        } else {
            printf("a[%d] / b[%d] = %.2f\n", i, i, (float)a[i] / b[i]);
        }
    }
}

int main() {
    int n;

    printf("Nhap so phan tu cua hai mang: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));

    if (a == NULL || b == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang a:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Nhap cac phan tu cua mang b:\n");
    for (int i = 0; i < n; i++) {
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }

    chiaMang(a, n, b, n);

    free(a);
    free(b);

    return 0;
}

