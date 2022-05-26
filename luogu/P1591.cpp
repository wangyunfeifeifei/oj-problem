#include <cstdio>

int fac[5000];
int len;
int ans[1001][10] = {0};

void mul(int n) {
    for (int i = 0; i < len; i++) {
        fac[i] *= n;
    }
    for (int i = 0; i < len; i++) {
        if (fac[i] > 9) {
            if (i == len - 1) len++;
            fac[i + 1] += fac[i] / 10;
            fac[i] = fac[i] % 10;
        }
    }
}

// 调试用
void display() {
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", fac[i]);
    }
    printf("\n");
}

int main() {
    fac[0] = 1;
    len = 1;
    ans[0][1] = 1;
    for (int i = 1; i <= 1000; i++) {
        mul(i);
        for (int j = 0; j < len; j++) {
            ans[i][fac[j]]++;
        }
    }
    int n;
    scanf("%d", &n);
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", ans[a][b]);
    }

    return 0;
}
