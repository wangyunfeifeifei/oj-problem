#include <cstdio>

int main() {
    int cube[10][10] = {0};
    int n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    scanf("%d", &n);
    int k = 2;
    int x = 0, y = 0;
    for (int i = 0; i < n*n; i++) {
        cube[y][x] = i + 1;
        if (k == 2 && (x == n - 1 || cube[y + dy[k]][x + dx[k]] != 0)) {
            k = 0;
        } else if (k == 0 && (y == n - 1 || cube[y + dy[k]][x + dx[k]] != 0)) {
            k = 3;
        } else if (k == 3 && (x == 0 || cube[y + dy[k]][x + dx[k]] != 0)) {
            k = 1;
        } else if (k == 1 && (y == 0 || cube[y + dy[k]][x + dx[k]] != 0)) {
            k = 2;
        }
        x += dx[k];
        y += dy[k];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", cube[i][j]);
        }
        printf("\n");
    }
    return 0;
}
