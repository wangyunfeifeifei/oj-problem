#include <cstdio>
#include <cstring>

int main() {
    int q; // q次操作
    char str[10001];
    int op; // 操作类型
    char s[101]; // 操作的字符串
    int a, b;
    int len;
    int i, j;
    int nlen, slen;
    scanf("%d%s", &q, str);
    while (q--) {
        scanf("%d", &op);
        switch (op) {
            case 1:
                scanf("%s", s);
                strcat(str, s);
                printf("%s\n", str);
                break;
            case 2:
                scanf("%d%d", &a, &b);
                len = strlen(str);
                for (i = a; i < a + b && i < len; i++)
                    str[i - a] = str[i];
                str[i - a] = '\0';
                printf("%s\n", str);
                break;
            case 3:
                scanf("%d%s", &a, s);
                len = strlen(str);
                slen = strlen(s);
                nlen = slen + len;
                for (i = nlen, j = len; j >= a; i--, j--)
                    str[i] = str[j];
                for (i = 0; i < slen; i++)
                    str[i + a] = s[i];
                printf("%s\n", str);
                break;
            case 4:
                scanf("%s", s);
                char *pos = strstr(str, s);
                if (pos == NULL) {
                    printf("-1\n");
                } else {
                    printf("%d\n", pos - str);
                }
                break;
        }
    }

    return 0;
}
