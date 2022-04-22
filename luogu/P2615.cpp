#include <cstdio>

int main() {
    int n;
    int cub[40][40] = {0};
    scanf("%d", &n);
    int y = 0, x = n / 2;
    for (int k = 1; k <= n * n; k++) {
        cub[y][x] = k;
        if (y == 0 && x != n - 1) {
            y = n - 1;
            x++;
        } else if (x == n - 1 && y != 0) {
            x = 0;
            y--;
        } else if (y == 0 && x == n - 1) {
            y++;
        } else if (y != 0 && x != n - 1) {
            if (cub[y - 1][x + 1] == 0) {
                y--;
                x++;
            } else {
                y++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", cub[i][j]);
        }
        printf("\n");
    }

    return 0;
}
