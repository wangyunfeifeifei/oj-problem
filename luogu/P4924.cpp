#include <cstdio>

int matrix[505][505], middle[505][505];
int n, m;

void clockwise(int x1, int x2, int y1, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            middle[j - y1 + x1][y2 - i + x1] = matrix[i][j];
        }
    }
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            matrix[i][j] = middle[i][j];
        }
    }
}

void anti_clockwise(int x1, int x2, int y1, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            middle[x2 - j + y1][i - x1 + y1] = matrix[i][j];
        }
    }
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            matrix[i][j] = middle[i][j];
        }
    }
}

void op(int x, int y, int r, int z) {
    if (z == 0) clockwise(x - r, x + r, y - r, y + r);
    else anti_clockwise(x - r, x + r, y - r, y + r);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = (i - 1) * n + j;
        }
    }
    int x, y, r, z;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &x, &y, &r, &z);
        op(x, y, r, z);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1)printf("%d", matrix[i][j]);
            else printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
