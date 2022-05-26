#include <cstdio>

int dis[101][101] = {0};

int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char ch;
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            scanf("%c", &ch);
            for (int k = 0; ch == '*' && k < 8; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && dis[ni][nj] != -1) {
                    dis[ni][nj]++;
                }
            }
            if (ch == '*') dis[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dis[i][j] == -1)printf("*");
            else printf("%d", dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}
