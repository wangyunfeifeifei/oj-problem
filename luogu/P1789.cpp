#include <cstdio>

int torch[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
};

int stone[5][5] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
};

int main() {
    int n, m, k;
    int cube[101][101] = {0};
    scanf("%d%d%d", &n, &m, &k);

    int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        for (int is = -2; is <= 2; is++) {
            for (int js = -2; js <= 2; js++) {
                int nx = x + is;
                int ny = y + js;
                if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1) cube[nx][ny] += torch[is + 2][js + 2];
            }
        }

    }
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        for (int is = -2; is <= 2; is++) {
            for (int js = -2; js <= 2; js++) {
                int nx = x + is;
                int ny = y + js;
                if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1) cube[nx][ny] += stone[is + 2][js + 2];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cube[i][j] == 0)ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
