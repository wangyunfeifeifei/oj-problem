#include <cstdio>

char map[10][11];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int df = 0, dc = 0; // 农民和牛开始的方向
int fi, fj;
int ci, cj;
int ans = 0;

int main() {
    for (int i = 0; i < 10; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 'F') {
                fi = i;
                fj = j;
            } else if (map[i][j] == 'C') {
                ci = i;
                cj = j;
            }
        }
    }
    while (!(ci == fi && cj == fj) && ans <= 160000) {
        int ni = fi + di[df];
        int nj = fj + dj[df];
        if (ni < 0 || ni == 10 || nj < 0 || nj == 10 || map[ni][nj] == '*') {
            df = (df + 1) % 4;
        } else {
            fi = ni;
            fj = nj;
        }

        ni = ci + di[dc];
        nj = cj + dj[dc];
        if (ni < 0 || ni == 10 || nj < 0 || nj == 10 || map[ni][nj] == '*') {
            dc = (dc + 1) % 4;
        } else {
            ci = ni;
            cj = nj;
        }

        ans++;

    }
    if (ans > 160000) printf("0\n");
    else printf("%d\n", ans);

    return 0;
}
