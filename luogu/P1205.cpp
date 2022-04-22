#include <iostream>

int n;
char a[11][11], b[11][11], c[11][11], d[11][11]; // 原矩阵，中间矩阵，目标矩阵, 多的中间矩阵

bool test() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] != c[i][j]) return false;
        }
    }
    return true;
}

bool case1() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[j][n - i - 1] = a[i][j];
        }
    }
    return test();
}

bool case2() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[n - 1 - i][n - 1 - j] = a[i][j];
        }
    }
    return test();
}

bool case3() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[n - j - 1][i] = a[i][j];
        }
    }
    return test();
}

bool case4() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][n - 1 - j] = a[i][j];
        }
    }
    return test();
}

bool case5() {
    case4();
    // 旋转90
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[j][n - i - 1] = b[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = d[i][j];
    if (test()) return true;
    // 旋转180
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[j][n - i - 1] = b[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = d[i][j];
    if (test()) return true;
    // 旋转270
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[j][n - i - 1] = b[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = d[i][j];
    return test();
}

bool case6() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = a[i][j];
    return test();
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", c[i]);
    }
    if (case1()) {
        printf("%d\n", 1);
    } else if (case2()) {
        printf("%d\n", 2);
    } else if (case3()) {
        printf("%d\n", 3);
    } else if (case4()) {
        printf("%d\n", 4);
    } else if (case5()) {
        printf("%d\n", 5);
    } else if (case6()) {
        printf("%d\n", 6);
    } else {
        printf("%d\n", 7);
    }

    return 0;
}
