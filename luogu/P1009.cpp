#include <cstdio>

int a[1000], b[1000];

int main() {
    int n;
    scanf("%d", &n);
    a[0] = b[0] = 1;
    int lena = 1, lenb = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < lena; j++) {
            a[j] *= i;
        }
        for (int j = 0; j < lena; j++) {
            if (a[j] > 9) {
                if (j == lena - 1) lena++;
                a[j + 1] += a[j] / 10;
                a[j] %= 10;
            }
        }

        for (int j = 0; j < lena; j++) {
            b[j] += a[j];
            if (j + 1 > lenb) lenb = j + 1;
        }
        for (int j = 0; j < lenb; j++) {
            if (b[j] > 9) {
                if (j == lenb - 1) lenb++;
                b[j + 1] += b[j] / 10;
                b[j] %= 10;
            }
        }
    }
    for (int i = lenb - 1; i >= 0; i--) {
        printf("%d", b[i]);
    }
    printf("\n");
    return 0;
}
