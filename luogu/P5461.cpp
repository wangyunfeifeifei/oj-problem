#include <cstdio>

int matrix[1025][1025], n, pow2n = 1;

void check(int x, int y) {
    int i = x, j = y;
    for (int k = pow2n; k >= 1; k /= 2) {
        int t = k / 2;
        if (i <= t && j <= t) {
            matrix[x][y] = 0;
            return;
        }
        if (i > t) i -= t;
        if (j > t) j -= t;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) pow2n *= 2;
    for (int i = 0; i <= pow2n; i++) {
        for (int j = 0; j <= pow2n; j++) {
            matrix[i][j] = 1;
        }
    }
    for (int i = 1; i <= pow2n; i++) {
        for (int j = 1; j <= pow2n; j++) {
            check(i, j);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
