#include <cstdio>

char num[10][5][4] = {
        {
                "XXX",
                "X.X",
                "X.X",
                "X.X",
                "XXX"
        },
        {
                "..X",
                "..X",
                "..X",
                "..X",
                "..X",
        },
        {
                "XXX",
                "..X",
                "XXX",
                "X..",
                "XXX"
        },
        {
                "XXX",
                "..X",
                "XXX",
                "..X",
                "XXX"
        },
        {
                "X.X",
                "X.X",
                "XXX",
                "..X",
                "..X",
        },
        {
                "XXX",
                "X..",
                "XXX",
                "..X",
                "XXX"
        },
        {
                "XXX",
                "X..",
                "XXX",
                "X.X",
                "XXX"
        },
        {
                "XXX",
                "..X",
                "..X",
                "..X",
                "..X",
        },
        {
                "XXX",
                "X.X",
                "XXX",
                "X.X",
                "XXX"
        },
        {
                "XXX",
                "X.X",
                "XXX",
                "..X",
                "XXX"
        }
};

int main() {
    int n;
    char str[101];
    scanf("%d%s", &n, str);
    char out[5][405];
    for (int i = 0; i < n; i++) {
        char ch = str[i];
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 5; y++) {
                out[y][4 * i + x] = num[ch - '0'][y][x];
            }
        }

        if (i != n - 1) {
            for (int j = 0; j < 5; j++) {
                out[j][4 * i + 3] = '.';
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4 * n - 1; j++) {
            printf("%c", out[i][j]);
        }
        printf("\n");
    }
    return 0;
}
