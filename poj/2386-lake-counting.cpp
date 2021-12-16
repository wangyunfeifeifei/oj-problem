//
// Created by wang on 2021/12/7.
//

#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX_N 101
#define MAX_M 101

int N, M;
char field[MAX_N][MAX_M];

void dfs(int i, int j) {
    field[i][j] = '.';
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = i + dx;
            int ny = j + dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') dfs(nx, ny);
        }
    }
}

void solve() {
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
        }
    }
    printf("%d\n", res);
}

int main() {
//    freopen("../input.txt", "r", stdin);
    scanf("%d%d\n", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &field[i][j]);
        }
        getchar();
    }
    solve();
    return 0;
}
