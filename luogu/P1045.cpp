#include <cmath>
#include <cstdio>
#include <cstring>

int p;
int fac[1005], res[1005], mid[1005];

void mul1() {
    memset(mid, 0, sizeof(mid));
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            mid[i + j] += res[i] * fac[j];
        }
    }
    for (int i = 0; i <= 500; i++) {
        mid[i + 1] += mid[i] / 10;
        mid[i] %= 10;
    }
    memcpy(res, mid, sizeof(res));
}

void mul2() {
    memset(mid, 0, sizeof(mid));
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            mid[i + j] += fac[i] * fac[j];
        }
    }
    for (int i = 0; i <= 500; i++) {
        mid[i + 1] += mid[i] / 10;
        mid[i] %= 10;
    }
    memcpy(fac, mid, sizeof(res));
}

int main() {
    scanf("%d", &p);
    printf("%d\n", (int) (log10(2) * p + 1));
    res[0] = 1;
    fac[0] = 2;
    while (p != 0) {
        if (p % 2 == 1) mul1();
        p /= 2;
        mul2();
    }
    res[0] -= 1;
    for (int i = 500 - 1; i >= 0; i--) {
        if (i != 499 && i % 50 == 49)printf("\n");
        printf("%d", res[i]);
    }
    return 0;
}
