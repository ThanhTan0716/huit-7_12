#include <stdio.h>
#include <ctype.h>
#include <string.h>


void xuatKyTu(char *st) {
    while (*st != '\0') {
        printf("%c ", *st);
        st++;
    }
    printf("\n");
}


void chuyenChuHoa(char *st) {
    while (*st != '\0') {
        if (*st >= 'a' && *st <= 'z') {
            *st = *st - 32;
        }
        st++;
    }
}


void chuyenKyTuDauChuHoa(char *st) {
    int cap = 1; 
    while (*st != '\0') {
        if (*st == ' ') {
            cap = 1; 
        } else if (cap && *st >= 'a' && *st <= 'z') {
            *st = *st - 32; 
            cap = 0; 
        }
        st++;
    }
}

int main() {
    char st[100];

    printf("Nhap vao chuoi: ");
    fgets(st, sizeof(st), stdin);

    size_t len = strlen(st);
    if (len > 0 && st[len - 1] == '\n') {
        st[len - 1] = '\0';
    }

    printf("Cac ky tu cua chuoi la: ");
    xuatKyTu(st);

    chuyenChuHoa(st);
    printf("Chuoi sau khi chuyen thanh chu hoa: %s\n", st);

    printf("Nhap lai chuoi: ");
    fgets(st, sizeof(st), stdin);
    if (len > 0 && st[len - 1] == '\n') {
        st[len - 1] = '\0';
    }

    chuyenKyTuDauChuHoa(st);
    printf("Chuoi sau khi chuyen ky tu dau moi tu thanh chu hoa: %s\n", st);

    return 0;
}

