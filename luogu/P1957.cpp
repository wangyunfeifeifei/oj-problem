#include <cstdio>
#include <cstring>

int main() {
    int n;
    char str[15];
    char op;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(str, 15, stdin);
        if (str[0] == 'a' || str[0] == 'b' || str[0] == 'c') {
            op = str[0];
            str[0] = ' ';
        }
        int a, b;
        char out[50];
        sscanf(str, "%d%d", &a, &b);
        switch (op) {
            case 'a':
                sprintf(out, "%d+%d=%d", a, b, a + b);
                break;
            case 'b':
                sprintf(out, "%d-%d=%d", a, b, a - b);
                break;
            case 'c':
                sprintf(out, "%d*%d=%d", a, b, a * b);
                break;
        }
        printf("%s\n%u\n", out, strlen(out));
    }
    return 0;
}
