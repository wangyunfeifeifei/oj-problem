#include <cstdio>

int main() {
    int cube[21][21][21];
    int w, x, h;
    int q;
    int x1, y1, z1;
    int x2, y2, z2;
    scanf("%d%d%d%d", &w, &x, &h, &q);
    for (int i = 1; i <= w; i++)
        for (int j = 1; j <= x; j++)
            for (int k = 1; k <= h; k++)
                cube[i][j][k] = 1;
    while (q--) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &z1,
              &x2, &y2, &z2);
        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                for (int k = z1; k <= z2; k++)
                    cube[i][j][k] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= w; i++)
        for (int j = 1; j <= x; j++)
            for (int k = 1; k <= h; k++)
                ans += cube[i][j][k];
    printf("%d\n", ans);
    return 0;
}
